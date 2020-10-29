#include <iostream>
#include <list>
#include <algorithm>
#include <string.h>
#include "grafo.h"

Nodo::Nodo(int identificador){
	id = identificador;
}

int Nodo::getId() const{
	return id;
}

void Nodo::agregarAdyacencia(Nodo* adyacente){
	lista_ady.push_back(adyacente);
}

bool Nodo::esAdy(int id){
	for(Nodo* ady : lista_ady){
		if (ady->getId() == id){
			return true;
		}
	}
	return false;
}

int Nodo::cantAdy() const{
	return (lista_ady.size());
}

std::list<Nodo*> Nodo::getAdy(){
	return lista_ady;
}

Nodo::~Nodo(){
}

Grafo::Grafo(){
	cant_nodos = 0;
}

void Grafo::addNodo(int id){
	if (!hayNodo(id)){
		Nodo* nuevo_nodo = new Nodo(id);
		lista_nodos.push_back(nuevo_nodo);
		cant_nodos++;
	}
}

bool Grafo::hayNodo(int id) const{
	for(Nodo* nodo : lista_nodos){
		if (nodo->getId() == id){
			return true;
		}
	}
	return false;
}

Nodo* Grafo::getNodo(int id){
	for(Nodo* nodo : lista_nodos){
		if (nodo->getId() == id){
			return nodo;
		}
	}
	return NULL;
}

void Grafo::addAdy(int id1, int id2){
	if (hayNodo(id1) && hayNodo(id2)){
		Nodo* nodo_base = getNodo(id1);
		Nodo* nodo_ady = getNodo(id2);
		nodo_base->agregarAdyacencia(nodo_ady);
	}
}

bool Grafo::yaVisite(std::list<int>* vistos, Nodo* nodo) const{
	std::list<int>::iterator iterVis;
	iterVis = std::find(vistos->begin(), vistos->end(), nodo->getId());
	return (iterVis != vistos->end());
}

bool Grafo::hasCiclo(std::list<int> ids, Nodo* ady, std::list<int>* vistos){
	for (int id : ids){
		if ((ady)->esAdy(id)){
			return true;	
		}
	}
	if (!yaVisite(vistos, ady)){
		vistos->push_back(ady->getId());

		if (ady->cantAdy() > 0){
			std::list<Nodo*> list_ady = ady->getAdy();
			ids.push_back(ady->getId());

			for (Nodo* nodo : list_ady){
				if (hasCiclo(ids, nodo, vistos)){
					return true;
				}
			}
		}
	}
	return false;
}

int Grafo::dfsErrores(){
	int salida = FLAG_OK;
	std::list<int> lista_ids;
	std::list<int>* visitados = new std::list<int>();
	Nodo* nodo_base = lista_nodos.front();
	std::list<Nodo*> adyacentes = nodo_base->getAdy();

	lista_ids.push_back(nodo_base->getId());
	visitados->push_back(nodo_base->getId());

	for(Nodo* nodo_ady : adyacentes){
		if (hasCiclo(lista_ids, nodo_ady, visitados)){
			salida = FLAG_CICLO;
		}
	}
	bool nodo_solo = visitados->size() != cant_nodos;
	if (salida != 1 && nodo_solo){
		salida = FLAG_SOLITARIO;
	}
	delete visitados;
	return salida;
}

Grafo::~Grafo(){
	for(Nodo* nodo : lista_nodos){
		delete nodo;
	}
}

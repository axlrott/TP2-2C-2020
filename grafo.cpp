#include <iostream>
#include <list>
#include <algorithm>
#include <string.h>
#include <functional>
#include "grafo.h"

Nodo::Nodo(int identificador){
	id = identificador;
}

int Nodo::getId() const{
	return id;
}

void Nodo::agregarAdyacencia(Nodo &nodo){
	lista_ady.push_back(nodo);
}

bool Nodo::esAdy(int id_ady) const{
	return std::any_of(lista_ady.begin(), lista_ady.end(),
		[&](const Nodo &nodo) {
			return nodo.getId() == id_ady;
		});
}

int Nodo::cantAdy() const{
	return (lista_ady.size());
}

std::list<std::reference_wrapper<Nodo>>& Nodo::getAdy(){
	return lista_ady;
}

void Grafo::addNodo(int id){
	if (!hayNodo(id)){
		lista_nodos.emplace_back(id);
		cant_nodos++;
	}
}

bool Grafo::hayNodo(int id) const{
	return std::any_of(lista_nodos.begin(), lista_nodos.end(),
		[&](const Nodo &nodo) {
			return nodo.getId() == id;
		});
}

/*Esta funcion se utiliza ya sabiendo que los
dos nodos buscados estan en la lista*/
void Grafo::BuscoYAgregoAdy(int id1, int id2){
	auto ptr_nodo1 = lista_nodos.begin();
	auto ptr_nodo2 = lista_nodos.begin();
	while (true) {
		if (ptr_nodo1->getId() != id1){
			++ptr_nodo1;
		} else if (ptr_nodo2->getId() != id2){
			++ptr_nodo2;
		} else {
			break;
		}
	}
	ptr_nodo1->agregarAdyacencia(*ptr_nodo2);
}

void Grafo::addAdy(int id1, int id2){
	if (hayNodo(id1) && hayNodo(id2)){
		BuscoYAgregoAdy(id1, id2);
	}
}

bool Grafo::yaVisite(std::list<int> vistos, const Nodo &nodo) const{
	auto iterVis = std::find(vistos.begin(), vistos.end(), nodo.getId());
	return (iterVis != vistos.end());
}

bool Grafo::esAdyList(const Nodo &nodo, std::list<int> &lista_ids){
	return std::any_of(lista_ids.begin(), lista_ids.end(),
		[&](const int &id) {
			return nodo.esAdy(id);
		});
}

bool Grafo::hasCiclo(std::list<int> ids, Nodo &ady, std::list<int> &vistos){
	if (esAdyList(ady, ids)){
		return true;
	}
	if (!yaVisite(vistos, ady)){
		vistos.push_back(ady.getId());

		if (ady.cantAdy() > 0){
			ids.push_back(ady.getId());

			for (Nodo &new_ady : ady.getAdy()){;
				if (hasCiclo(ids, new_ady, vistos)){
					return true;
				}
			}
		}
	}
	return false;
}

int Grafo::busquedaDFS(){
	int salida = FLAG_OK;
	std::list<int> lista_ids;
	std::list<int> visitados;
	int id_nodo_base = lista_nodos.front().getId();

	lista_ids.push_back(id_nodo_base);
	visitados.push_back(id_nodo_base);
	
	for (Nodo &ady : lista_nodos.front().getAdy()){
		if (hasCiclo(lista_ids, ady, visitados)){
			salida = FLAG_CICLO;
		}
	}
	bool nodo_solo = visitados.size() != cant_nodos;
	if (salida != FLAG_CICLO && nodo_solo){
		salida = FLAG_SINUSO;
	}
	return salida;
}

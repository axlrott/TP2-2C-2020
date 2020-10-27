#include <iostream>
#include <string>
#include <list>
#include "diccionario.h"

Diccionario::Diccionario(){
}

void Diccionario::agregarClave(std::string clave, int valor){
	claves.push_back(clave);
	valores.push_back(valor);
}

bool Diccionario::hayClave(std::string clave){
	for (std::string clave_almacenada : claves){
		if (clave_almacenada.compare(clave) == 0){
			return true;
		}
	}
	return false;
}

int Diccionario::getValor(std::string clave){
	std::list<int>::iterator iter = valores.begin();

	for (std::string clave_almacenada : claves){
		if (clave_almacenada.compare(clave) == 0){
			int valor = *iter;
			return valor;
		}
		iter++;
	}
	return -1;
}

void Diccionario::cambiarClave(std::string clave, int valor){
	std::list<int>::iterator iter = valores.begin();

	for (std::string clave_almacenada : claves){
		if (clave_almacenada.compare(clave) == 0){
			*iter = valor;
			return;
		}
		iter++;
	}
	agregarClave(clave, valor);
}

std::list<int> Diccionario::getAllValores(std::string clave){
	std::list<int> lista_valores;
	std::list<int>::iterator iter = valores.begin();

	for (std::string clave_almacenada : claves){
		if (clave_almacenada.compare(clave) == 0){
			int valor = *iter;
			lista_valores.push_back(valor);
		}
		iter++;
	}
	return lista_valores;
}

Diccionario::~Diccionario(){
}
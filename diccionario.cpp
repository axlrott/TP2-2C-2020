#include <iostream>
#include <string>
#include <vector>
#include "diccionario.h"

Diccionario::Diccionario(){
}

void Diccionario::agregarClave(std::string clave, int valor){
	claves.push_back(clave);
	valores.push_back(valor);
}

bool Diccionario::hayClave(std::string clave) const{
	for (std::string clave_almacenada : claves){
		if (clave_almacenada.compare(clave) == 0){
			return true;
		}
	}
	return false;
}

int Diccionario::getValor(std::string clave) const{
	int pos = 0;

	for (std::string clave_almacenada : claves){
		if (clave_almacenada.compare(clave) == 0){
			int valor = valores.at(pos);
			return valor;
		}
		pos++;
	}
	return -1;
}

void Diccionario::cambiarClave(std::string clave, int valor){
	std::vector<int>::iterator iter = valores.begin();

	for (std::string clave_almacenada : claves){
		if (clave_almacenada.compare(clave) == 0){
			*iter = valor;
			return;
		}
		iter++;
	}
	agregarClave(clave, valor);
}

std::vector<int> Diccionario::getAllValores(std::string clave) const{
	std::vector<int> lista_valores;
	int pos = 0;

	for (std::string clave_almacenada : claves){
		if (clave_almacenada.compare(clave) == 0){
			int valor = valores.at(pos);
			lista_valores.push_back(valor);
		}
		pos++;
	}
	return lista_valores;
}

Diccionario::~Diccionario(){
}

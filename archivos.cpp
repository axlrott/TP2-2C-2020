#include <iostream>
#include <string>
#include <list>
#include <thread>
#include "archivos.h"

Archivos::Archivos(){
}

void Archivos::agregarArchivo(std::string archivo){
	lista_archivos.push_back(archivo);
}

bool Archivos::hayArchivos(){
	return (lista_archivos.size() > 0);
}

std::string Archivos::getNuevoArchivo(){
	if (hayArchivos()){
		std::string archivo = lista_archivos.front();
		lista_archivos.pop_front();
		return archivo;
	}
	return "";
}

Archivos::~Archivos(){
}

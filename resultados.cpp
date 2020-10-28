#include <iostream>
#include <string>
#include <list>
#include <thread>
#include <algorithm>
#include "diccionario.h"
#include "resultados.h"

Resultados::Resultados(){
	msj_ok = " GOOD";
	msj_ciclo = " FAIL: cycle detected";
	msj_sin_uso = " FAIL: unused instructions detected";
}

void Resultados::agregarEnOrden(std::string archivo_nuevo){
	if (lista_archivos.size() > 0){
		std::list<std::string>::iterator it;
		for (it = lista_archivos.begin(); it != lista_archivos.end(); it++){
			std::string archivo = *it;
			if (archivo > archivo_nuevo){
				lista_archivos.insert(it, archivo_nuevo);
				return;
			}
		}
	}
	lista_archivos.push_back(archivo_nuevo);
}

void Resultados::agregarArchivo(std::string archv, bool ciclos, bool sin_uso){
	agregarEnOrden(archv);
	if(ciclos){
		dic_archivos.agregarClave(archv, CICLO);
	}else if (sin_uso){
		dic_archivos.agregarClave(archv, SINUSO);
	}else{
		dic_archivos.agregarClave(archv, OK);
	}
}

void Resultados::mostrarResultados(){
	for (std::string archivo : lista_archivos){
		int resultado = dic_archivos.getValor(archivo);
		if (resultado == OK){
			std::cout << archivo << msj_ok << std::endl;
		} else if (resultado == CICLO){
			std::cout << archivo << msj_ciclo << std::endl;
		} else {
			std::cout << archivo << msj_sin_uso << std::endl;
		}
	}
}

Resultados::~Resultados(){
}

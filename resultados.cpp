#include <iostream>
#include <string>
#include <list>
#include "diccionario.h"
#include "resultados.h"

Resultados::Resultados(){
	msj_ok = " GOOD";
	msj_ciclo = " FAIL: cycle detected";
	msj_sin_uso = " FAIL: unused instructions detected";
}

void Resultados::agregarArchivo(std::string archivo){
	lista_archivos.push_back(archivo);
	dic_archivos.agregarClave(archivo, OK);
}

void Resultados::tieneCiclos(std::string archivo){
	dic_archivos.cambiarClave(archivo, CICLO);
}

void Resultados::tieneInstrSinUso(std::string archivo){
	dic_archivos.cambiarClave(archivo, SINUSO);
}

void Resultados::mostrarResultados(){
	lista_archivos.sort();

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

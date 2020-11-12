#include <iostream>
#include <string>
#include <list>
#include <thread>
#include <algorithm>
#include <map>
#include "resultados.h"
#define OK " GOOD"
#define CICLO " FAIL: cycle detected"
#define SIN_USO " FAIL: unused instructions detected"

void Resultados::agregarArchivo(std::string &archv, bool ciclos, bool sin_uso){
	set_archivos.insert(archv);
	if(ciclos){
		dic_archivos[archv] = CICLO;
	}else if (sin_uso){
		dic_archivos[archv] = SIN_USO;
	}else{
		dic_archivos[archv] = OK;
	}
}

void Resultados::mostrarResultados() const{
	for (const std::string &archv : set_archivos){
		std::string resultado = dic_archivos.at(archv);
		std::cout << archv << resultado << std::endl;
	}
}

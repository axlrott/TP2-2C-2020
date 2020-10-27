#include <iostream>
#include <string>
#include <list>
#include "procesador.h"
#include "archivos.h"
#include "resultados.h"
#include "grafo_ebpf.h"

Procesador::Procesador(Archivos* archivos, Resultados* resultados){
	ptr_archivos = archivos;
	ptr_resultados = resultados;
}

void Procesador::procesar(){
	while(ptr_archivos->hayArchivos()){
		std::string archivo = ptr_archivos->getNuevoArchivo();
		
		GrafoEbpf grafo = GrafoEbpf(archivo);
		ptr_resultados->agregarArchivo(archivo);

		if (grafo.hayCiclos()){
			ptr_resultados->tieneCiclos(archivo);
		} else if (grafo.hayInstrSinUso()){
			ptr_resultados->tieneInstrSinUso(archivo);
		}
	}
}

Procesador::~Procesador(){
}

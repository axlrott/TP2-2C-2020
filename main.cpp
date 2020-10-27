#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <bits/stdc++.h> 
#include <thread>
#include "grafo.h"
#include "lector_ebpf.h"
#include "grafo_ebpf.h"
#include "archivos.h"
#include "resultados.h"
#include "procesador.h"


int main(int argc, char const *argv[]){
	Archivos archivos;
	Resultados res;
	int cant_archivos = argc-1;

	for (int i=0; i < cant_archivos; i++){
		archivos.agregarArchivo(argv[i+1]);
	}

	Procesador procesador = Procesador(&archivos, &res);
	procesador.procesar();

	res.mostrarResultados();
	return 0;
}
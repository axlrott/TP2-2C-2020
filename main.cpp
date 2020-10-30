#include <iostream>
#include <bits/stdc++.h> 
#include "archivos.h"
#include "resultados.h"
#include "thread_tda.h"
#include "procesador.h"

int main(int argc, char const *argv[]){
	Archivos archivos;
	Resultados res;
	int cant_threads = atoi(argv[1]);
	int cant_archivos = argc-2;
	std::vector<Thread*> threads;

	for (int i=0; i < cant_archivos; ++i){
		archivos.agregarArchivo(argv[i+2]);
	}
	MonitorArchv monitor_archivos(&archivos, &res);

	for (int i = 0; i < cant_threads; ++i){
		Thread* thread = new Procesar(monitor_archivos);
		thread->start();
		threads.push_back(thread);
	}
	for (int i = 0; i < cant_threads; ++i){
		threads[i]->join();
		delete threads[i];
	}
	res.mostrarResultados();
	return 0;
}

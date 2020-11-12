#include <iostream>
#include <bits/stdc++.h> 
#include "thread_tda.h"
#include "procesador.h"
#include "monitor_res.h"
#include "monitor_archv.h"

int main(int argc, char const *argv[]){
	MonitorArchv monitor_archv;
	MonitorRes monitor_res;
	int cant_threads = std::stoi(argv[1]);
	int cant_archivos = argc-2;
	std::vector<Thread*> threads;

	for (int i=0; i < cant_archivos; ++i){
		monitor_archv.agregarArchivo(argv[i+2]);
	}

	for (int i = 0; i < cant_threads; ++i){
		Thread* thread = new Procesar(monitor_archv, monitor_res);
		thread->start();
		threads.push_back(thread);
	}
	for (int i = 0; i < cant_threads; ++i){
		threads[i]->join();
		delete threads[i];
	}
	monitor_res.mostrarResultados();
	return 0;
}

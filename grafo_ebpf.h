#ifndef GRAFO_EBPF_T
#define GRAFO_EBPF_T

#include <iostream>
#include <string>
#include <fstream>
#include "grafo.h"
#include "lector_ebpf.h"
#include "diccionario.h"

/*Clase que contiene un grafo de un proceso en BPF
donde cada nodo representa una instruccion y sus adyacencias
dependen de los saltos y los retornos que se hayan dado*/
class GrafoEbpf{
private:
	int id_nodo;
	bool pto_muerto;
	std::string nombre_archivo;
	Diccionario dicTags;
	Diccionario dicTagsEnEspera;
	Grafo* grafoEbpf;
	void procesarLineas(std::string linea);
	void crearGrafo();
public:
	GrafoEbpf(std::string archivo);
	bool hayCiclos();
	bool hayInstrSinUso();
	std::string getNombreArchivo();
	~GrafoEbpf();
};
#endif

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
	void agregarAdyacencias(std::string tag);
	void procesarTag(std::string tag);
	void revisarPtoMuerto(bool hay_return, bool hay_jmpInc);
	void procesarLineas(std::string linea);
	void crearGrafo();
public:
	explicit GrafoEbpf(std::string archivo);
	bool hayCiclos() const;
	bool hayInstrSinUso() const;
	std::string getNombreArchivo() const;
	~GrafoEbpf();
};
#endif

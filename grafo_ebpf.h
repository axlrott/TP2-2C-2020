#ifndef GRAFO_EBPF_T
#define GRAFO_EBPF_T

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
#include "grafo.h"
#include "lector_ebpf.h"

/*Clase que contiene un grafo de un proceso en BPF
donde cada nodo representa una instruccion y sus adyacencias
dependen de los saltos y los retornos que se hayan dado*/
class GrafoEbpf{
private:
	int id_nodo;
	bool pto_muerto;
	std::string nombre_archivo;
	std::map<std::string, int> dicTags;
	std::map<std::string, std::list<int>> dicTagsEnEspera;
	Grafo grafoEbpf;
	void agregarAdyacencias(std::string tag);
	void procesarTag(std::string tag);
	void revisarPtoMuerto(bool hay_return, bool hay_jmpInc);
	void procesarLineas(std::string linea);
	void crearGrafo();
public:
	explicit GrafoEbpf(const std::string &archivo);
	bool hayCiclos();
	bool hayInstrSinUso();
	~GrafoEbpf() {}
};

#endif

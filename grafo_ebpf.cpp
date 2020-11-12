#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <list>
#include <functional>
#include "grafo.h"
#include "lector_ebpf.h"
#include "grafo_ebpf.h"

void GrafoEbpf::procesarTag(std::string tag){
	dicTags[tag] = id_nodo;
	for (int id_origen : dicTagsEnEspera[tag]){
		grafoEbpf.addAdy(id_origen, id_nodo);
	}
}

void GrafoEbpf::agregarAdyacencias(std::string tag){
	if(tag.size() > 0){
		if (dicTags.count(tag) > 0){
			int ady = dicTags[tag];
			grafoEbpf.addAdy(id_nodo, ady);
		}else{
			dicTagsEnEspera[tag].push_back(id_nodo);
		}
	}
}

void GrafoEbpf::revisarPtoMuerto(bool hay_return, bool hay_jmpInc){
	if (pto_muerto){
		pto_muerto = false;
	}else{
		grafoEbpf.addAdy(id_nodo-1, id_nodo);
	}
	if (hay_return || hay_jmpInc){
		pto_muerto = true;
	}
}

void GrafoEbpf::procesarLineas(std::string linea){
	LectorEbpf lector(linea);
	grafoEbpf.addNodo(id_nodo);

	if(lector.hayTag()){
		procesarTag(lector.getTag());
	}
	if (lector.hayJmp()){
		agregarAdyacencias(lector.getArg1());
		agregarAdyacencias(lector.getArg2());
	}
	revisarPtoMuerto(lector.hayReturn(), lector.hayJmpInc());
	id_nodo++;
}

void GrafoEbpf::crearGrafo(){
	std::fstream archv(nombre_archivo);
	std::string linea_ebpf;

	while (std::getline(archv, linea_ebpf)){
		if (linea_ebpf.size() > 0){
			procesarLineas(linea_ebpf);
		}
	}
}

GrafoEbpf::GrafoEbpf(const std::string &archivo): nombre_archivo(archivo){
	id_nodo = 0;
	pto_muerto = false;
	crearGrafo();
}

bool GrafoEbpf::hayCiclos(){
	int flag = grafoEbpf.busquedaDFS();
	return (flag == FLAG_CICLO);
}

bool GrafoEbpf::hayInstrSinUso(){
	int flag = grafoEbpf.busquedaDFS();
	return (flag == FLAG_SINUSO);
}

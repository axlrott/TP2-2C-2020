#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <vector>
#include "grafo.h"
#include "lector_ebpf.h"
#include "grafo_ebpf.h"
#include "diccionario.h"

void GrafoEbpf::procesarTag(std::string tag){
	dicTags.agregarClave(tag, id_nodo);
	std::vector<int> adyacencias = dicTagsEnEspera.getAllValores(tag);
	for (int id_origen : adyacencias){
		grafoEbpf->addAdy(id_origen, id_nodo);
	}
}

void GrafoEbpf::agregarAdyacencias(std::string tag){
	if(tag.size() > 0){
		if (dicTags.hayClave(tag)){
			int ady = dicTags.getValor(tag);
			grafoEbpf->addAdy(id_nodo, ady);
		}else{
			dicTagsEnEspera.agregarClave(tag, id_nodo);
		}
	}
}

void GrafoEbpf::revisarPtoMuerto(bool hay_return, bool hay_jmpInc){
	if (pto_muerto){
		pto_muerto = false;
	}else{
		grafoEbpf->addAdy(id_nodo-1, id_nodo);
	}
	if (hay_return || hay_jmpInc){
		pto_muerto = true;
	}
}

void GrafoEbpf::procesarLineas(std::string linea){
	std::string tag;
	LectorEbpf lector(linea);
	grafoEbpf->addNodo(id_nodo);

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
	std::fstream archv;
	std::string linea_ebpf;
	archv.open(nombre_archivo);

	while (std::getline(archv, linea_ebpf)){
		if (linea_ebpf.size() > 0){
			procesarLineas(linea_ebpf);
		}
	}
	archv.close();
}

GrafoEbpf::GrafoEbpf(std::string archivo){
	id_nodo = 0;
	pto_muerto = false;
	nombre_archivo = archivo;
	grafoEbpf = new Grafo();
	crearGrafo();
}

bool GrafoEbpf::hayCiclos() const{
	int flag = grafoEbpf->busquedaDFS();
	return (flag == FLAG_CICLO);
}

bool GrafoEbpf::hayInstrSinUso() const{
	int flag = grafoEbpf->busquedaDFS();
	return (flag == FLAG_SINUSO);
}

std::string GrafoEbpf::getNombreArchivo() const{
	return nombre_archivo;
}

GrafoEbpf::~GrafoEbpf(){
	delete grafoEbpf;
}

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <list>
#include "grafo.h"
#include "lector_ebpf.h"
#include "grafo_ebpf.h"
#include "diccionario.h"

void GrafoEbpf::procesarLineas(std::string linea){
	std::string tag;
	LectorEbpf lector = LectorEbpf(linea);
	grafoEbpf->addNodo(id_nodo);

	if(lector.hayTag()){
		tag = lector.getTag();
		dicTags.agregarClave(tag, id_nodo);
		std::list<int> adyacencias = dicTagsEnEspera.getAllValores(tag);
		for (int id_origen : adyacencias){
			grafoEbpf->addAdy(id_origen, id_nodo);
		}
	}
	if (lector.hayJmp()){
		tag = lector.getArg1();
		if (dicTags.hayClave(tag)){
			int ady = dicTags.getValor(tag);
			grafoEbpf->addAdy(id_nodo, ady);
		}else{
			dicTagsEnEspera.agregarClave(tag, id_nodo);
		}
		if (lector.getArg2().size() > 0){
			tag = lector.getArg2();
			if (dicTags.hayClave(tag)){
				int ady = dicTags.getValor(tag);
				grafoEbpf->addAdy(id_nodo, ady);
			}else{
				dicTagsEnEspera.agregarClave(tag, id_nodo);
			}
		}
	}
	if (pto_muerto){
		pto_muerto = false;
	}else{
		grafoEbpf->addAdy(id_nodo-1, id_nodo);
	}
	if (lector.hayReturn() || lector.hayJmpInc()){
		pto_muerto = true;
	}
	id_nodo++;
}

void GrafoEbpf::crearGrafo(){
	std::fstream stream;
	std::string linea_ebpf;
	stream.open(nombre_archivo);

	while (getline(stream, linea_ebpf)){
		if (linea_ebpf.size() > 0){
			procesarLineas(linea_ebpf);
		}
	}
	stream.close();
}

GrafoEbpf::GrafoEbpf(std::string archivo){
	id_nodo = 0;
	pto_muerto = false;
	nombre_archivo = archivo;
	grafoEbpf = new Grafo();
	crearGrafo();
}

bool GrafoEbpf::hayCiclos(){
	int flag = grafoEbpf->dfsErrores();
	return (flag == FLAG_CICLO);
}

bool GrafoEbpf::hayInstrSinUso(){
	int flag = grafoEbpf->dfsErrores();
	return (flag == FLAG_SOLITARIO);
}

std::string GrafoEbpf::getNombreArchivo(){
	return nombre_archivo;
}

GrafoEbpf::~GrafoEbpf(){
	delete grafoEbpf;
}

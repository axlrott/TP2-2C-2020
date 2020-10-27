#ifndef PROCESADOR_T
#define PROCESADOR_T

#include <iostream>
#include <string>
#include <list>
#include "archivos.h"
#include "resultados.h"

class Procesador{
private:
	Archivos* ptr_archivos;
	Resultados* ptr_resultados;
public:
	Procesador(Archivos* archivos, Resultados* resultados);
	void procesar();
	~Procesador();
};
#endif

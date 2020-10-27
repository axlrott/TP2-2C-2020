#ifndef RESULTADOS_T
#define RESULTADOS_T

#include <iostream>
#include <string>
#include <list>
#include "diccionario.h"

enum TIPORESULTADO {OK, CICLO, SINUSO};

class Resultados{
private:
	std::list<std::string> lista_archivos;
	Diccionario dic_archivos;
	std::string msj_ok;
	std::string msj_ciclo;
	std::string msj_sin_uso;
public:
	Resultados();
	void agregarArchivo(std::string archivo);
	void tieneCiclos(std::string archivo);
	void tieneInstrSinUso(std::string archivo);
	void mostrarResultados();
	~Resultados();
};
#endif

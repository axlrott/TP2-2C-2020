#ifndef ARCHIVOS_T
#define ARCHIVOS_T

#include <iostream>
#include <string>
#include <list>

class Archivos{
private:
	std::list<std::string> lista_archivos;
public:
	Archivos();
	void agregarArchivo(std::string archivo);
	bool hayArchivos();
	std::string getNuevoArchivo();
	~Archivos();
};
#endif

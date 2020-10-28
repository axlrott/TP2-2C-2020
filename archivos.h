#ifndef ARCHIVOS_T
#define ARCHIVOS_T

#include <iostream>
#include <string>
#include <list>
#include <mutex>

class Archivos{
private:
	std::list<std::string> lista_archivos;
	std::mutex m;
public:
	Archivos();
	void agregarArchivo(std::string archivo);
	bool hayArchivos();
	std::string getNuevoArchivo();
	~Archivos();
};

#endif

#ifndef RESULTADOS_T
#define RESULTADOS_T

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <mutex>

/*Clase Resultado que almacena archivos y sus resultados
en base a si tuvieron ciclos o instrucciones sin uso*/
class Resultados{
private:
	std::set<std::string> set_archivos;
	std::map<std::string, std::string> dic_archivos;
public:
	Resultados() {}
	void agregarArchivo(std::string &archv, bool ciclos, bool sin_uso);
	void mostrarResultados() const;
	~Resultados() {}
};

#endif

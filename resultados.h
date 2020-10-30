#ifndef RESULTADOS_T
#define RESULTADOS_T

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <mutex>

enum TIPORESULTADO {OK, CICLO, SINUSO};

class Resultados{
private:
	std::list<std::string> lista_archivos;
	std::map<std::string, int> dic_archivos;
	std::string msj_ok;
	std::string msj_ciclo;
	std::string msj_sin_uso;
	void agregarEnOrden(std::string archivo_nuevo);
public:
	Resultados();
	void agregarArchivo(std::string archv, bool ciclos, bool sin_uso);
	void mostrarResultados() const;
	~Resultados();
};

#endif

#ifndef ARCHIVOS_T
#define ARCHIVOS_T

#include <iostream>
#include <string>
#include <list>
#include <mutex>

/*La clase archivo sirve mas que nada para almacenar
strings que representan archivos, se pueden agregar,
preguntar si hay arhivos y se pueden obtener archivos,
los archivos que devuelva son quitados del objeto*/
class Archivos{
private:
	std::list<std::string> lista_archivos;
	std::mutex m;
public:
	Archivos();
	void agregarArchivo(std::string archivo);
	bool hayArchivos() const;
	std::string getNuevoArchivo();
	~Archivos();
};

#endif

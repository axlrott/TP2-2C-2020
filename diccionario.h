#ifndef DICC_T
#define DICC_T

#include <iostream>
#include <string>
#include <list>

/*Objeto que funciona como un diccionario con claves strings
y valores numericos, las claves pueden repetirse*/
class Diccionario{
private:
	std::list<std::string> claves;
	std::list<int> valores;
public:
	Diccionario();
	void agregarClave(std::string clave, int valor);
	bool hayClave(std::string clave);
	int getValor(std::string clave);
	/*getValor devuelve el valor de la primer
	clave que coincida con la buscada*/
	void cambiarClave(std::string clave, int valor);
	/*cambiarClave sobreescribe el valor de la clave
	si ya estaba en el diccionario en caso de que no este
	funciona igual que agregarClave*/
	std::list<int> getAllValores(std::string clave);
	/*getAllValores devuelve una lista con todos
	los valores que tengan la clave buscada*/
	~Diccionario();
};
#endif

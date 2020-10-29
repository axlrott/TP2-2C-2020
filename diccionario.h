#ifndef DICC_T
#define DICC_T

#include <iostream>
#include <string>
#include <vector>

/*Objeto que funciona como un diccionario con claves strings
y valores numericos, las claves pueden repetirse*/
class Diccionario{
private:
	std::vector<std::string> claves;
	std::vector<int> valores;
public:
	Diccionario();
	void agregarClave(std::string clave, int valor);
	bool hayClave(std::string clave) const;
	int getValor(std::string clave) const;
	/*getValor devuelve el valor de la primer
	clave que coincida con la buscada*/
	void cambiarClave(std::string clave, int valor);
	/*cambiarClave sobreescribe el valor de la clave
	si ya estaba en el diccionario en caso de que no este
	funciona igual que agregarClave*/
	std::vector<int> getAllValores(std::string clave) const;
	/*getAllValores devuelve un vector con todos
	los valores que tengan la clave buscada*/
	~Diccionario();
};
#endif

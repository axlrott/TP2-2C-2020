#ifndef GRAFO_T
#define GRAFO_T

#include <iostream>
#include <list>

class Nodo{
private:
	int id;
	std::list<Nodo*> lista_ady;
public:
	explicit Nodo(int identificador);
	Nodo(const Nodo &copy) = delete;
	Nodo operator=(const Nodo &copy) = delete;
	void agregarAdyacencia(Nodo* adyacente);
	int getId() const;
	bool esAdy(int id);
	int cantAdy() const;
	std::list<Nodo*> getAdy();
	~Nodo();
};

enum FLAG_DFS{
	FLAG_OK, FLAG_CICLO, FLAG_SINUSO		
	};

class Grafo{
private:
	size_t cant_nodos;
	std::list<Nodo*> lista_nodos;
	Nodo* getNodo(int id);
	bool hayNodo(int id) const;
	bool yaVisite(std::list<int> vistos, Nodo* nodo) const;
	bool hasCiclo(std::list<int> ids, Nodo* ady, std::list<int> &vistos);
public:
	Grafo();
	Grafo(const Grafo &copy) = delete;
	Grafo operator=(const Grafo &copy) = delete;
	void addNodo(int id);
	void addAdy(int id1, int id2);
	int busquedaDFS();
	/*Esta funcion busca si hay ciclos o instrucciones sin uso en el grafo
	mediante DFS, devuelve un FLAG_DFS del tipo CICLO si hay ciclos, 
	SINUSO si hay una instruccion sin uso y OK si no se encontro nada*/
	~Grafo();
};

#endif

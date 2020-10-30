#ifndef LECTOR_EBPF_T
#define LECTOR_EBPF_T

#include <iostream>
#include <string>
#include <list>

/*La clase LectorEbpf lee una cadena de caracteres que representa
una linea de codigo un archivo bpf. Esta clase sirve para detectar si hay
saltos, los argumentos de ese salto y si la linea de codigo
contiene alguna etiqueta*/
class LectorEbpf{
private:
	std::list<std::string> jmp;
	std::string tag;
	std::string arg1;
	std::string arg2;
	bool isJmpInc;
	bool isReturn;
	bool contieneTag(std::string linea) const;
	bool contieneReturn(std::string palabra) const;
	bool contieneSalto(std::string palabra) const;
	int cantidadArg(std::string linea) const;
	void tomarArgs(std::istringstream &ss, int cant_arg);
public:
	explicit LectorEbpf(std::string linea);
	bool hayTag() const;
	std::string getTag() const;
	bool hayJmp() const;
	bool hayJmpInc() const;
	bool hayReturn() const;
	std::string getArg1() const;
	std::string getArg2() const;
	~LectorEbpf();
};

#endif

#ifndef LECTOR_EBPF_T
#define LECTOR_EBPF_T

#include <iostream>
#include <string>

class LectorEbpf{
private:
	std::string tag;
	std::string arg1;
	std::string arg2;
	bool isJmpInc;
	bool isReturn;
	bool contieneTag(std::string linea);
	bool contieneReturn(std::string palabra);
	bool contieneSalto(std::string palabra);
	int cantidadArg(std::string linea);
public:
	LectorEbpf(std::string linea);
	bool hayTag() const;
	std::string getTag();
	bool hayJmp() const;
	bool hayJmpInc() const;
	bool hayReturn() const;
	std::string getArg1();
	std::string getArg2();
	~LectorEbpf();
};

#endif

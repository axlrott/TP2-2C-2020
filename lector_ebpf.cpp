#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include "lector_ebpf.h"

bool LectorEbpf::contieneTag(std::string &linea) const{
	auto buscarTag = std::find(linea.begin(), linea.end(), ':');
	return (buscarTag != linea.end());
}

bool LectorEbpf::contieneReturn(const std::string &palabra) const{
	return (palabra == "ret");
}

bool LectorEbpf::contieneSalto(const std::string &palabra){
	std::list<std::string> jmp = {"jmp", "ja", "jeq", "jneq",
	"jne", "jlt", "jle", "jgt", "jge", "jset"};
	
	return std::any_of(jmp.begin(), jmp.end(),
		[&](const std::string &salto) {
			return salto == palabra;
		});
}

bool esUnaComa(char c){
	return (c == ',');
}

int LectorEbpf::cantidadArg(std::string &linea) const{
	int cant_arg = 1 + std::count_if(linea.begin(), linea.end(), esUnaComa);
	return cant_arg;
}

void LectorEbpf::tomarArgs(std::istringstream &separador, int cant_arg){
	std::string palabra;
	separador >> palabra;

	if (cant_arg == 1){
		arg1 = palabra;
		isJmpInc = true;
	}else{
		separador >> palabra;
		arg1 = palabra;
	}
	if (cant_arg == 3){
		arg1.erase(arg1.end()-1, arg1.end());
		separador >> palabra;
		arg2 = palabra;
		isJmpInc = true;
	}
}

LectorEbpf::LectorEbpf(std::string &linea){
	isJmpInc = false;
	isReturn = false;
	bool linea_tag = contieneTag(linea);
	int cant_arg = cantidadArg(linea);
	std::istringstream separador(linea);
	std::string palabra;

	separador >> palabra;
	if (linea_tag){
		palabra.erase(palabra.end()-1, palabra.end());
		tag = palabra;
		separador >> palabra;
	}
	if (contieneSalto(palabra)){
		tomarArgs(separador, cant_arg);
	}else if (contieneReturn(palabra)){
		isReturn = true;
	}
}

bool LectorEbpf::hayTag() const{
	return (tag.size() > 0);
}

std::string LectorEbpf::getTag() const{
	return tag;
}

bool LectorEbpf::hayJmp() const{
	return (arg1.size() > 0);
}

bool LectorEbpf::hayJmpInc() const{
	return isJmpInc;
}

bool LectorEbpf::hayReturn() const{
	return isReturn;
}

std::string LectorEbpf::getArg1() const{
	return arg1;
}

std::string LectorEbpf::getArg2() const{
	return arg2;
}

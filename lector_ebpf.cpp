#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include "lector_ebpf.h"

#define JMP {"jmp", "ja", "jeq", "jneq","jne", "jlt", "jle", "jgt", "jge", "jset"}

bool LectorEbpf::contieneTag(std::string linea){
	for (char caracter : linea){
		if (caracter == ':'){
			return true;
		}
	}
	return false;
}

bool LectorEbpf::contieneReturn(std::string palabra){
	return (palabra.compare("ret") == 0);
}

bool LectorEbpf::contieneSalto(std::string palabra){
	for(std::string salto : JMP){
		if(palabra.compare(salto) == 0){
			return true;
		}
	}
	return false;
}

int LectorEbpf::cantidadArg(std::string linea){
	int cant_arg = 1;

	for(char caracter : linea){
		if (caracter == ','){
			cant_arg++;
		}
	}
	return cant_arg;
}


LectorEbpf::LectorEbpf(std::string linea){
	isJmpInc = false;
	isReturn = false;
	bool linea_tag = contieneTag(linea);
	int cant_arg = cantidadArg(linea);
	std::istringstream ss(linea);
	std::string palabra;

	ss >> palabra;

	if (linea_tag){
		palabra.erase(palabra.end()-1, palabra.end());
		tag = palabra;
		ss >> palabra;
	}
	if (contieneSalto(palabra)){
		ss >> palabra;
		if (cant_arg == 1){
			arg1 = palabra;
			isJmpInc = true;
		}else{
			ss >> palabra;
			arg1 = palabra;
		}
		if (cant_arg == 3){
			arg1.erase(arg1.end()-1, arg1.end());
			ss >> palabra;
			arg2 = palabra;
			isJmpInc = true;
		}
	}else if (contieneReturn(palabra)){
		isReturn = true;
	}
}

bool LectorEbpf::hayTag() const{
	return (tag.size() > 0);
}

std::string LectorEbpf::getTag(){
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

std::string LectorEbpf::getArg1(){
	return arg1;
}

std::string LectorEbpf::getArg2(){
	return arg2;
}

LectorEbpf::~LectorEbpf(){
}

#include <iostream>
#include <string>
#include "procesador.h"
#include "grafo_ebpf.h"

void Procesar::run(){
	while(true){
		std::string archv = mArchv.RecvArchivoProt();
		if (archv.size() == 0){
			return;
		}
		GrafoEbpf gf(archv);
		mRes.sendResProt(archv, gf.hayCiclos(), gf.hayInstrSinUso());
	}
}

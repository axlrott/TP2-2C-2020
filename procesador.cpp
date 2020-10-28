#include <iostream>
#include <string>
#include "procesador.h"
#include "grafo_ebpf.h"

Procesar::Procesar(MonitorArchv &monitor_archv) : monitor(monitor_archv) {
}

void Procesar::run(){
	bool continuar = true;

	while(continuar){
		std::string archv = monitor.RecvArchivoProtected();
		if (archv.size() == 0){
			return;
		}
		GrafoEbpf gf = GrafoEbpf(archv);
		monitor.sendResProtected(archv, gf.hayCiclos(), gf.hayInstrSinUso());
	}
}

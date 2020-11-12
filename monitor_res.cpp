#include "monitor_res.h"
#include <string>
#include <mutex>

void MonitorRes::sendResProt(std::string archv, bool ciclo, bool sin_uso){
	std::unique_lock<std::mutex> lck(m);
	resultados.agregarArchivo(archv, ciclo, sin_uso);
}

void MonitorRes::mostrarResultados(){
	resultados.mostrarResultados();
}

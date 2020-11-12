#include <string>
#include "monitor_archv.h"

void MonitorArchv::agregarArchivo(std::string archv){
	archivos.push_back(archv);
}

bool MonitorArchv::hayArchivos() const{
	return (archivos.size() > 0);
}

std::string MonitorArchv::RecvArchivoProt(){
	std::unique_lock<std::mutex> lck(m);

	if (hayArchivos()){
		std::string archivo = archivos.front();
		archivos.pop_front();
		return archivo;
	}
	return "";
}

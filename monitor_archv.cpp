#include <string>
#include "monitor_archv.h"
#include "lock.h"

MonitorArchv::MonitorArchv(Archivos* archivos, Resultados* resultados){
	ptr_archv = archivos;
	ptr_res = resultados;
}

std::string MonitorArchv::RecvArchivoProt(){
	Lock l(m);
	return (ptr_archv->getNuevoArchivo());
}

void MonitorArchv::sendResProt(std::string archv, bool ciclo, bool sin_uso){
	Lock l(m);
	ptr_res->agregarArchivo(archv, ciclo, sin_uso);
}

MonitorArchv::~MonitorArchv(){
}

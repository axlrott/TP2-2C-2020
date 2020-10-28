#ifndef MONITOR_ARCHV_T
#define MONITOR_ARCHV_T

#include <string>
#include "archivos.h"
#include "resultados.h"

/*La clase MonitorArchv tiene un puntero a una Clase Archivos y 
a una clase Resultados, sirve para recibir archivos y para enviar
resultados por threads utilizando mutex para evitar conflictos*/
class MonitorArchv{
private:
	Archivos* ptr_archv;
	Resultados* ptr_res;
	std::mutex m;
public:
	MonitorArchv(Archivos* archivos, Resultados* resultados);
	std::string RecvArchivoProt();
	void sendResProt(std::string archv, bool ciclo, bool sin_uso);
	~MonitorArchv();
};

#endif

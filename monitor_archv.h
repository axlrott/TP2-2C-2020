#ifndef MONITOR_ARCHV_T
#define MONITOR_ARCHV_T

#include "archivos.h"
#include "resultados.h"

class MonitorArchv{
private:
	Archivos* ptr_archv;
	Resultados* ptr_res;
	std::mutex m;
public:
	MonitorArchv(Archivos* ptr1, Resultados* ptr2);
	std::string RecvArchivoProtected();
	void sendResProtected(std::string archv, bool ciclo, bool sin_uso);
	~MonitorArchv();
};

#endif

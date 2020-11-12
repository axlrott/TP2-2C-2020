#ifndef MONITOR_RES_T
#define MONITOR_RES_T

#include <string>
#include <mutex>
#include "resultados.h"

class MonitorRes{
private:
	Resultados resultados;
	std::mutex m;
public:
	MonitorRes() {}
	void sendResProt(std::string archv, bool ciclo, bool sin_uso);
	void mostrarResultados();
	~MonitorRes() {}
};

#endif

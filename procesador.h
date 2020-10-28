#ifndef PROCESADOR_T
#define PROCESADOR_T

#include <iostream>
#include <string>
#include "thread_tda.h"
#include "monitor_archv.h"

class Procesar : public Thread { 
private:
	MonitorArchv &monitor;
public:
	Procesar(MonitorArchv &monitor_archv);
	virtual void run() override;
	~Procesar(){};
};

#endif

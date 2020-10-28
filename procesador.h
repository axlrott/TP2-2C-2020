#ifndef PROCESADOR_T
#define PROCESADOR_T

#include <iostream>
#include <string>
#include "thread_tda.h"
#include "monitor_archv.h"

/*La clase Procesar es la que ira recibiendo archivos de la clase Archivos
y los va a pasar a grafos ebpf para luego informar si tienen ciclos o
instrucciones sin uso a la clase Resultados mediante la clase MonitorArchv*/
class Procesar : public Thread { 
private:
	MonitorArchv &monitor;
public:
	explicit Procesar(MonitorArchv &monitor_archv);
	virtual void run() override;
	~Procesar(){}
};

#endif

#ifndef PROCESADOR_T
#define PROCESADOR_T

#include <iostream>
#include <string>
#include "thread_tda.h"
#include "monitor_archv.h"
#include "monitor_res.h"

/*La clase Procesar es la que ira recibiendo archivos de la clase Archivos
y los va a pasar a grafos ebpf para luego informar si tienen ciclos o
instrucciones sin uso a la clase Resultados mediante la clase MonitorArchv
y la clase MonitorRes*/
class Procesar : public Thread { 
private:
	MonitorArchv &mArchv;
	MonitorRes &mRes;
public:
	Procesar(MonitorArchv &Archv, MonitorRes &Res): mArchv(Archv), mRes(Res) {}
	virtual void run() override;
	~Procesar(){}
};

#endif

#ifndef MONITOR_ARCHV_T
#define MONITOR_ARCHV_T

#include <string>
#include <list>
#include <mutex>

class MonitorArchv{
private:
	std::list<std::string> archivos;
	std::mutex m;
public:
	MonitorArchv() {}
	void agregarArchivo(std::string archv);
	bool hayArchivos() const;
	std::string RecvArchivoProt();
	~MonitorArchv() {}
};

#endif

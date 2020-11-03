#ifndef LOCK_T
#define LOCK_T

#include <mutex>

/*Clase Lock basada en una vista en los
ejemplos interactivos de la materia, hecha
para hacer encapsulamiento del mutex*/
class Lock {
private:
	std::mutex &m;
public:
	explicit Lock(std::mutex &m);
	~Lock();
private:
	Lock(const Lock&) = delete;
	Lock& operator=(const Lock&) = delete;
	Lock(Lock&&) = delete;
	Lock& operator=(Lock&&) = delete;
};

#endif

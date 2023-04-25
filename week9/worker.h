#ifndef _WORKER_H
#define _WORKER_H
#include <cstring>
#include "project.h"

class Worker {
protected:
	std::string name;
	int months;
	int salary = 1;
public:
	virtual void annual_raise() = 0;
};

#endif
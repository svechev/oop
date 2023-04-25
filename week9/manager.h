#ifndef _MANAGER_H
#define _MANAGER_H
#include "worker.h"

class Manager : public Worker {
protected:
	int subworkers;
public:
	void annual_raise();
};

#endif

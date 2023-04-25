#ifndef _PROGRAMMER_H
#define _PROGRAMMER_H
#include "qa.h"
#include "programmer.h"
#include "project.h"

class System {
private:
	int annual_budget = 20000;
	Worker** workers;
	int num_workers;
	Project** projects;
	int num_projects;
public:
	void annual_raises() { //nqmam vreme da go napravq po-hubavo
		for (int i = 0; i < n; i++) {
			workers[i]->annual_raise();
		}
		annual_budget = 0;
	};
};

#endif

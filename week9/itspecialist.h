#ifndef _ITSPECIALIST_H
#define _ITSPECIALIST_H
#include "worker.h"

class ITSpecialist : public Worker {
protected:
	Project** projects;
	int num_projects;
	void free();
	double project_difficulty();

public:
	ITSpecialist(const Project* new_projects, int arr_size);
	virtual ~ITSpecialist();

	ITSpecialist& operator=(const ITSpecialist& other);
	ITSpecialist(const ITSpecialist& other);
};

#endif

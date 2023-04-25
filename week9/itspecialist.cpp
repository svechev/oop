#include "itspecialist.h"

void ITSpecialist::free()
{
	for (int i = 0; i < num_projects; i++) {
		delete projects[i];
	}
	delete[] projects;
}

double ITSpecialist::project_difficulty()
{
	double average = 0;
	for (int i = 0; i < num_projects; i++) {
		average += projects[i]->get_diff();
	}

	return average / num_projects;
}

ITSpecialist::ITSpecialist(const Project* new_projects, int arr_size)
{
	num_projects = 0;
	for (int i = 0; i < arr_size; i++) {
		projects[i] = new Project(new_projects[i]);
		num_projects++;
	}
}

ITSpecialist::~ITSpecialist()
{
	free();
}

ITSpecialist& ITSpecialist::operator=(const ITSpecialist& other)
{
	if (this != &other) {
		free();
		num_projects = 0;
		for (int i = 0; i < other.num_projects; i++) {
			projects[i] = new Project(*other.projects[i]);
			num_projects++;
		}
	}
	return *this;
}

ITSpecialist::ITSpecialist(const ITSpecialist& other)
{
	for (int i = 0; i < other.num_projects; i++) {
		projects[i] = new Project(*other.projects[i]);
		num_projects++;
	}
}

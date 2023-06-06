#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "person.h"
#include "movie.h"

class Employee : public Person {
protected:
	size_t salary;
public:
	void addMovie(const Movie& movie);
	void addScreening(const Screening& screening);
	void buyTicket(Screening* screening);
};

#endif

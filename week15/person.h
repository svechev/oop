#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "cinema.h"
#include "screening.h"

class Person {
protected:
	Cinema* cinema;
	std::string names;
	std::string dateOfBirth;
public:
	virtual void buyTicket(Screening* screening) = 0;
	void getReservations();
	virtual ~Person() = default;
	virtual Person* clone() const = 0;

};

#endif

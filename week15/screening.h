#ifndef SCREENING_H
#define SCREENING_H
#include <string>
#include <vector>
#include "movie.h"
#include "room.h"

class Screening {
private:
	Movie* film;
	Room* room;
	size_t takenSeats;
	std::vector<Person*> people;
	double price;
public:
	void makeReservation(const Person*);
	void print() const;
	double getPrice() const;


};

#endif

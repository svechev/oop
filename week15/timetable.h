#ifndef SCREENING_H
#define SCREENING_H
#include "screening.h"

class Timetable {
private:
	std::vector<Screening> screenings;
public:
	void addScreening(Screening screening);
};

#endif


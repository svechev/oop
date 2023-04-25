#ifndef _PROGRAMMER_H
#define _PROGRAMMER_H
#include "itspecialist.h"

class Programmer : public ITSpecialist {
protected:
	std::string language;

public:
	void annual_raise();
};

#endif

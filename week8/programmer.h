#ifndef _PROGRAMMER_H
#define _PROGRAMMER_H
#include "itspecialist.h"

class Programmer : protected ITSpecialist {
protected:
	char* language;
};

#endif
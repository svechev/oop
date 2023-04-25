#ifndef DOG_H
#define DOG_H
#include "animal.h"
#include <iostream>

class Dog : public Animal {
public:
	Dog(const char* _name, const char* _species) : Animal(_name, _species) {};

	void talk();
};

#endif

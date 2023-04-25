#ifndef CAT_H
#define CAT_H
#include "animal.h"
#include <iostream>

class Cat : public Animal {
public:
	Cat(const char* _name, const char* _species) : Animal(_name, _species) {};
	// Cat(const char* _name) : Animal(_name, "Cat") {};

	void talk();
};

#endif

#define _CRT_SECURE_NO_WARNINGS
#ifndef ANIMAL_H
#define ANIMAL_H
#include <cstring>
#include <iostream>

class Animal {
protected:
	char* name;
	char* species;
	void copy(const char* _name, const char* _species);
	void free();
	void move(Animal&& other);

public:
	Animal(const char* _name, const char* _species);
	virtual ~Animal();
	
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	Animal(Animal&& other);
	Animal& operator=(Animal&& other);


	virtual void talk() = 0;
};

#endif
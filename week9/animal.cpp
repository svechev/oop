#include "animal.h"

void Animal::copy(const char* _name, const char* _species)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	species = new char[strlen(_species) + 1];
	strcpy(species, _species);
}

void Animal::free()
{
	delete[] name;
	delete[] species;
}

void Animal::move(Animal&& other)
{
	name = other.name;
	other.name = nullptr;

	species = other.species;
	other.species = nullptr;
}

Animal::Animal(const char* _name, const char* _species)
{
	copy(_name, _species);
}

Animal::~Animal()
{
	free();
}

Animal::Animal(const Animal& other)
{
	copy(other.name, other.species);
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other) {
		free();
		copy(other.name, other.species);
	}
	return *this;
}

Animal::Animal(Animal&& other)
{
	move(std::move(other));
}

Animal& Animal::operator=(Animal&& other)
{
	if (this != &other) {
		free();
		move(std::move(other));
	}
	return *this;
}

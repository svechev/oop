#ifndef CHOCOLATE_H
#define CHOCOLATE_H
#include <string>
#include <iostream>

template <typename T>
class Chocolate {
protected:
	T id;
	virtual bool validId() const = 0;
public:
	Chocolate(T id) : id(id) {};
};

#endif



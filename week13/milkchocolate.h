#ifndef MILK_CHOCOLATE_H
#define MILK_CHOCOLATE_H
#include "chocolate.h"

class MilkChocolate : virtual public Chocolate<int> {
protected:
	int milk;
	bool validId() const override;
public:
	MilkChocolate(int id, int milk);
};

#endif

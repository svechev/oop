#ifndef DARK_CHOCOLATE_H
#define DARK_CHOCOLATE_H
#include "chocolate.h"

class DarkChocolate : virtual public Chocolate<std::string> {
protected:
	int cocoa;
	bool validId() const override;
public:
	DarkChocolate(std::string id, int cocoa);
};

#endif

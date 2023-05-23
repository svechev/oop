#ifndef RAISINS_H
#define RAISINS_H
#include "chocolate.h"

template <typename U>
class Raisins : virtual public Chocolate<U> {
protected:
	int raisins;
	bool validId() const override = 0;
public:
	Raisins(const U& id, int raisins);
};


#endif

template<typename U>
Raisins<U>::Raisins(const U& id, int raisins) : Chocolate<U>(id), raisins(raisins)
{
}

#ifndef MILK_RAISINS_H
#define MILK_RAISINS_H
#include "raisins.h"
#include "milkchocolate.h"

class MilkRaisins : public MilkChocolate, public Raisins<int> {
protected:
	bool validId() const override;
public:
	MilkRaisins(int id, int milk = 35, int raisins = 20);
};

#endif

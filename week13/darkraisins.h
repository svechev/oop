#ifndef DARK_RAISINS_H
#define DARK_RAISINS_H
#include "raisins.h"
#include "darkchocolate.h"

class DarkRaisins : public DarkChocolate, public Raisins<std::string> {
protected:
	bool validId() const override;
public:
	DarkRaisins(std::string id, int cocoa = 80, int raisins = 20);
};

#endif

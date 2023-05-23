#include "darkraisins.h"

bool DarkRaisins::validId() const
{
    return id[0] == 'S';
}

DarkRaisins::DarkRaisins(std::string id, int cocoa, int raisins)
    : Chocolate(id), DarkChocolate(id, cocoa), Raisins(id, raisins)
{
}

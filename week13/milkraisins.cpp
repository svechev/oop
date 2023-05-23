#include "milkraisins.h"

bool MilkRaisins::validId() const
{
    if (id < 45) return false;
    return true;
}

MilkRaisins::MilkRaisins(int id, int milk, int raisins) 
    : Chocolate(id), MilkChocolate(id, milk), Raisins(id, raisins)
{
}

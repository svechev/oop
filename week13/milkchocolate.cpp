#include "milkchocolate.h"

bool MilkChocolate::validId() const
{
    return true;
}

MilkChocolate::MilkChocolate(int id, int milk) : Chocolate<int>(id), milk(milk)
{   

}

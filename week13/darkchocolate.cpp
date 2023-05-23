#include "darkchocolate.h"

bool DarkChocolate::validId() const
{
    return true;
}

DarkChocolate::DarkChocolate(std::string id, int cocoa) : Chocolate<std::string>(id), cocoa(cocoa)
{
}

#include "room.h"

Room::Room(size_t numberOfSeats, const std::string& name) : numberOfSeats(numberOfSeats), name(name)
{
}

size_t Room::getSeats() const
{
	return numberOfSeats;
}

std::string Room::getName() const
{
	return name;
}

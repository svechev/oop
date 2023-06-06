#include "movie.h"

Movie::Movie(const std::string& name, const std::string& genre, size_t duration, size_t year, double price)
	: name(name), genre(genre), duration(duration), yearOfPremiere(year), price(price)
{
}

size_t Movie::getDuration() const
{
	return duration;
}

size_t Movie::getYear() const
{
	return yearOfPremiere;
}

std::string Movie::getName() const
{
	return name;
}

std::string Movie::getGenre() const
{
	return genre;
}

double Movie::getPrice() const
{
	return price;
}

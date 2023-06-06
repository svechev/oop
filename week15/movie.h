#ifndef MOVIE_H
#define MOVIE_H
#include <string>

class Movie {
private:
	std::string name;
	std::string genre;
	size_t duration;
	size_t yearOfPremiere;
	double price;
public:
	Movie(const std::string& name, const std::string& genre, size_t duration, size_t year, double price);
	size_t getDuration() const;
	size_t getYear() const;
	std::string getName() const;
	std::string getGenre() const;
	double getPrice() const;
};

#endif

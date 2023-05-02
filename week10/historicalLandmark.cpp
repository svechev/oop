#include "historicalLandmark.h"

void HistoricalLandmark::getInfo(std::ifstream& iFile)
{
	if (!iFile.eof()) {
		int coords_size;
		iFile >> coords_size;
		iFile.ignore(); //ignore spaces

		char* coords_str = new char[coords_size + 1];
		iFile.read(coords_str, coords_size);
		iFile.ignore();

		coordinates = coords_str; //ne znam kak raboti s std::string no dano raboti
		delete[] coords_str;

		int desc_size;
		iFile >> desc_size;
		iFile.ignore(); //ignore spaces

		char* desc_str = new char[desc_size + 1];
		iFile.read(desc_str, desc_size);
		iFile.ignore();

		description = desc_str; //ne znam kak raboti s std::string no dano raboti
		delete[] desc_str;

		iFile >> year;
		iFile.ignore(3, '\n');

	}

	else {
		throw std::exception("Landmark information unavailable");
	}
}

int HistoricalLandmark::getYear() const
{
    return year;
}

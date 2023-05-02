#include "companyUser.h"

void CompanyUser::getUserInfo(std::ifstream& iFile)
{
	if (!iFile.eof()) {
		int name_size;
		iFile >> name_size;
		iFile.ignore(); //ignore spaces

		char* name_str = new char[name_size + 1];
		iFile.read(name_str, name_size);
		iFile.ignore();

		name = name_str; //ne znam kak raboti s std::string no dano raboti
		delete[] name_str;

		iFile >> salary;
		iFile.ignore(3, '\n');

	}

	else {
		throw std::exception("User information unavailable");
	}
}

void CompanyUser::writeLandmarktoFile(std::ofstream& oFile, const HistoricalLandmark& landmark)
{
	std::string coords = landmark.getCoords();
	oFile << coords.length() << coords << " ";
	std::string desc = landmark.getDesc();

	oFile << desc.length() << desc << " ";

	oFile << landmark.getYear() << "\n";
}

void CompanyUser::writeLandmarktoFile(std::ofstream& oFile, const NatureLandmark& landmark)
{
	std::string coords = landmark.getCoords();
	oFile << coords.length() << " " << coords << " ";
	std::string desc = landmark.getDesc();

	oFile << desc.length() << " " << desc << " ";

	oFile << landmark.getMonth() << "\n";
}


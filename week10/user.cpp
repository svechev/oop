#include "user.h"

void User::getUserInfo(std::ifstream& iFile)
{
	if (!iFile.eof()) {
		int name_size;
		iFile >> name_size;
		iFile.ignore(); //ignore spaces

		char* name_str = new char[name_size + 1];
		iFile.read(name_str, name_size);

		name = name_str; //ne znam kak raboti s std::string no dano raboti
		delete[] name_str;
		iFile.ignore(3, '\n');
	}

	else {
		throw std::exception("User information unavailable");
	}
}


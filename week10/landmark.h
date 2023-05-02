#ifndef LANDMARK_H
#define LANDMARK_H
#include <string>
#include <fstream>

class Landmark {
protected:
	std::string coordinates;
	std::string description;
public:
	virtual void getInfo(std::ifstream& iFile) = 0;

	std::string getCoords() const;
	std::string getDesc() const;
};

#endif
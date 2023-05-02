#ifndef HISTORICAL_LANDMARK_H
#define HISTORICAL_LANDMARK_H
#include "landmark.h"

class HistoricalLandmark : public Landmark {
	int year;
public:
	void getInfo(std::ifstream& iFile);

	int getYear() const;
};

#endif

#ifndef NATURE_LANDMARK_H
#define NATURE_LANDMARK_H
#include "landmark.h"

class NatureLandmark : public Landmark {
	int visiting_month;
public:
	void getInfo(std::ifstream& iFile);

	int getMonth() const;
};

#endif

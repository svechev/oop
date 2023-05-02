#ifndef COMPANY_USER_H
#define COMPANY_USER_H
#include "user.h"
#include "historicalLandmark.h"
#include "natureLandmark.h"

class CompanyUser : public User {
protected:
	int salary;
	
public:
	void getUserInfo(std::ifstream& iFile);

	void writeLandmarktoFile(std::ofstream& oFile, const HistoricalLandmark& landmark);
	void writeLandmarktoFile(std::ofstream& oFile, const NatureLandmark& landmark);
};

#endif

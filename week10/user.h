#ifndef USER_H
#define USER_H
#include <fstream>
#include <string>

//zadachata ne kazva v user kakvo da ima

class User {
protected:
	std::string name;
	
public:
	virtual void getUserInfo(std::ifstream& iFile);
};

#endif

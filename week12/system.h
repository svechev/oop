#ifndef SYSTEM_H
#define SYSTEM_H
#include "premiumuser.h"


class UserSystem {
protected:
	std::vector<User> users;
	std::vector<PremiumUser> premiumUsers;
public:
	void addUser(const User& user);
	void addPremiumUser(const PremiumUser& user);
	bool existingUser(std::string name, std::string pass);
};

#endif

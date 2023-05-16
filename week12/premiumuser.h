#ifndef PREMIUM_USER_H
#define PREMIUM_USER_H
#include "user.h"

class PremiumUser : public User {
protected:
	std::string planDesc;
	std::vector<std::string> datesList;
public:
	PremiumUser(const std::string& _name, const std::string& _pass, const std::string& _planDesc, const std::vector<std::string>& dates);
	PremiumUser(const PremiumUser& other);
};

#endif

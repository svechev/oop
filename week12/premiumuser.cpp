#include "premiumuser.h"

PremiumUser::PremiumUser(const std::string& _name, const std::string& _pass, const std::string& _planDesc, const std::vector<std::string>& dates)
	: User(_name, _pass)
{
	planDesc = _planDesc;
	datesList = dates;
}

PremiumUser::PremiumUser(const PremiumUser& other) : User(other)
{
	planDesc = other.planDesc;
	datesList = other.datesList;
}


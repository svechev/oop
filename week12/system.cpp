#include "system.h"

void UserSystem::addUser(const User& user)
{
	users.resize(users.size() + 1);
	users.push_back(user);
}

void UserSystem::addPremiumUser(const PremiumUser& user)
{
	premiumUsers.resize(premiumUsers.size() + 1);
	premiumUsers.push_back(user);
}

bool UserSystem::existingUser(std::string name, std::string pass)
{
	User new_user(name, pass);
	int numUsers = users.size();
	for (int i = 0; i < numUsers; ++i) {
		if (name == users[i].getName() && User::comparePassword(users[i], new_user)) {
			return true;
		}
	}
	return false;
}

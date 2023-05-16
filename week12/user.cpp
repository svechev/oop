#include "user.h"

unsigned User::idGenerator = 1;

std::string User::cryptPass(const std::string& pass)
{
	std::string cryptedPass;
	int len = pass.length();
	for (int i = 0; i < len; ++i) {
		cryptedPass[i] == pass[i] + 1;
	}
	return cryptedPass;
}

bool User::comparePassword(const User& user1, const User& user2)
{
	return user1.password == user2.password;
}

std::string User::getName() const
{
	return name;
}

User::User(std::string _name, std::string _password)
{
	id = idGenerator;
	idGenerator++;

	name = _name;
	password = cryptPass(_password);
}

User::User(const User& other)
{
	id = idGenerator;
	idGenerator++;

	name = other.name;
	password = other.password;
}



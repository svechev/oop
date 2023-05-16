#ifndef USER_H
#define USER_H
#include <string>
#include <vector>

class User {
protected:
	unsigned id;
	static unsigned idGenerator;
	std::string name;
	std::string password;
	std::string cryptPass(const std::string& pass);

	
public:
	User(std::string _name, std::string _password);
	User(const User& other);

	static bool comparePassword(const User& user1, const User& user2);
	std::string getName() const;
};


#endif

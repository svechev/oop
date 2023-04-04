#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "event.h"
#include <cstring>

User::User()
{
	username[0] = '\0';
	password[0] = '\0';
}

User::User(char name[32], char pass[16])
{
	strcpy(username, name);
	strcpy(password, pass);
}

//void User::addEvent(const Event& event)
//{
//	calendar[0] = event;
//	numEvents++;
//}

void User::printEvents()
{
	if (!numEvents) {
		std::cout << "No events for this user!";
	}
	/*for (int i = 0; i < numEvents; i++) {
		std::cout << calendar[i] << std::endl;
	}*/
}

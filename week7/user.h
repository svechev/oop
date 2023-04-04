#ifndef USER_H
#define USER_H
#include "event.h"

class User {
public:
	char username[32];
	char password[16];
	//Event calendar[3];
	int numEvents = 0;

	User();
	User(char name[32], char pass[16]);
	//void addEvent(const Event& event);
	void printEvents();
};

#endif

#ifndef EVENT_H
#define EVENT_H
#include "user.h"
#include <iostream>

class Event {
private:
	char description[101];
	char date[11];
	char hour[6];
public:
	Event();
	Event(char desc[101], char date[11], char hour[6]);
	Event(const Event& other);
	Event& operator=(const Event& other);

	friend class User;
	friend std::ostream& operator<<(std::ostream& os, const Event& event);
};



#endif

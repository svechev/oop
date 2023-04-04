#define _CRT_SECURE_NO_WARNINGS
#include "event.h"
#include <cstring>

Event::Event()
{
	strcpy(description, "No description");
	strcpy(date, "XX/XX/XXXX");
	strcpy(hour, "XX/XX");
}

Event::Event(char desc[101], char date[11], char hour[6])
{
	strcpy(description, desc);
	strcpy(date, date);
	strcpy(hour, hour);
}

Event::Event(const Event& other)
{
	strcpy(description, other.description);
	strcpy(date, other.date);
	strcpy(hour, other.hour);
}

Event& Event::operator=(const Event& other)
{
	if (this != &other) {
		strcpy(description, other.description);
		strcpy(date, other.date);
		strcpy(hour, other.hour);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Event& event)
{
	os << "description: " << event.description << ", date: " 
		<< event.date << ", hour: " << event.hour;
	return os;
}

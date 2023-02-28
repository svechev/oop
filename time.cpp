#include "time.h" 
#include <cstring>

Time::Time() {
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}

Time::Time(int hours, int minutes, int seconds) {
	this->set_hour(hours);
	this->set_minute(minutes);
	this->set_second(seconds);
}





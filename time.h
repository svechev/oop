#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
	int hour;
	int minute;
	int second;
public:
	void set_hour(int h) {
		hour = h;
		while (hour >= 24) {
			hour -= 24;
		}
	}
	void set_minute(int m) {
		minute = m;
		while (minute >= 60) {
			minute -= 60;
			hour += 1;
		}
	}
	void set_second(int s) {
		second = s;
		while (second >= 60) {
			second -= 60;
			minute += 1;
		}
	}
	int get_hour() {
		return hour;
	}
	int get_minute() {
		return minute;
	}
	int get_second() {
		return second;
	}

	void print() {
		std::cout << hour << ":" << minute << ":" << second;
	};
	Time();
	Time(int hours, int minutes, int seconds);

};

#endif
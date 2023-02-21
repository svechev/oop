#include <iostream>

struct Time {
	int hour;
	int minute;
	int second;
	void print() { 
		std::cout << hour << ":" << minute << ":" << second; 
	}
};

struct Event {
	char title[128];
	char organizer[128];
	Time start_time;
	Time end_time;
	Time get_duration();
	void init();
};

void Event::init() {
	std::cin.getline(title, 128);
	std::cin.getline(organizer, 128);
	std::cin >> start_time.hour >> start_time.minute >> start_time.second;
	std::cin >> end_time.hour >> end_time.minute >> end_time.second;
}

Time Event::get_duration() {
	Time diff_time;
	diff_time.hour = end_time.hour - start_time.hour;
	diff_time.minute = end_time.minute - start_time.minute;
	diff_time.second = end_time.second - start_time.second;
	if (diff_time.second < 0) {
		diff_time.minute -= 1;
		diff_time.second += 60;
	}
	if (diff_time.minute < 0) {
		diff_time.hour -= 1;
		diff_time.minute += 60;
	}
	return diff_time;
}


int main() {
	Event event1;
	event1.init();
	Time duration = event1.get_duration();
	duration.print();
	return 0;
}
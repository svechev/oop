#ifndef EVENT_H
#define EVENT_H
#include "time.h"
#include <cstring>

class Event {
private:
	char title[128];
	char organizer[128];
	Time start_time;
	Time end_time;
public:
	Time get_start_time() {
		return start_time;
	}
	Time get_end_time() {
		return end_time;
	}
	Time get_duration();
	bool overlap_events(Event new_event);
	Event();
	Event(const char* event_title, const char* event_organizer, Time event_start_time, Time event_end_time);
};


#endif
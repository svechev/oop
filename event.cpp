#include "time.h"
#include "event.h"

Event::Event() {
	this->title[0] = '\0';
	this->organizer[0] = '\0';
	this->start_time = { 0, 0, 0 };
	this->end_time = { 0, 0, 0 };
}

Event::Event(const char* event_title, const char* event_organizer, Time event_start_time, Time event_end_time) {
	strncpy_s(title, event_title, 128);
	strncpy_s(organizer, event_organizer, 128);
	start_time = event_start_time;
	end_time = event_end_time;
}

Time Event::get_duration() {
	Time diff_time;
	diff_time.set_hour(end_time.get_hour() - start_time.get_hour());
	diff_time.set_minute(end_time.get_minute() - start_time.get_minute());
	diff_time.set_second(end_time.get_second() - start_time.get_second());
	if (diff_time.get_second() < 0) {
		diff_time.set_minute(diff_time.get_minute() - 1);
		diff_time.set_second(diff_time.get_second() + 60);
	}
	if (diff_time.get_minute() < 0) {
		diff_time.set_hour(diff_time.get_hour() - 1);
		diff_time.set_minute(diff_time.get_minute() + 60);
	}
	return diff_time;
}

bool Event::overlap_events(Event new_event) {
	int event_2_start_hour = new_event.get_start_time().get_hour();
	int event_2_start_minute = new_event.get_start_time().get_minute();
	int event_2_start_second = new_event.get_start_time().get_second();
	int event_2_end_hour = new_event.get_end_time().get_hour();
	int event_2_end_minute = new_event.get_end_time().get_minute();
	int event_2_end_second = new_event.get_end_time().get_second();
	int event_1_end_hour = this->get_end_time().get_hour();
	int event_1_end_minute = this->get_end_time().get_minute();
	int event_1_end_second = this->get_end_time().get_second();
	int event_1_start_hour = this->get_start_time().get_hour();
	int event_1_start_minute = this->get_start_time().get_minute();
	int event_1_start_second = this->get_start_time().get_second();

	if (event_2_start_hour > event_1_end_hour) {
		return false;
	}
	else if (event_2_start_hour == event_1_end_hour) {
		if (event_2_start_minute > event_1_end_minute) {
			return false;
		}
		else if (event_2_start_minute == event_1_end_minute) {
			if (event_2_start_second >= event_1_end_second) {
				return false;
			}
		}
	}
	if (event_1_start_hour > event_2_end_hour) {
		return false;
	}
	else if (event_1_start_hour == event_2_end_hour) {
		if (event_1_start_minute > event_2_end_minute) {
			return false;
		}
		else if (event_1_start_minute == event_2_end_minute) {
			if (event_1_start_second >= event_2_end_second) {
				return false;
			}
		}
	}
	return true;
}
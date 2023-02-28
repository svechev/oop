#include "time.h"
#include "event.h"

int main() {
	Event event_2("title", "az", { 1, 2, 3 }, { 2, 1, 1 });
	Event event_1("title2", "ti", { 2, 2, 1 }, { 3, 3, 3 });
	std::cout << event_1.overlap_events(event_2);
	return 0;
}
#include "programmer.h"

void Programmer::annual_raise()
{
	double diff = project_difficulty();
	if (diff >= 1 && diff < 4.5) {
		salary += salary * 6 / 100;
	}
	else if (diff >= 4.5 && diff < 7.5) {
		salary += salary * 12 / 100;
	}
	else {
		salary += salary * 15 / 100;
	}
}

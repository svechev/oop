#include "qa.h"

void ManualQA::annual_raise()
{
	double diff = project_difficulty();
	if (diff >= 1 && diff < 1.5) {
		salary += salary * 5 / 100;
	}
	else if (diff >= 1.5 && diff < 3.5) {
		salary += salary * 10 / 100;
	}
	else {
		salary += salary * 15 / 100;
	}
}

void AutomationQA::annual_raise()
{
	double diff = project_difficulty();
	if (diff >= 1 && diff < 4.5) {
		salary += salary * 5 / 100;
	}
	else if (diff >= 4.5 && diff < 7.5) {
		salary += salary * 10 / 100;
	}
	else {
		salary += salary * 15 / 100;
	}
}

#include "manager.h"

void Manager::annual_raise()
{
	if (subworkers >= 1 && subworkers <= 10) {
		salary += salary * 6 / 100;
	}
	else if (subworkers >= 11 && subworkers <= 15) {
		salary += salary * 12 / 100;
	}
	else {
		salary += salary * 15 / 100;
	}
}

#include "yesnoquestion.h"

void YesNoQuestion::ask()
{
	std::cout << text << std::endl;
	char userAnswer[4];
	std::cin.getline(userAnswer, 4);
	if (!strcmp(userAnswer, "yes")) {
		answer = true;
	}
	else {
		answer = false;
	}
}

int YesNoQuestion::grade()
{
	if (answer == correctAnswer) {
		return points;
	}
	return 0;
}

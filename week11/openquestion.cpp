#include "openquestion.h"

void OpenQuestion::ask()
{
	std::cout << text << std::endl;
	std::cin >> answer;
}

int OpenQuestion::grade()
{
	if (!answer.length()) {
		return 0;
	}
	int percentage;
	std::cin >> percentage;
	double score = points * percentage / 100;
	return round(score);
}

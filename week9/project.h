#ifndef _PROJECT_H
#define _PROJECT_H
#include <string>

class Project {
private:
	std::string name;
	int difficulty;

public:
	Project(std::string _name, int diff);

	int get_diff();
};

#endif 
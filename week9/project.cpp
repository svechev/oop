#include "project.h"

Project::Project(std::string _name, int diff)
{
	name = _name;
	difficulty = diff;
}

int Project::get_diff()
{
	return difficulty;
}

#include "shorttask.h"

ShortTask::ShortTask(const std::string& description) : Task(description, 1)
{
	
}

Task* ShortTask::clone() const
{
	return new ShortTask(*this);
}

unsigned ShortTask::work(int time)
{
	if (time == 0) {
		std::cout << "Task incomplete." << std::endl;
		return 0;
	}
	progress = 1;
	return time - 1;
}

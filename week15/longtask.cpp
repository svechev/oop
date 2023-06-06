#include "longtask.h"

LongTask::LongTask(const std::string& description, unsigned size) : Task(description, size)
{
}

Task* LongTask::clone() const
{
	return new LongTask(*this);
}

unsigned LongTask::work(int time)
{
	if (size - progress * size >= time) {
		progress = 1;
		return size - time;
	}
	progress += size / time;
	std::cout << "Task not complete. Progress: " << progress * 100 << "%" << std::endl;
	return 0;
}

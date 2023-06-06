#include "task.h"

Task::Task(const std::string& description, unsigned size) : description(description),
	size(size)
{

}

unsigned Task::getSize() const
{
	return size;
}

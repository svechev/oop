#include "complextask.h"

void ComplexTask::free()
{
	for (int i = 0; i < taskCount; i++) {
		delete tasks[i];
	}
	delete[] tasks;
}

void ComplexTask::copyFrom(const Task** otherTasks, unsigned count)
{
	taskCount = count;
	this->tasks = new Task * [taskCount];
	for (int i = 0; i < taskCount; i++) {
		tasks[i] = otherTasks[i]->clone();
	}
}

ComplexTask::ComplexTask(const Task** tasks, unsigned count)
{
	copyFrom(tasks, count);
}

ComplexTask::ComplexTask(const ComplexTask& other)
{
	copyFrom(other.tasks, other.taskCount);
}

ComplexTask& ComplexTask::operator=(const ComplexTask& other)
{
	if (this != &other) {
		free();
		copyFrom(other.tasks, other.taskCount);
	}
	return *this;
}

ComplexTask::~ComplexTask()
{
	free();
}

unsigned ComplexTask::work(unsigned time)
{
	int sum = 0;
	for (int i = 0; i < taskCount; i++) {
		sum += tasks[i]->work(time);
		time -= tasks[i]->getSize();
		if (time <= 0) {
			return 0;
		}
	}
	if (time - sum < 0) {
		std::cout << "Tasks not completed." << std::endl;
		return 0;
	}
	return time - sum;
}

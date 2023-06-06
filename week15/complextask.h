#ifndef COMPLEX_TASK_H
#define COMPLEX_TASK_H
#include "task.h"

class ComplexTask {
protected:
	Task** tasks;
	unsigned taskCount;

	void free();
	void copyFrom(const Task** otherTasks, unsigned count);

public:
	ComplexTask(const Task** tasks, unsigned count);
	ComplexTask(const ComplexTask& other);
	ComplexTask& operator=(const ComplexTask& other);
	~ComplexTask();

	unsigned work(unsigned const time);
};

#endif

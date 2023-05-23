#ifndef TASK_H
#define TASK_H
#include <string>
#include <iostream>

class Task {
protected:
	std::string description;
	int size;
	int progress = 0;
	bool finished = false;
public:
	virtual int work(unsigned const hours) = 0;
};

#endif

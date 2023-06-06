#ifndef TASK_H
#define TASK_H
#include <string>
#include <iostream>

class Task {
protected:
	std::string description;
	unsigned size;
	double progress = 0;
	bool finished = false;
public:
	Task(const std::string& description, unsigned size);


	unsigned getSize() const;
	virtual unsigned work(int time) = 0;
	virtual Task* clone() const = 0;
};

#endif
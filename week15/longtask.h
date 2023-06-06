#ifndef LONG_TASK_H
#define LONG_TASK_H
#include "task.h"

class LongTask : public Task {
public:
	LongTask(const std::string& description, unsigned size);

	Task* clone() const override;
	unsigned work(int time) override;
};

#endif

#ifndef SHORT_TASK_H
#define SHORT_TASK_H
#include "task.h"

class ShortTask : public Task {
public:
	ShortTask(const std::string& _description);

	Task* clone() const override;
	unsigned work(int time) override;
};

#endif

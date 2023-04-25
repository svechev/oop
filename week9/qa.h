#ifndef _QA_H
#define _QA_H
#include "itspecialist.h"

class ManualQA : public ITSpecialist {
public:
	void annual_raise();
};

class AutomationQA : public ITSpecialist {
public:
	void annual_raise();
};

#endif

#ifndef OPENQUESTION_H
#define OPENQUESTION_H
#include "question.h"

class OpenQuestion : public Question {
protected:
	std::string answer;
public:
	OpenQuestion(std::string _text, int _points) :
		Question(_text, _points) {};
	void ask() override;
	int grade() override;
};

#endif

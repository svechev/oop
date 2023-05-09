#ifndef YESNOQUESTION_H
#define YESNOQUESTION_H
#include "question.h"
#include <cstring>

class YesNoQuestion : public Question {
protected:
	bool answer;
	bool correctAnswer;
public:
	YesNoQuestion(std::string _text, int _points, bool _correctAnswer) :
		Question(_text, _points), correctAnswer(_correctAnswer) {};
	void ask() override;
	int grade() override;
};

#endif

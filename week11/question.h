#ifndef QUESTION_H
#define QUESTION_H
#include <iostream>
#include <string>

class Question {
protected:
	std::string text;
	int points;

public:
	Question(std::string _text, int _points) : text(_text), points(_points) {};
	virtual void ask() = 0;
	virtual int grade() = 0;
};

#endif

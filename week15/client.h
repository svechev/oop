#ifndef CLIENT_H
#define CLIENT_H
#include "person.h"

enum Discount {
	none, elderly, school, student
};

class Client : public Person {
protected:
	double balance;
	enum discount;
public:
	void buyTicket(Screening* screening);
	void addMoney(double money);
};

#endif

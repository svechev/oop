#ifndef VENDING_H
#define VENDING_H

struct Products {
	int sweets;
	int salty;
	int drinks;
};

class VendingMachine {
	Products products;
	char* id;
	char* address;
	char* msg[3];
};

class VendingController {
	VendingMachine* machines;
	int num_machines;
	int capacity;
};

#endif

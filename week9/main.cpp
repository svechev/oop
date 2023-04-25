#include "cat.h"
#include "dog.h"


int main() {
	Cat c1("mewo", "black"), c2("toast", "orange");
	Dog d1("peter barker", "chihuahua"), d2("sweetpie", "bulldog");
	Animal* arr[4];
	arr[0] = &c1;
	arr[1] = &d1;
	arr[2] = &c2;
	arr[3] = &d2;
	for (int i = 0; i < 4; i++) {
		arr[i]->talk();
	}

	return 0;
}
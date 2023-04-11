#include "sorted.h"

int main() {
	Sorted<int> arr1;
	int num1 = 2, num2 = 3, num3 = 1;
	arr1.add(num1);
	arr1.add(num2);
	arr1.add(num3);
	arr1.print();
	Sorted<int> arr2 = arr1;
	arr2.remove(num2);
	arr2.print();
	return 0;
}
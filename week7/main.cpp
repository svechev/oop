#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "user.h"
#include "event.h"
#include <cstring>

void writeToFile(std::fstream& file, char name[32], char pass[16]) {
	file << name << " " << pass << "\n";
}

int main() {
	std::fstream file("user.txt", std::ios::app);
	if (!file.is_open()) {
		std::cout << "File not open!";
		return -1;
	}
	char name[32], password[16];
	std::cin.getline(name, 32, ' ');
	std::cin.getline(password, 16);
	writeToFile(file, name, password);
	file.close();
	return 0;
}
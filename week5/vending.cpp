#define _CRT_SECURE_NO_WARNINGS
#include "vending.h"
int ID = 0, capacityWarnMsgs = 5;
const int INITIAL_CAPACITY = 10, WARNING_MSG_LEN = 32;

void Inventory::changeSalty(int quantity)
{
	salty += quantity;
}

void Inventory::changeSweets(int quantity)
{
	sweet += quantity;
}

void Inventory::changeDrinks(int quantity)
{
	drinks += quantity;
}

inline void Inventory::print() 
{
	std::cout << "salty: " << salty << ", sweet: " << sweet << ", drinks: " << drinks << std::endl;
}

VendingMachine::VendingMachine()
{
	id = ID;
	ID++;
	this->address = new char[INITIAL_CAPACITY];
	warningMessages = new char* [capacityWarnMsgs];
	inventory = { 0, 0, 0 };
	capacity = INITIAL_CAPACITY;
	numWarningMsgs = 0;
}

VendingMachine::VendingMachine(char* address, Inventory inventory)
{
	id = ID;
	ID++;
	this->inventory = inventory;
	capacity = INITIAL_CAPACITY;

	this->address = new char[strlen(address) + 1];
	strcpy(this->address, address);

	numWarningMsgs = 0;
	warningMessages = new char* [capacityWarnMsgs];
}

VendingMachine::VendingMachine(VendingMachine const& other)
{
	id = ID;
	ID++;
	inventory = other.inventory;
	capacity = other.capacity;
	
	this->address = new char[strlen(address) + 1];
	strcpy(this->address, address);

	numWarningMsgs = other.numWarningMsgs;

	warningMessages = new char*[capacityWarnMsgs];
	for (int i = 0; i < other.numWarningMsgs; i++) {
		warningMessages[i] = new char[WARNING_MSG_LEN];
		strcpy(warningMessages[i], other.warningMessages[i]);
	}
}

VendingMachine::VendingMachine(VendingMachine&& other)  
{	
	id = ID;
	ID++;
	inventory = other.inventory;
	capacity = other.capacity;
	address = other.address;
	warningMessages = other.warningMessages;
	numWarningMsgs = other.numWarningMsgs;


	other.id = 0;
	other.inventory = { 0, 0, 0 };
	other.capacity = 0;
	other.address = nullptr;
	other.warningMessages = nullptr;
	other.numWarningMsgs = 0;
}

VendingMachine& VendingMachine::operator=(VendingMachine const& other)
{
	if (this != &other) {
		inventory = other.inventory;
		capacity = other.capacity;
		numWarningMsgs = other.numWarningMsgs;

		strcpy(address, other.address);

		for (int i = 0; i < other.numWarningMsgs; i++) {
			strcpy(warningMessages[i], other.warningMessages[i]);
		}
	}
	return *this;
}

VendingMachine::~VendingMachine()
{
	delete[] address;
	for (int i = 0; i < numWarningMsgs; i++) {
		delete[] warningMessages[i];
	}
	delete[] warningMessages;
}

//no time for these :(

void VendingController::addVendingMachine(VendingMachine machine)
{

}

void VendingController::getAddressOfMachine(int machineID)
{
}

void VendingController::getInventoryOfMachine(int machineID)
{
}

void VendingController::sellProductInMachine(int machineID, char* product)
{
}

void VendingController::restockProductInMachine(int machineID, char* product)
{
}

void VendingController::seeWarningMsgForMachine(int machineID)
{
}

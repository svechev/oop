#include "set.h"

// направих го без помощ така че сигурно има грешки:DDD 


Set::Set() {
	this->capacity = 10;
	this->num_elements = 0;
}

Set::~Set() {
	delete [] this->elements;
}

Set::Set(Set const& other_set) {
	this->capacity = other_set.capacity;
	this->num_elements = other_set.num_elements;
	this->copy(other_set.elements);
}

Set& Set::operator=(Set const& other_set) {
	if (this != &other_set) {
		this->capacity = other_set.capacity;
		this->num_elements = other_set.num_elements;
		this->copy(other_set.elements);
	}
	return *this;
}

void Set::resize() {
	this->capacity *= 2;
	int* copy_elements = new int[this->capacity];
	for (int i = 0; i < num_elements; i++) {
		copy_elements[i] = this->elements[i];
	}
	delete[] this->elements;
	this->elements = copy_elements;
}

bool Set::add_element(int const element) {
	bool exist = false;
	for (int i = 0; i < num_elements; i++) {
		if (elements[i] == element) exist = true;
	}
	if (!exist) {
		if (num_elements == capacity) this->resize();
		num_elements++;
		elements[num_elements - 1] = element;
	}
	return !exist;
}

bool Set::delete_element(int const element) {
	bool exists = false;
	for (int i = 0; i < num_elements; i++) {
		if (elements[i] == element) {
			exists = true;
			for (int j = i; j < num_elements - 1; j++) {
				elements[j] = elements[j + 1];
			}
		}
	}
	return exists;
}

void Set::print() {
	std::cout << "(";
	for (int i = 0; i < num_elements-1; i++) {
		std::cout << this->elements[i] << ", ";
	}
	std::cout << this->elements[num_elements - 1] << ")" << std::endl;
}

void Set::set_union(Set const& other) {
	int* union_set = new int[this->capacity + other.num_elements];
	while (this->capacity < other.num_elements + this->num_elements) resize();
	for (int i = 0; i < num_elements; i++) {
		union_set[i] = this->elements[i];
	}
	for (int i = 0; i < other.num_elements; i++) {
		union_set[i + num_elements] = other.elements[i];
	}
	this->copy(union_set);
	for (int i = 0; i < other.num_elements; i++) {
		delete_element(other.elements[i]);
		add_element(other.elements[i]);
	}
	delete[] union_set;
}

void Set::set_intersection(Set const& other) {
	for (int i = 0; i < num_elements; i++) {
		bool intersect = false;
		for (int j = 0; j < other.num_elements; j++) {
			if (elements[i] == other.elements[j]) intersect = true; break;
		}
		if (!intersect) this->delete_element(elements[i]);
	}
}

void Set::copy(int* element_set) {
	if (this->elements != nullptr) {
		delete[] this->elements;
	}
	this->elements = new int[capacity];
	for (int i = 0; i < num_elements; i++) {
		this->elements[i] = element_set[i];
	}
}
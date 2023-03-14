#include "set.h"
const int INITIAL_CAPACITY = 10;

Set::Set() {
	this->capacity = INITIAL_CAPACITY;
	this->num_elements = 0;
	this->elements = new int[this->capacity];
}

Set::~Set() {
	delete [] this->elements;
}

void Set::copy(int const* elements, int capacity, int num_elements) {
	this->capacity = capacity;
	this->num_elements = num_elements;

	if (this->elements != nullptr) {
		delete[] this->elements;
	}
	this->elements = new int[this->capacity];
	for (int i = 0; i < this->num_elements; i++) {
		this->elements[i] = elements[i];
	}
}

Set::Set(Set const& other_set) {
	this->copy(other_set.elements, other_set.capacity, other_set.num_elements);
}

Set& Set::operator=(Set const& other_set) {
	if (this != &other_set) {
		this->copy(other_set.elements, other_set.capacity, other_set.num_elements);
	}
	return *this;
}

Set::Set(Set && other_set) {
	this->elements = other_set.elements;
	this->num_elements = other_set.num_elements;
	this->capacity = other_set.capacity;
	other_set.elements = nullptr;
	other_set.num_elements = 0;
	other_set.capacity = 0;
}

Set& Set::operator=(Set && other_set) {
	if (this != &other_set) {
		this->elements = other_set.elements;
		this->num_elements = other_set.num_elements;
		this->capacity = other_set.capacity;
		other_set.elements = nullptr;
		other_set.num_elements = 0;
		other_set.capacity = 0;
	}
	return *this;
}

Set& Set::operator+=(Set const& other) {
	this->set_union(other);
	return *this;
}

Set& Set::operator+(Set const& other) {
	this->set_union(other);
	return *this;
}

Set& Set::operator*(int num) {
	for (int i = 0; i < this->num_elements; i++) {
		this->elements[i] *= num;
	}
	return *this;
}

Set& Set::operator+(int num) {
	for (int i = 0; i < this->num_elements; i++) {
		this->elements[i] += num;
	}
	return *this;
}

Set& Set::operator/=(Set const& other) {
	this->set_union(other);
	for (int i = 0; i < other.num_elements; i++) {
		this->delete_element(other.elements[i]);
	}
	return *this;
}

Set& Set::operator/(Set const& other) {
	this->set_union(other);
	for (int i = 0; i < other.num_elements; i++) {
		this->delete_element(other.elements[i]);
	}
	return *this;
}


Set& Set::operator%=(Set const& other) {
	this->set_intersection(other);
	return *this;
}

Set& Set::operator%(Set const& other) {
	this->set_intersection(other);
	return *this;
}

bool Set::operator==(Set const& other) {
	if (this->num_elements != other.num_elements) return false;
	for (int i = 0; i < this->num_elements; i++) {
		int j = 0;
		while (j < other.num_elements && other.elements[j] != this->elements[i]) {
			j++;
		}
		if (j == other.num_elements) return false;
	}
	return true;
}

bool Set::operator!=(Set const& other) {
	return !(*this == other);
}

bool Set::operator>=(Set const& other) {
	if (this->num_elements < other.num_elements) return false;
	for (int i = 0; i < this->num_elements; i++) {
		int j = 0;
		while (j < other.num_elements && other.elements[j] != this->elements[i]) {
			j++;
		}
		if (j == other.num_elements) return false;
	}
	return true;
}

bool Set::operator<=(Set const& other) {
	if (this->num_elements > other.num_elements) return false;
	for (int i = 0; i < this->num_elements; i++) {
		int j = 0;
		while (j < other.num_elements && other.elements[j] != this->elements[i]) {
			j++;
		}
		if (j == other.num_elements) return false;
	}
	return true;
}

bool Set::operator<(Set const& other) {
	if (this->num_elements >= other.num_elements) return false;
	for (int i = 0; i < this->num_elements; i++) {
		int j = 0;
		while (j < other.num_elements && other.elements[j] != this->elements[i]) {
			j++;
		}
		if (j == other.num_elements) return false;
	}
	return true;
}

bool Set::operator>(Set const& other) {
	if (this->num_elements <= other.num_elements) return false;
	for (int i = 0; i < this->num_elements; i++) {
		int j = 0;
		while (j < other.num_elements && other.elements[j] != this->elements[i]) {
			j++;
		}
		if (j == other.num_elements) return false;
	}
	return true;
}

bool Set::operator[](int num) {
	for (int i = 0; i < this->num_elements; i++) {
		if (this->elements[i] == num) return true;
	}
	return false;
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
	if (this->num_elements == this->capacity) {
		this->resize();
	}

	for (int i = 0; i < this->num_elements; i++) {
		if (this->elements[i] == element) {
			return false;
		}
	}
	this->elements[this->num_elements] = element;
	this->num_elements++;
	return true;
}

bool Set::delete_element(int const element) {
	for (int i = 0; i < num_elements; i++) {
		if (elements[i] == element) {
			for (int j = i; j < num_elements - 1; j++) {
				elements[j] = elements[j + 1];
			}
			this->num_elements--;
			return true;
		}
	}
	return false;
}

void Set::print() {
	std::cout << "(";
	for (int i = 0; i < num_elements-1; i++) {
		std::cout << this->elements[i] << ", ";
	}
	std::cout << this->elements[num_elements - 1] << ")" << std::endl;
}

void Set::set_union(Set const& other) {
	for (int i = 0; i < other.num_elements; i++) {
		add_element(other.elements[i]);
	}
}

void Set::set_intersection(Set const& other) {
	for (int i = 0; i < num_elements; i++) {
		int j = 0;
		while (j < other.num_elements && elements[i] != other.elements[i]) {
			j++;
		}
		if (j == other.num_elements) {
			this->delete_element(elements[i]);
			i--;
		}
	}
}


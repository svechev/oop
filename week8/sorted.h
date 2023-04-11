#ifndef _SORTED_H
#define _SORTED_H
#include <iostream>
const int INITIAL_CAPACITY = 16;

template <typename T>
class Sorted {
private:
	T* arr;
	int capacity = INITIAL_CAPACITY;
	int numElements = 0;


	void sort();
	void resize();
	void copy(const Sorted& other);
	void del();

public:
	Sorted();
	~Sorted();
	
	Sorted(const Sorted& other);
	Sorted& operator=(const Sorted& other);

	Sorted(Sorted&& other);
	Sorted& operator=(Sorted&& other);


	void add(T& elem);
	bool remove(T& elem);
	void print() const;
};



template<typename T>
void Sorted<T>::sort()
{
	int index = numElements - 1;
	while (index > 0 && arr[index] < arr[index - 1]) {
		T temp = arr[index];
		arr[index] = arr[index - 1];
		arr[index - 1] = temp;
		index--;
	}
}

template<typename T>
void Sorted<T>::resize()
{
	capacity *= 2;
	T* new_arr = new T[capacity];
	for (int i = 0; i < numElements; i++) {
		new_arr[i] = arr[i];
	}
	delete[] arr;
	arr = new_arr;
}

template<typename T>
void Sorted<T>::copy(const Sorted& other)
{
	capacity = other.capacity;
	numElements = other.numElements;

	arr = new T[capacity];
	for (int i = 0; i < numElements; i++) {
		arr[i] = other.arr[i];
	}
}

template<typename T>
void Sorted<T>::del()
{
	delete[] arr;
}

template<typename T>
Sorted<T>::Sorted()
{
	capacity = INITIAL_CAPACITY;
	arr = new T[capacity];
}

template<typename T>
Sorted<T>::~Sorted()
{
	del();
}

template<typename T>
Sorted<T>::Sorted(const Sorted& other)
{
	copy(other);
}

template<typename T>
Sorted<T>& Sorted<T>::operator=(const Sorted& other)
{
	if (this != &other) {
		del();
		copy(other);
	}

	return *this;
}

template<typename T>
Sorted<T>::Sorted(Sorted&& other)
{
	capacity = other.capacity;
	other.capacity = 0;

	numElements = other.numElements;
	other.numElements = 0;

	arr = other.arr;
	other.arr = nullptr;
}

template<typename T>
Sorted<T>& Sorted<T>::operator=(Sorted&& other)
{
	if (this != &other) {
		capacity = other.capacity;
		other.capacity = 0;

		numElements = other.numElements;
		other.numElements = 0;

		arr = other.arr;
		other.arr = nullptr;
	}

	return *this;
}

template<typename T>
void Sorted<T>::add(T& elem)
{
	if (numElements == capacity) {
		resize();
	}
	arr[numElements] = elem;
	numElements++;
	sort();
}

template<typename T>
bool Sorted<T>::remove(T& elem)
{
	for (int i = 0; i < numElements; i++) {
		if (arr[i] == elem) {
			int swapIndex = i;
			while (swapIndex < numElements - 1) {
				arr[swapIndex] = arr[swapIndex + 1];
				swapIndex++;
			}
			numElements--;
			return true;
		}
	}
	return false;
}

template<typename T>
void Sorted<T>::print() const
{
	std::cout << "(";
	for (int i = 0; i < numElements - 1; i++) {
		std::cout << arr[i] << ", ";
	}
	std::cout << arr[numElements - 1] << " )" << std::endl;
}

#endif
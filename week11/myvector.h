#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
#include <cassert>

const int INITIAL_CAPACITY = 16;

template <typename T>
class MyVector {
private:
	T* arr;
	int numElements = 0;
	int capacity;

	void free();
	void copyFrom(const MyVector& other);
	void move(MyVector&& other);
	void resize();

public:
	MyVector();
	~MyVector();

	MyVector(const MyVector& other);
	MyVector& operator=(const MyVector& other);

	MyVector(MyVector&& other);
	MyVector& operator=(MyVector&& other);

	void addElement(T element);
	T operator[](unsigned index) const;

	template <typename R>
	void apply(R(*func)(T&));
};


#endif

template<typename T>
void MyVector<T>::free()
{
	delete[] arr;
}

template<typename T>
void MyVector<T>::copyFrom(const MyVector& other)
{
	capacity = other.capacity;
	numElements = other.numElements;

	arr = new T[capacity];
	for (int i = 0; i < numElements; ++i) {
		arr[i] = other.arr[i];
	}
}

template<typename T>
void MyVector<T>::move(MyVector&& other)
{
	capacity = other.capacity;
	numElements = other.numElements;

	arr = other.arr;
	other.arr = nullptr;
}

template<typename T>
void MyVector<T>::resize()
{
	T* newArr = new T[capacity * 2];
	for (int i = 0; i < numElements; ++i) {
		newArr[i] = arr[i];
	}
	free();
	arr = newArr;
	capacity *= 2;
}

template<typename T>
MyVector<T>::MyVector()
{
	capacity = INITIAL_CAPACITY;
	arr = new T[capacity];
}

template<typename T>
MyVector<T>::~MyVector()
{
	free();
}

template<typename T>
MyVector<T>::MyVector(const MyVector& other)
{
	copyFrom(other);
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
MyVector<T>::MyVector(MyVector&& other)
{
	move(std::move(other));
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other)
{
	if (this != &other) {
		free();
		move(std::move(other));
	}

	return *this;
}

template<typename T>
void MyVector<T>::addElement(T element)
{
	if (numElements == capacity) {
		resize();
	}
	arr[numElements] = element;
	numElements++;
}

template<typename T>
T MyVector<T>::operator[](unsigned index) const
{
	assert(index < numElements);
	return arr[index];
}

template<typename T>
template<typename R>
void MyVector<T>::apply(R(*func)(T&))
{
	for (int i = 0; i < numElements; ++i) {
		func(arr[i]);
	}
}

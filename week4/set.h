#ifndef SET_H
#define SET_H
#include <iostream>

class Set {
    int* elements;

    int num_elements;
    int capacity;

    void resize();
    void copy(int const* element_set, int capacity, int num_elements);

public:
    Set();
    Set(Set const& other_set);
    Set& operator=(Set const& other_set);
    Set(Set && other_set);
    Set& operator=(Set && other_set);
    ~Set();

    Set& operator+(Set const& other);
    Set& operator+=(Set const& other);
    Set& operator+(int num);
    Set& operator*(int num);
    Set& operator/(Set const& other);
    Set& operator/=(Set const& other);
    Set& operator%(Set const& other);
    Set& operator%=(Set const& other);
    bool operator==(Set const& other);
    bool operator!=(Set const& other);
    bool operator>=(Set const& other);
    bool operator<=(Set const& other);
    bool operator>(Set const& other);
    bool operator<(Set const& other);
    bool operator[](int num);

    bool add_element(int const element);
    bool delete_element(int const element);
    void set_union(Set const& other);
    void set_intersection(Set const& other);
    void print();
};

#endif
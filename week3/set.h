#ifndef SET_H
#define SET_H
#include <iostream>

class Set {
    int* elements;

    int num_elements;
    int capacity;

    void resize();
    void copy(int* element_set);

public:
    Set();
    Set(Set const& other);
    Set& operator=(Set const& other);
    ~Set();

    bool add_element(int const element);

    bool delete_element(int const element);

    void set_union(Set const& other);

    void set_intersection(Set const& other);

    void print();
};

#endif
#pragma once
#pragma once
#include <stdexcept>

class DynamicArray {
private:
    int size = 0;
    int capacity;
    int* data;

    void resize();

public:
    DynamicArray();
    ~DynamicArray(); //destructor for freeing memory
    void add(int value);
    void remove(int index);
    int pop();
    int get(int index);
    void insert(int index, int value);
    int getSize();
};

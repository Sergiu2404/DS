#include "DynamicArray.h"

DynamicArray::DynamicArray() : size{ 0 }, capacity{ 4 } {
    data = new int[capacity];
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::resize() {
    int* newData = new int[2 * capacity];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity *= 2;
}

void DynamicArray::add(int value) {
    if (size == capacity) {
        resize();
    }

    data[size] = value;
    size++;
}

void DynamicArray::remove(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index exceeds array bounds");
    }

    for (int i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }

    size--;
}

int DynamicArray::pop() {
    if (size == 0) {
        throw std::out_of_range("Array is already empty, nothing to pop");
    }

    int removedElement = data[size - 1];
    size--;
    return removedElement;
}

int DynamicArray::get(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index exceeds array bounds");
    }

    return data[index];
}

void DynamicArray::insert(int index, int value) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Index exceeds array bounds");
    }

    if (size == capacity) {
        resize();
    }

    for (int i = size; i > index; i--) {
        data[i] = data[i - 1];
    }

    data[index] = value;
    size++;
}

int DynamicArray::getSize()
{
    return this->size;
}

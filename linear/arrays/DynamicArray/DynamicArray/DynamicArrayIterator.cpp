#include "DynamicArrayIterator.h"
#include <stdexcept>

DynamicArrayIterator::DynamicArrayIterator(const DynamicArray& arr) : array(arr), currentIndex(0) {}

void DynamicArrayIterator::first() {
    currentIndex = 0;
}

void DynamicArrayIterator::next() {
    if (!valid()) {
        throw std::out_of_range("Iterator out of range");
    }
    currentIndex++;
}

bool DynamicArrayIterator::valid() const {
    return currentIndex < array.size;
}

int DynamicArrayIterator::getCurrent() const {
    if (!valid()) {
        throw std::out_of_range("Current index is out of range");
    }
    return array.data[currentIndex];
}

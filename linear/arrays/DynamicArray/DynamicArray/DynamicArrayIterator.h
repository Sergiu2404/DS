#pragma once
#include "DynamicArray.h"

class DynamicArrayIterator {
    friend class DynamicArray;

private:
    const DynamicArray& array;
    int currentIndex;

    DynamicArrayIterator(const DynamicArray& arr);

public:
    void first();
    void next();
    bool valid() const;
    int getCurrent() const;
};

#include <iostream>
#include "DynamicArray.h";

using namespace std;

int main()
{
    DynamicArray arr;
    arr.add(1);
    arr.add(2);
    arr.insert(1, 3);
    arr.remove(0);

    for (int i = 0; i < arr.getSize(); i++) {
        std::cout << arr.get(i) << " ";
    }

    return 0;
}
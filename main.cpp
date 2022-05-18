#include "header.h"

int main() {

    int size;

    std::cin >> size;

    int *arr1 = new int[size], *arr2 = new int[size], *arr3 = new int[size], *arr4 = new int[size];

    makeArray(arr1, size);

    copyArrays(arr1, arr2, arr3, arr4, size);

    printArray(arr1, 0, size);
    printArray(arr2, 0, size);
    printArray(arr3, 0, size);
    printArray(arr4, 0, size);

}

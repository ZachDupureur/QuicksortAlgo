//
// Created by zach on 5/14/22.
//

#include "header.h"


void makeArray(int arr[], int size) { // Basic function to fill array with random numbers between 0 and 999
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
}

void swap(int* x, int* y) { // Quick swap of integers
    int z = *x;
    *x = *y;
    *y = z;
}


void quickSort(int arr[], int min, int max) { // Standard quicksort call, uses full array then both halves of original
    if (min < max) {

        int partNum = partitionMedian(arr, min, max);

        quickSort(arr, min, partNum - 1);
        quickSort(arr, partNum + 1, max);
    }
}

void printArray(int arr[], int size) { // Function to print an array. Debug purposes
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int partitionMin(int *arr, int min, int max) {
    int pivotNum = arr[min];
    int j = min + 1;

    for (int i = min + 1; i<= max; i++) {

        if (arr[i] < pivotNum) {
            if (i != j) {
                swap(&arr[j], &arr[i]);
            }
            j++;
        }
    }

    swap(&arr[min], &arr[j-1]);

    return j - 1;
}

int partitionMedian(int *arr, int min, int max) {

    int pivotIndex = medianOfThree(arr, min, max);
    int pivotNum = arr[pivotIndex];

    int j = min;
    int h = max;

    while (j < h) {

        while (arr[j] <= pivotNum) {
            j++;
        }
        while (arr[h] > pivotNum) {
            h--;
        }
        if (j < h && j != h) {
            swap(&arr[j], &arr[h]);
        }
    }

    swap(&arr[pivotIndex + 1], &arr[pivotIndex]);
    return h;

}

int medianOfThree(int arr[], int min, int max) {
    int mid = (min + max) / 2;

    if (arr[max] < arr[min]) {
        swap(&arr[min], &arr[max]);
    }

    if (arr[mid] < arr[min]) {
        swap(&arr[mid], &arr[min]);
    }

    if (arr[max] < arr[mid]) {
        swap(&arr[max], &arr[mid]);
    }

    return mid;

}

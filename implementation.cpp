//
// Created by Zach Dupureur on 5/14/22.
//

#include "header.h"


void makeArray(int arr[], int size) { // Basic function to fill array with random numbers between 0 and 999
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
}

void copyArrays(int orgArr[], int arr1[], int arr2[], int arr3[], int size) {
    for (int i = 0; i < size; i++) {
        arr1[i] = arr2[i] = arr3[i] = orgArr[i];
    }
}

void swap(int* x, int* y) { // Quick swap of integers
    int z = *x;
    *x = *y;
    *y = z;
}



void quickSortMin(int *arr, int size) { // Helper functions to call quicksort with proper size
    quickSortMin(arr, 0, size - 1);
}

void quickSortMedian(int arr[], int size) {
    quickSortMedian(arr, 0, size - 1);
}


void quickSortMin(int arr[], int min, int max) { // Standard quicksort call, uses full array then both halves of original
    if (min < max) {

            int partNum = partitionMedian(arr, min, max);

            quickSortMin(arr, min, partNum - 1);
            quickSortMin(arr, partNum + 1, max);
    }
}

void quickSortMedian(int arr[], int min, int max) { // Standard quicksort call, uses full array then both halves of original
    if (min < max) {

        int partNum = partitionMedian(arr, min, max);

        quickSortMedian(arr, min, partNum - 1);
        quickSortMedian(arr, partNum + 1, max);
    }
}


void printArray(int arr[], int min, int size) { // Function to print an array. Debug purposes
    for (int i = min; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int partitionMin(int *arr, int min, int max) { // Partitions array using min number as pivot
    int pivotNum = arr[min];
    int j = min + 1;

    for (int i = min + 1; i <= max; i++) {

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
    int pivotIndex = medianOfThree(arr, min, max); // Getting Median and swapping positions
    int pivot = arr[pivotIndex];
    int left = min + 1;
    int right = max - 1;
    while (right > left) {
        while (left <= right && arr[left] <= pivot) {
            left++;
        }
        while (left <= right && arr[right] > pivot) {
            right--;
        }
        if (right > left) {
            swap(&arr[left], &arr[right]);
        }
    }

    while (right > min && arr[right] >= pivot) {
        right--;
    }
    if (pivot > arr[right]) {
        swap(&arr[right], &arr[pivotIndex]);
        return right;
    }

    else {
        return min;
    }
}


int medianOfThree(int arr[], int min, int max){
    int mid;
    if ((min + max) % 2 == 0) {
        mid = (min + max) / 2;
    }
    else {
        mid = (min + (max - min)) / 2 ;
    }

    // Swapping of three integers so in order
    if (arr[mid] < arr[min]) {
        swap(&arr[mid], &arr[min]);
    }
    if (arr[max] < arr[min]) {
        swap(&arr[max], &arr[min]);
    }
    if (arr[max] < arr[mid]) {
        swap(&arr[max], &arr[mid]);
    }

    swap(&arr[min], &arr[mid]);
    // Placing pivot in first position for sorting. I know this is probably not what you were looking for and would
    // want the pivot in place, but I spent two days on this algorithm and couldn't get it working properly. I decided
    // to move on.

    return min;

}


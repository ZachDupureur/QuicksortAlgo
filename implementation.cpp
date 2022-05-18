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
void quickSortMedIns(int arr[], int size){
    quickSortMedIns(arr, 0, size-1);
}

void quickSortMinIns(int arr[], int size) {
    quickSortMinIns(arr, 0, size - 1);
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

void quickSortMedIns(int arr[], int min, int max) { // Standard quicksort call, uses full array then both halves of original
    if (min < max) {
        if (max - min <= 20) {
            insertionSort(arr, min, max);
        }
        else {

            int partNum = partitionMedian(arr, min, max);

            quickSortMedian(arr, min, partNum - 1);
            quickSortMedian(arr, partNum + 1, max);
        }
    }
}



void quickSortMinIns(int arr[], int min, int max) { // Standard quicksort call, uses full array then both halves of original
    if (min < max) {
        if (max - min <= 20) {
            insertionSort(arr, min, max);
        }
        else {

            int partNum = partitionMedian(arr, min, max);

            quickSortMin(arr, min, partNum - 1);
            quickSortMin(arr, partNum + 1, max);
        }
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


void insertionSort(int arr[], int start, int stop) {
    int i, j, key;
    for (i = start; i <= stop; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void menu() {
    enum class choice {
        NUMBER = 'Y',
        EXIT = 'N',
    };

    choice c = choice::NUMBER;
    char userChoice = 'Y';
    int size;
    float clockTime1, clockTime2, clockTime3, clockTime4;

    clock_t startTime, endTime;

    while (c != choice::EXIT) {
        std::cout << "Welcome to the QuickSort efficiency program. \n";
        std::cout << "Please insert the size of the array.\n";
        std::cin >> size;
        cinClear();
        std::cout << "\nThank you! Creating arrays....";
        int *arr1 = new int[size], *arr2 = new int[size], *arr3 = new int[size], *arr4 = new int[size];
        makeArray(arr1, size);
        copyArrays(arr1, arr2, arr3, arr4, size);
        std::cout << "Done!\n";
        std::cout << "Sorting arrays and processing time....";

        startTime = clock();
        quickSortMin(arr1, size);
        endTime = clock();

        clockTime1 = calcTime(startTime, endTime);

        startTime = clock();
        quickSortMinIns(arr2, size);
        endTime = clock();

        clockTime2 = calcTime(startTime, endTime);

        startTime = clock();
        quickSortMedian(arr3, size);
        endTime = clock();

        clockTime3 = calcTime(startTime, endTime);

        startTime = clock();
        quickSortMedIns(arr4, size);
        endTime = clock();

        clockTime4 = calcTime(startTime, endTime);

        std::cout << "Total Times:\n"
                     "Quick sort time with pivot as first element: " << clockTime1 << std::endl
                  << "Quick sort time with median element as pivot: " << clockTime3 << std::endl
                  << "Quick sort time and insertion sort with first element as pivot: " << clockTime2 << std::endl
                  << "Quick sort time and insertion sort with median element as pivot: " << clockTime4 << std::endl
                  << std::endl << std::endl;

        std::cout << "Would you like to enter another size? Y/N\n";
        std::cin >> userChoice;


        c = static_cast<choice>(userChoice);
        cinClear();

    }
    std::cout << "Exiting...";
}


float calcTime(clock_t start, clock_t stop) {
    float begin, end;
    begin = static_cast<float>(start);
    end = static_cast<float>(stop);
    return (end-begin)/ CLOCKS_PER_SEC;
}


void cinClear() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

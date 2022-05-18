//
// Created by Zach Dupureur on 5/14/22.
//

#ifndef QUICKSORT_HEADER_H
#define QUICKSORT_HEADER_H

#include "iostream"
#include "iomanip"
#include "ctime"

void swap(int* x, int* y);

void quickSortMin(int arr[], int size);

void quickSortMin(int arr[], int min, int max);

void quickSortMedian(int arr[], int size);

void quickSortMedian(int arr[], int min, int max);


void makeArray(int arr[], int size);

void copyArrays(int orgArr[], int arr1[], int arr2[], int arr3[], int size);

void printArray(int arr[], int min,  int size);

int partitionMin(int *arr, int min, int max);

int partitionMedian(int *arr, int min, int max);

int medianOfThree(int arr[], int min, int max);

#endif //QUICKSORT_HEADER_H



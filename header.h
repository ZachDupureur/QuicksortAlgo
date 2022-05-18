//
// Created by Zach Dupureur on 5/14/22.
//

#ifndef QUICKSORT_HEADER_H
#define QUICKSORT_HEADER_H

#include "iostream"
#include "iomanip"
#include "ctime"
#include "limits"

void swap(int* x, int* y);

void quickSortMin(int arr[], int size);

void quickSortMin(int arr[], int min, int max);

void quickSortMedian(int arr[], int size);

void quickSortMedian(int arr[], int min, int max);

void quickSortMinIns(int arr[], int size);

void quickSortMinIns(int arr[], int min, int max);

void quickSortMedIns(int arr[], int size);

void quickSortMedIns(int arr[], int min, int max);

void insertionSort(int arr[],int start, int stop);

void makeArray(int arr[], int size);

void copyArrays(int orgArr[], int arr1[], int arr2[], int arr3[], int size);

void printArray(int arr[], int min,  int size);

int partitionMin(int *arr, int min, int max);

int partitionMedian(int *arr, int min, int max);

int medianOfThree(int arr[], int min, int max);

float calcTime(clock_t start, clock_t stop);

void menu();

void cinClear();

#endif //QUICKSORT_HEADER_H



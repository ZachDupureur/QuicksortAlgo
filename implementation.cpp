//
// Created by zach on 5/14/22.
//

#include "header.h"

void swap(int* x, int* y) {
    int z = *x;
    *x = *y;
    *y = z;
}


void quickSort(int arr[], int min, int max);
//
// Created by Zach Dupureur on 05/14/2022
//

// Program to show efficiency of Quick sort with first element as pivot and median
// of three as pivot. Also show efficiency of quicksort with insertion when array
// is less than 21 elements.

#include "header.h"

int main() {
    menu();
}


/* TESTING BELOW

Welcome to the QuickSort efficiency program.
Please insert the size of the array.
900

Thank you! Creating arrays....Done!
Sorting arrays and processing time....Total Times:
Quick sort time with pivot as first element: 0.000314
Quick sort time with median element as pivot: 0.000306
Quick sort time and insertion sort with first element as pivot: 0.000255
Quick sort time and insertion sort with median element as pivot: 0.000311


Would you like to enter another size? Y/N
Y
Welcome to the QuickSort efficiency program.
Please insert the size of the array.
100000

Thank you! Creating arrays....Done!
Sorting arrays and processing time....Total Times:
Quick sort time with pivot as first element: 0.035073
Quick sort time with median element as pivot: 0.030707
Quick sort time and insertion sort with first element as pivot: 0.030602
Quick sort time and insertion sort with median element as pivot: 0.031032


Would you like to enter another size? Y/N
N
Exiting...
Process finished with exit code 0
 */
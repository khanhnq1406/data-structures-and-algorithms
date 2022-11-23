#include <iostream>
#include "linearSearch.h"
#include "binarySearch.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "interchangeSort.h"
#include "bubbleSort.h"

#ifndef utils_h
#define utils_h
#include "utils.h"
#endif

using namespace std;

int main() {
    // Linear Search 
    int linearArray[] = {4,1,5,7,9};
    int linearSize = sizeof(linearArray) / sizeof(linearArray[0]);
    int linearPosition = linearSearch(linearArray, linearSize, 11);
    cout << "------ Linear Search ------" << endl << linearPosition << endl;

    // Binary Search
    int binaryArray[] = {1,3,5,7,9,11};
    int binarySize = sizeof(binaryArray) / sizeof(binaryArray[0]);
    int binaryPosition = binarySearch(binaryArray, binarySize, 11);
    cout << "------ Binary Search ------" << endl;
    cout << binaryPosition << endl;
    binaryPosition = binarySearch(binaryArray, binarySize, 3);
    cout << binaryPosition << endl;
    binaryPosition = binarySearch(binaryArray, binarySize, 15);
    cout << binaryPosition << endl;
    binaryPosition = binarySearch(binaryArray, binarySize, -5);
    cout << binaryPosition << endl;

    // ---------------- Sorting Algorithm ----------------
    const int SIZE_ARRAY = 10;
    
    // Selection sort
    int sortArray[SIZE_ARRAY];
    cout << "------ Selection sort ------" << endl;
    generateNumberArray(sortArray, SIZE_ARRAY);
    cout << "Before:" << endl;
    output(sortArray, SIZE_ARRAY);
    selectionSort(sortArray, SIZE_ARRAY);
    cout << "After: " << endl;
    output(sortArray, SIZE_ARRAY);

    // Insertion sort
    cout << "------ Insertion sort ------" << endl;
    int insertionArray[SIZE_ARRAY];
    generateNumberArray(insertionArray, SIZE_ARRAY);
    cout << "Before:" << endl;
    output(insertionArray, SIZE_ARRAY);
    selectionSort(insertionArray, SIZE_ARRAY);
    cout << "After: " << endl;
    output(insertionArray, SIZE_ARRAY);

    // Interchange sort
    cout << "------ Interchange sort ------" << endl;
    int interchangeArray[SIZE_ARRAY];
    generateNumberArray(interchangeArray, SIZE_ARRAY);
    cout << "Before:" << endl;
    output(interchangeArray, SIZE_ARRAY);
    interchangeSort(interchangeArray, SIZE_ARRAY);
    cout << "After: " << endl;
    output(interchangeArray, SIZE_ARRAY);

     // Bubble sort
    cout << "------ Bubble sort ------" << endl;
    int bubbleArray[SIZE_ARRAY];
    generateNumberArray(bubbleArray, SIZE_ARRAY);
    cout << "Before:" << endl;
    output(bubbleArray, SIZE_ARRAY);
    bubbleSort(bubbleArray, SIZE_ARRAY);
    cout << "After: " << endl;
    output(bubbleArray, SIZE_ARRAY);
    return 0;
}
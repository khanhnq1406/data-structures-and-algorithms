#include <iostream>
#include "linearSearch.h"
#include "binarySearch.h"
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

    return 0;
}
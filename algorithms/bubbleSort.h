#ifndef utils_h
#define utils_h
#include "utils.h"
#endif

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                swap(array[j], array[j+1]);
            }
        }
    }    
}
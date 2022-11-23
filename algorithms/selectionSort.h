#ifndef utils_h
#define utils_h
#include "utils.h"
#endif

void selectionSort(int array[], int size) {
    for (int i = 0; i < size; i++)
    {
        int minPosition = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minPosition])
            {
                minPosition = j;
            }
        }
        swap(array[i], array[minPosition]);
    }
}

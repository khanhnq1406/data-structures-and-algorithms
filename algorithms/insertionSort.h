void insertionSort(int array[], int size) {
	int current, position;
    for (int i = 1; i < size; i++) {
        /* Method 1
        current = array[i];
        position = i;
        for (int j = i - 1; j >= 0; j--) {
            if (current < array[j]) {
                array[position] = array[j];
                position--;
            }
            else {
                array[position] = current;
                break;
            }
        }
        */

        // Method 2
        current = array[i];
        position = i - 1;
        while (position >= 0 && array[position] > current)
        {
            array[position + 1] = array[position];
            position--;
        }
        array[position + 1] = current;
    }
}

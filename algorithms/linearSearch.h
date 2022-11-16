int linearSearch(int a[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (a[i] == value) {
            return i;
        }
    }
    return -1;
    
    // int position = 0;
    // while (position < size && a[position] != input) {
    //     position++;
    // }
    // if (position == size) {
    //     position = -1;
    // }
    // return position;
}

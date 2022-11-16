int binarySearch(int a[], int size, int value) {
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = (left + right)/2;
        if (a[mid] == value) {
            return mid;
        }
        else if (a[mid] > value) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;    
}
void generateNumberArray(int randArray[],int size) {
    const int MAX = 20;
    const int MIN = -5;
    for(int i=0; i < size; i++)
      randArray[i]= rand() % (MAX - MIN + 1) + MIN;  
}


void output(int array[], int size) {
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << "\t";
    }
    std::cout << std::endl;
}

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
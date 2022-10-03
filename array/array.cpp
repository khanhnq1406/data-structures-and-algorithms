#include "utils.cpp"
#define MAX 100
using namespace std;

struct Array
{
    int a[MAX];
    int n;
};
void inputArray(Array &arr) //Pass by reference
{
    interface::printFuncName("Input Array Fuction");
    cout << "Input n: ";
    cin >> arr.n;
    for (int i = 0; i < arr.n; i++)
    {
        cout << "Input a[" << i << "]: ";
        cin >> arr.a[i];
    }
}

void outputArray(const Array arr)
{
    interface::printFuncName("Output Array Fuction");
    for (int i = 0; i < arr.n; i++)
    {
        cout << "Out a[" << i << "]: " << arr.a[i] << endl;
    }
    
}

int findFirst(const Array arr, const int x)
{
    for (int i = 0; i < arr.n; i++)
    {
        if (arr.a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int findLast(const Array arr, const int x)
{
    for (int i = arr.n-1; i >= 0; i--)
    {
        if (arr.a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

bool addNumber(Array &arr, const int number_input, const int position)
{
    if (position < 0 || position > arr.n)
        return false;
    arr.n++;
    for (int i = arr.n; i >= position + 1; i--)
    {
        arr.a[i] = arr.a[i - 1];
    }
    arr.a[position] = number_input;
    return true;
}

bool deleteNumber(Array &arr, const int number_input, const int position)
{
    if (position < 0 || position >= arr.n)
        return false;
    for (int i = position; i < arr.n; i++)
    {
        arr.a[i] = arr.a[i + 1];
    }
    arr.n--;
    return true;
}
int main()
{
    int x, position;
    Array arr;
    cout << "WELCOME TO DATA STRUCTURE AND ALGORITHMS" << endl;
    // In/Out
    inputArray(arr);
    outputArray(arr);
    // Find first
    interface::printFuncName("Find first input number (x) in array");
    cout << "Input x: ";
    cin >> x;
    int first_pos = findFirst(arr, x);
    if (first_pos != -1)
        cout << "-> Position is " << first_pos << endl;
    else
        cout << "-> Cannot found" << endl;
    // Find last
    interface::printFuncName("Find last input number (x) in array");
    cout << "Input x: ";
    cin >> x;
    int last_pos = findLast(arr, x);
    if (last_pos != -1)
        cout << "-> Position is " << last_pos << endl;
    else
        cout << "-> Cannot found" << endl;
    // Add number
    interface::printFuncName("Add number with index");
    cout << "Input number: ";
    cin >> x;
    cout << "Input position: ";
    cin >> position;
    if (addNumber(arr, x, position) == true)
        outputArray(arr);
    else
        cout << "-> ADD FAIL" << endl;
    // Delete
    interface::printFuncName("Delete number with index");
    cout << "Input position: ";
    cin >> position;
    if (deleteNumber(arr, x, position) == true)
        outputArray(arr);
    else
        cout << "-> DELETE FAIL" << endl;
    return 0;
}
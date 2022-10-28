#include <iostream>
using namespace std;
#define MAX 100

struct Stack
{
    int data[MAX];
    int top;
};

void init(Stack &s) {
    s.top = -1;
}

void push(Stack &s, int input) {
    s.top++;
    s.data[s.top] = input;
}

int pop(Stack &s) {
    int output = s.data[s.top];
    s.top--;
    return output;
}

bool isEmpty(Stack s) {
    return s.top < 0;
}

bool isFull(Stack s) {
    return s.top == MAX;
}

void output (Stack s) {
    for (int i = 0; i <= s.top; i++)
    {
        cout << s.data[i] << "\t";
    }
    cout << endl;
}

int convertDecimalToBinary(int decNumber, int radix) {
    Stack binNumber;
    init(binNumber);
    while (decNumber != 0)
    {
        push(binNumber, decNumber%radix);
        decNumber /= radix;
    }
    while (!isEmpty(binNumber))
    {
        cout << pop(binNumber);
    }
    cout << endl;
    return 0;
}


int main() {
    Stack stack;
    init(stack);

    push(stack, 10);
    push(stack, 15);
    push(stack, 20);
    output(stack);

    cout << pop(stack) << endl;
    output(stack);

    convertDecimalToBinary(125, 2);

    return 0;
}

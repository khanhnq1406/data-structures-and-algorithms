#include <iostream>
#include <string.h>
#include <typeinfo>
using namespace std;
#define MAX 100

struct Stack
{
    char data[MAX][MAX];
    int top;
};

void init(Stack &s) {
    s.top = -1;
}

void push(Stack &s, char input[]) {
    s.top++;
    strcpy(s.data[s.top], input);
}

char* pop(Stack &s) {
    return s.data[s.top--];
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

int cal(char s[]) {
    // s = 5 10 + 2 * 3 / 
    Stack charStack;
    init(charStack);
    char *p = strtok(s, " ");
    int result = 0;
    while (p != NULL)
    {
        if (strcmp(p, "+") != 0 && strcmp(p, "-") != 0 && strcmp(p, "*") != 0 && strcmp(p, "/") != 0)
        {
            push(charStack, p);
        }
        else 
        {
            int numberB = atoi(pop(charStack));
            int numberA = atoi(pop(charStack));
            if (strcmp(p, "+") == 0)
                result = numberA + numberB;
            else if (strcmp(p, "-") == 0)
                result = numberA - numberB;
            else if (strcmp(p, "*") == 0)
                result = numberA * numberB;
            else if (strcmp(p, "/") == 0)
                result = numberA / numberB;
            char tmp[MAX];
            sprintf(tmp, "%d", result);
            push(charStack, tmp);
        }
        // cout << p << endl;
        p = strtok(NULL, " ");
    }
    return result;
}


int main() {
    char s[] = "5 10 + 2 * 3 /";
    cout << "result: " << cal(s) << endl;
    return 0;
}

#include <iostream>
using namespace std;

struct StackLinkedList
{
    int data;
    StackLinkedList *next;
};

struct stack 
{
    StackLinkedList *head, *tail;
};
void init(stack *&stack) {
    stack->head = NULL;
    stack->tail = NULL;
}

StackLinkedList* createNode (int input) {
    StackLinkedList *newNode = new StackLinkedList;
    newNode->data = input;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty(stack *stack) {
    return stack->head == NULL;
}

void push(stack *&stack, int input) {
    StackLinkedList *newNode = createNode(input);
    StackLinkedList *temp = stack->head;
    if (isEmpty(stack))
        stack->head = stack->tail =  newNode;
    else {
        temp->next = newNode;
        stack->head =  newNode;
    }
}

int pop(stack *&stack) {
    if (stack->head != NULL) { 
        int poppedVal;
        if (stack->head != stack->tail) {
            StackLinkedList *prevLast = stack->tail;
            while (prevLast->next != stack->head)
            {
                prevLast = prevLast->next;
            }
            poppedVal = prevLast->data;
            prevLast->next = NULL;
            stack->head = prevLast;
            delete(prevLast->next);
        }
        else 
        {
            poppedVal = stack->head->data;
            stack->head = stack->tail = NULL;
        }
        return poppedVal;
    }
}

void output(stack *stack) {
    StackLinkedList *temp = stack->tail;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    stack *stack;
    init(stack);
    push(stack, 5);
    push(stack, 10);
    push(stack, 15);
    output(stack);
    pop(stack);
    output(stack);
    pop(stack);
    output(stack);
    pop(stack);
    output(stack);
    return 0;
}

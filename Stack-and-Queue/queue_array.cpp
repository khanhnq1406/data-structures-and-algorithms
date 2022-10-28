#include <iostream>
using namespace std;
#define MAX 100

struct Queue {
    int data[MAX];
    int front;
    int rear;
};

void init(Queue &queue) {
    queue.front = -1;
    queue.rear = -1;
}

bool isEmpty(Queue queue) {
    return queue.front == -1;
}

void enqueue(Queue &queue, int input) {
    if (isEmpty(queue)) {
        queue.front++;
        queue.rear++;
    }
    else {
        queue.rear++;
    }
    queue.data[queue.rear] = input;
}

int dequeue(Queue &queue) {
    int dequeuedVal;
    if (!isEmpty(queue)) {
        if (queue.front == queue.rear) {
            dequeuedVal = queue.data[queue.front];
            queue.front = queue.rear = -1;
        }
        else {
            dequeuedVal = queue.data[queue.front];
            queue.front++;
        }
        return dequeuedVal;
    }
}
void output (Queue queue) {
    for (int i = queue.front; i <= queue.rear && queue.rear != -1; i++)
    {
        cout << queue.data[i] << "\t";
    }
    cout << endl;
}

int main() {
    Queue queue;
    init(queue);
    enqueue(queue, 5);
    output(queue);
    enqueue(queue, 10);
    output(queue);
    enqueue(queue, 15);
    output(queue);
    dequeue(queue);
    output(queue);
    dequeue(queue);
    output(queue);
    dequeue(queue);
    output(queue);
    return 0;
}
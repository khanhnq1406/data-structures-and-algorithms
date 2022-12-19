#include <iostream>
using namespace std;

struct QueueLinkedList {
    int data;
    QueueLinkedList *next;
};

struct Queue {
    QueueLinkedList *front, *rear;
};

void init(Queue *&queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

QueueLinkedList *CreateNode (int input) {
    QueueLinkedList *newNode = new QueueLinkedList;
    newNode->data = input;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty(Queue *queue) {
    return queue->front == NULL;
}

void enqueue (Queue *&queue, int input) {
    QueueLinkedList *newNode = CreateNode(input);
    QueueLinkedList *temp = queue->rear;
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    }
    else {
        temp->next = newNode;
        queue->rear = newNode;
    }
}

void dequeue (Queue *&queue) {
    QueueLinkedList *temp = queue->front;
    if (!isEmpty(queue)) {
        queue->front = temp->next;
        temp->next = NULL;
        delete(temp);
    }
}

void display(Queue *queue) {
    QueueLinkedList *temp = queue->front;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    Queue *queue;
    init(queue);
    enqueue(queue, 1);

    display(queue);
    enqueue(queue, 2);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    dequeue(queue);
    display(queue);
    return 0;   
}
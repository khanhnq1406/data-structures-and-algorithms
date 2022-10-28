#include <iostream>
#define max 100
struct AQueue {
	int arr[max];
	int front;
	int rear;
};

void init (AQueue &q){
	q.front = -1;
	q.rear = -1;
}

bool isEmpty(AQueue q) {
	return (q.front == -1 && q.rear == -1);
}
bool isFull(AQueue q)
{
	return (q.rear - q.front == max - 1);
}
int deQueue (AQueue &q) {
	if (isEmpty(q)) return -1;
	q.front++;
	if (q.front > q.rear) init(q);
	return 0;
}

int peek (AQueue &q)
{
	int front_pos = q.front;
	for (int i = 0; i < q.front; i++)
	{
		q.arr[i] = q.arr[front_pos];
		front_pos++;
	}
	q.rear -= q.front;
	q.front = 0;
	return 0;
}
int enQueue (int input, AQueue &q)
{
	if (isFull(q)) return -1;
	if (isEmpty(q))
	{
		q.front = 0;
	}
	if (q.front > 0 && q.rear == max - 1)
	{
		peek(q);
	}
	q.rear++;
	q.arr[q.rear] = input;
}

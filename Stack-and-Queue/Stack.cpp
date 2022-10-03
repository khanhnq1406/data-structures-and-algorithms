#include <iostream>
#define max 100
struct AStack
{
	int arr[max];
	int top;
};

void init (AStack &s)
{
	s.top = -1;
}

bool isEmpty(AStack s)
{
	return (s.top == -1);
}

bool isFull(AStack s)
{
	return (s.top >= max - 1);
}

int push (int input, AStack &s)
{
	std::cout << "In push" << std::endl;
	if (isFull(s)) return -1;
	std::cout << "In push 2" << std::endl;
	s.top++;
	s.arr[s.top] = input;
	return 0;
}

int pop (AStack &s)
{
	if (isEmpty(s)) return -1;
	s.top--;
	return 0;
}

int main()
{
	AStack stack;
	int input;
	std::cin >> input;
	do 
	{
		push(input%2, stack);
		input /= 2;
	} while (input > 0);

	std::cout << stack.arr[0] << std::endl;
	return 0;
}

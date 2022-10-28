# Data Structures and Algorithms
This is my learning process of subject "Data Structures and Algorithms" and I will take notes here &#128221;
<br />Go to my handwritten notes, [click here!!!&#9997;](https://drive.google.com/file/d/1FvkHS3HBY2fd7C88WjnY6xoNpaCy45i6/view?usp=sharing)
## Table of contents
- [Array](#array)
- [Linked List](#linked-list)
- [Stack and Queue](#stack-and-queue)

## Array
### Array Definition
- The size or length of array is fixed.
- Memory cells organized consecutively in memory.
### Advantages of Arrays
- It allows random access to elements.
- As the array is of fixed size and stored in contiguous memory locations there is no memory shortage or overflow.
- Since the elements in the array are stored at contiguous memory locations it is easy to iterate in this data structure and unit time is required to access an element if the index is known.
### Disadvantages of Arrays
- Insertion and deletion operations are difficult in an array as elements are stored in contiguous memory locations and the shifting operations are costly.
- The number of elements that have to be stored in an array should be known in advance.
- Wastage of memory is the main problem in the array. If the array size is big the less allocation of memory leads to wastage of memory.
### Pass by reference
- Pass-by-reference means to pass the reference of an argument in the calling function to the corresponding formal parameter of the called function. The called function can modify the value of the argument by using its reference passed in.

## Linked List
### Linked List Definition
- A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. 
- The elements in a linked list are linked using pointers. 
- A linked list consists of nodes where each node contains a data field and a reference(link) to the next node in the list.
- The size of linked list depend on RAM.
### Advantages of Linked Lists
- Inserting a new element in an array of elements is expensive because a room has to be created for the new elements and to create a room existing elements have to be shifted. 
### Disadvantages of Linked Lists
- Random access is not allowed. We have to access elements sequentially starting from the first node. So we cannot do a binary search with linked lists. 
- Extra memory space for a pointer is required for each element of the list. 
- It takes a lot of time in traversing and changing the pointers.
### Types Of Linked List
#### 1. Singly Linked List
It is the simplest type of linked list in which ***every node contains some data and a pointer*** to the next node of the same data type. The node contains a pointer to the next node means that the node stores the address of the next node in the sequence. A single linked list allows the traversal of data only in one way. 
#### 2. Doubly Linked List
A doubly linked list or a two-way linked list is a more complex type of linked list that contains a pointer to the next as well as the previous node in sequence. Therefore, it contains three parts of data, a pointer to the next node, and a pointer to the previous node. This would enable us to traverse the list in the backward direction as well.
#### 3. Circular Linked List
A circular linked list is that in which the last node contains the pointer to the first node of the list. While traversing a circular linked list, we can begin at any node and traverse the list in any direction forward and backward until we reach the same node we started. Thus, a circular linked list has no beginning and no end. 

## Stack and Queue
### Stack
Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).
<br>A stack is an abstract data type that serves as a collection of elements, with two main operations:
- **Push**, which adds an element to the collection, and
- **Pop**, which removes the most recently added element that was not yet removed.

<img src ="https://upload.wikimedia.org/wikipedia/commons/thumb/e/e4/Lifo_stack.svg/350px-Lifo_stack.svg.png"></img><br>

### Queue 
A queue is defined as a linear data structure that is open at both ends and the operations are performed in First In First Out (FIFO) order. <br>

We define a queue to be a list in which all additions to the list are made at one end, and all deletions from the list are made at the other end.  The element which is first pushed into the order, the operation is first performed on that. <br>

There are two main operations: 
- enqueue − add (store) an item to the queue.
- dequeue − remove (access) an item from the queue.

<img src = "https://media.geeksforgeeks.org/wp-content/uploads/20220816162225/Queue.png"><br>


# Link
- [Linked List vs Array](https://www.geeksforgeeks.org/linked-list-vs-array/)
- [Types of Linked List](https://www.geeksforgeeks.org/types-of-linked-list/)
- [Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/)
- [Queue Data Structure](https://www.geeksforgeeks.org/queue-data-structure/)
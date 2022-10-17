#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void init(Node *&head, Node *&tail)
{
    head = NULL;
    tail = NULL;
}

Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

bool addFirst(Node *&head, Node *&tail, int value)
{
    Node *newNode = createNode(value);
    Node *temp = head;
    if (temp != NULL)
    {
        newNode->next = temp;
        temp->prev = newNode;
        head = newNode;
    }
    else
    {
        head = newNode;
        tail = newNode;
    }
    return true;
}

bool addLast(Node *&head, Node *&tail, int value)
{
    Node *newNode = createNode(value);
    Node *temp = tail;
    if (temp != NULL)
    {
        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;
    }
    else
    {
        tail = newNode;
        head = newNode;
    }
    return true;
}

bool addAfter(Node *&head, Node *&tail, int valuePointed, int newValue)
{
    Node *temp = head;
    if (temp != NULL)
    {
        while (temp != NULL && temp->data != valuePointed)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            Node *newNode = createNode(newValue);
            if (temp->next != NULL)
            {
                newNode->next = temp->next;
                temp->next->prev = newNode;
                temp->next = newNode;
                newNode->prev = temp;
            }
            else 
            {
                addLast(head, tail, newValue);
            }
            return true;
        }
        else
        {
            cout << "Cannot find value " << valuePointed << endl;
            return false;
        }
    }
}

bool deleteFirst(Node *&head, Node *&tail)
{
    if (head != NULL)
    {
        Node *temp = head;
        if (head->next == NULL)
        {
            tail = NULL;
            head = NULL;
        }
        else
        {
            head = temp->next;
            temp->next->prev = NULL;
            temp->next = NULL;
        }
        delete(temp);
        return true;
    }
    else 
    {
        return false;
    }
}

bool deleteLast(Node *&head, Node *&tail)
{
    if (tail != NULL)
    {
        Node* temp = tail;
        if (tail->prev != NULL)
        {
            tail = temp->prev;
            temp->prev->next = NULL;
            temp->prev = NULL;
        }
        else
        {
            head = NULL;
            tail = NULL;
        }
        delete (temp);
    }
}
bool display(Node *head, int displayID)
{
    cout << "****************" << displayID << "****************" << endl << endl;
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << '\t';
        p = p->next;
    }
    cout << endl << endl;
}

int main()
{
    Node *head, *tail;
    int displayID = 1;
    init(head, tail);
    addFirst(head, tail, 1);
    addFirst(head, tail, 2);
    addFirst(head, tail, 3);
    display(head, displayID++);
    addLast(head, tail, 4);
    addLast(head, tail, 5);
    display(head, displayID++);
    addAfter(head, tail, 3, 6);
    display(head, displayID++);
    deleteFirst(head, tail);
    display(head, displayID++);
    deleteFirst(head, tail);
    display(head, displayID++);
    deleteLast(head, tail);
    display(head, displayID++);
    deleteLast(head, tail);
    display(head, displayID++);
    deleteLast(head, tail);
    display(head, displayID++);
    deleteLast(head, tail);
    display(head, displayID++);
    return 0;
}
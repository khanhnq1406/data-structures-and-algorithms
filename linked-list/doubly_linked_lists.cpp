#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

struct DoublyLinkedList
{
    Node *head;
    Node *tail;
};
void init(DoublyLinkedList *&list)
{
    list->head = NULL;
    list->tail = NULL;
}

Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

bool addFirst(DoublyLinkedList *&list, int value)
{
    Node *newNode = createNode(value);
    Node *temp = list->head;
    if (temp != NULL)
    {
        newNode->next = temp;
        temp->prev = newNode;
        list->head = newNode;
    }
    else
    {
        list->head = newNode;
        list->tail = newNode;
    }
    return true;
}

bool addLast(DoublyLinkedList *&list, int value)
{
    Node *newNode = createNode(value);
    Node *temp = list->tail;
    if (temp != NULL)
    {
        temp->next = newNode;
        newNode->prev = temp;
        list->tail = newNode;
    }
    else
    {
        list->tail = newNode;
        list->head = newNode;
    }
    return true;
}

bool addAfter(DoublyLinkedList *&list, int valuePointed, int newValue)
{
    Node *temp = list->head;
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
                addLast(list, newValue);
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

bool deleteFirst(DoublyLinkedList *&list)
{
    if (list->head != NULL)
    {
        Node *temp = list->head;
        if (list->head->next == NULL)
        {
            list->tail = NULL;
            list->head = NULL;
        }
        else
        {
            list->head = temp->next;
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

bool deleteLast(DoublyLinkedList *&list)
{
    if (list->tail != NULL)
    {
        Node* temp = list->tail;
        if (list->tail->prev != NULL)
        {
            list->tail = temp->prev;
            temp->prev->next = NULL;
            temp->prev = NULL;
        }
        else
        {
            list->head = NULL;
            list->tail = NULL;
        }
        delete (temp);
    }
}
bool displayRightToLeft(Node *head, int displayID)
{
    cout << "****************" << displayID <<". Right to left" << "****************" << endl << endl;
    Node *p = head;
    while (p != NULL)
    {
        cout << p->data << '\t';
        p = p->next;
    }
    cout << endl << endl;
}

bool displayLeftToRight(Node *tail, int displayID)
{
    cout << "****************" << displayID <<". Left to right" << "****************" << endl << endl;
    Node *p = tail;
    while (p != NULL)
    {
        cout << p->data << '\t';
        p = p->prev;
    }
    cout << endl << endl;
}
int main()
{
    DoublyLinkedList *list;
    int displayID = 1;
    init(list);
    addFirst(list, 1);
    addFirst(list, 2);
    addFirst(list, 3);
    displayRightToLeft(list->head, displayID++);
    addLast(list, 4);
    addLast(list, 5);
    displayRightToLeft(list->head, displayID++);
    addAfter(list, 3, 6);
    displayRightToLeft(list->head, displayID++);
    deleteFirst(list);
    displayRightToLeft(list->head, displayID++);
    deleteFirst(list);
    displayRightToLeft(list->head, displayID++);
    deleteLast(list);
    displayRightToLeft(list->head, displayID++);
    deleteLast(list);
    displayRightToLeft(list->head, displayID++);
    deleteLast(list);
    displayRightToLeft(list->head, displayID++);
    deleteLast(list);
    displayRightToLeft(list->head, displayID++);

    displayID = 0;
    addFirst(list, 1);
    addFirst(list, 2);
    addFirst(list, 3);
    displayLeftToRight(list->tail, displayID++);
    addLast(list, 4);
    addLast(list, 5);
    displayLeftToRight(list->tail, displayID++);
    addAfter(list, 3, 6);
    displayLeftToRight(list->tail, displayID++);
    deleteFirst(list);
    displayLeftToRight(list->tail, displayID++);
    deleteFirst(list);
    displayLeftToRight(list->tail, displayID++);
    deleteLast(list);
    displayLeftToRight(list->tail, displayID++);
    deleteLast(list);
    displayLeftToRight(list->tail, displayID++);
    deleteLast(list);
    displayLeftToRight(list->tail, displayID++);
    deleteLast(list);
    displayLeftToRight(list->tail, displayID++);
    return 0;
}
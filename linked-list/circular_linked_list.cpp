#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct CircularLinkedList
{
    Node *head;
    Node *tail;
};
void init(CircularLinkedList *&list)
{
    list->head = NULL;
    list->tail = NULL;
}

Node* createNode(CircularLinkedList *&list, int value)
{
    Node *new_node = new Node;
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

bool addFirst(CircularLinkedList *&list, int value)
{
    Node *new_node = createNode(list, value);
    if (list->head != NULL)
    {
        new_node->next = list->head;
        list->head = new_node;
        list->tail->next = list->head;
        return true;
    }
    else 
    {
        list->head = list->tail = new_node;
        list->tail->next = list->head;
        return true;
    }
    return false;
}

bool addLast(CircularLinkedList *&list, int value)
{
    Node *new_node = createNode(list, value);
    if (list->head != NULL)
    {
        list->tail->next = new_node;
        list->tail = new_node;
        list->tail->next = list->head;
    }
    else 
    {
        list->head = list->tail = new_node;
        list->tail->next = list->head;
        return true;
    }
    return false;
}

bool addAfter(CircularLinkedList *&list, int valuePointed ,int newValue)
{
    Node *new_node = createNode(list, newValue);
    if (list->head != NULL)
    {
        bool hasValue = false;
        Node *temp = list->head;
        do
        {
            if (temp->data == valuePointed) 
            {
                hasValue = true;
                break;
            }
            temp = temp->next;
        } while (temp != list->head);
        if (hasValue)
        {
            new_node->next = temp->next;
            temp->next = new_node;
            if (temp == list->tail)
                list->tail = new_node;
            return true;
        }
    }
    return false;
}

bool deleteFirst(CircularLinkedList *&list)
{
    if (list->head != NULL)
    {   
        if (list->head != list->tail)
        {
            Node *temp = list->head;
            list->tail->next = list->head->next;
            list->head = list->head->next;
            temp->next = NULL;
            delete(temp);
        }
        else
        {
            list->tail = NULL;
            list->head = NULL;
        }
        
    }
}

bool deleteLast(CircularLinkedList *&list)
{
    if (list->head != NULL)
    {
        if (list->head != list->tail)
        {
            Node *prev_tail = list->head;
            Node *temp = list->tail;
            while (prev_tail->next != list->tail)
            {
                prev_tail = prev_tail->next;
            }
            list->tail = prev_tail;
            list->tail->next = list->head;
            temp->next = NULL;
            delete(temp);
        }
        else
        {
            list->head = NULL;
            list->tail = NULL;
        }
    }
}

bool deleteNode(CircularLinkedList *&list)
{
    if (list->head != NULL)
    {
        Node *temp = list->head;
        int i = 0;
        while (temp != NULL)
        {
            if (list->head == list->tail)
            {
                list->head = NULL;
                list->tail = NULL;
                break;
            }
            list->head = temp->next;
            list->tail->next = list->head;
            temp->next = NULL;
            temp = list->head;
        }
        cout << "Deleted!!!" << endl;
        return true;
    }
    return false;
}

void display(const CircularLinkedList *list)
{
    if (list->head != NULL)
    {
        Node *temp = list->head;
        do
        {
            cout << temp->data << '\t';
            temp = temp->next;
        } while (temp != list->head);
        cout << endl;
    }
}

int main()
{
    CircularLinkedList *list;
    init(list);
    addFirst(list, 1);
    addFirst(list, 2);
    display(list);
    addLast(list, 3);
    display(list);
    addAfter(list,3, 4);
    display(list);
    addLast(list, 5);
    display(list);
    addFirst(list, 6);
    display(list);
    deleteFirst(list);
    display(list);
    deleteLast(list);
    display(list);
    cout << "-------------- Delete Node --------------" << endl;
    deleteNode(list);
    display(list);
    return 0;
}
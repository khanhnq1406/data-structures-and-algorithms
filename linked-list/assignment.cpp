// An informatics center needs to build a student management system in which students can be added unlimitedly and any time of the year
// A student have studentID, name and birthYear.
#include <iostream>
using namespace std;

struct StudentNode
{
    int studentID;
    int birthYear;
    string name;
    StudentNode *next;
};

struct StudentsInfo
{
    int studentID;
    int birthYear;
    string name;
};

void init(StudentNode *&head)
{
    head = NULL;
}

bool isEmpty(StudentNode *&head)
{
    return (head == NULL);
}

StudentNode *findLast (StudentNode *head)
{
    StudentNode *lastStudent = head;
    while (lastStudent->next != NULL)
    {
        lastStudent = lastStudent->next;
    }
    return lastStudent;
}
StudentNode* createStudent (StudentsInfo student)
{
    StudentNode *newStudent = new StudentNode;
    newStudent->studentID = student.studentID;
    newStudent->birthYear = student.birthYear;
    newStudent->name = student.name;
    newStudent->next = NULL;
}

bool addFirst(StudentNode *&head, StudentsInfo student)
{
    StudentNode *newStudent = createStudent(student);
    newStudent->next = head;
    head = newStudent;
    return true;
}

bool addLast(StudentNode *&head, StudentsInfo student)
{
    StudentNode *newStudent = createStudent(student);
    if (head == NULL)
    {
        head = newStudent;
    }
    else
    {
        StudentNode *lastStudent = findLast(head);
        lastStudent->next = newStudent;
    }
    return true;
}

bool addAfter (StudentNode *&head, StudentsInfo studentPointed, StudentsInfo student)
{
    StudentNode *newStudent = createStudent(student);
    StudentNode *temp = head;
    while (temp->next != NULL && (temp->studentID != studentPointed.studentID  && temp->name != studentPointed.name && temp->birthYear != studentPointed.birthYear))
    {
            temp = temp->next;
    }
    if (temp != NULL)
    {
        newStudent->next = temp->next;
        temp->next = newStudent;
    }
}

bool deleteFirst(StudentNode *&head)
{
    if (!isEmpty(head))
    {
        StudentNode *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete(temp);
        return true;
    }
}

bool deleteLast(StudentNode *&head)
{
    if (!isEmpty(head))
    {
        StudentNode *lastStudent = findLast(head);
        StudentNode *prevLastStudent = head;
        while (lastStudent->next != NULL)
        {
            prevLastStudent = lastStudent;
            lastStudent = lastStudent->next;
        }
        if (prevLastStudent == NULL)
        {
            deleteFirst(head);
        }
        else
        {
            prevLastStudent->next = NULL;
            delete(lastStudent);
        }
        return true;
    }
}

bool deleteNode(StudentNode *&head, StudentsInfo studentPointed)
{
    if (head != NULL)
    {
        StudentNode *temp = head;
        StudentNode *prev_temp = NULL;
        while (temp->next != NULL && (temp->studentID != studentPointed.studentID  && temp->name != studentPointed.name && temp->birthYear != studentPointed.birthYear))
        {
            prev_temp = temp;
            temp = temp->next;
        }
        if (temp != NULL)
        {
            
            if (prev_temp == NULL) // only have an element
            {
                deleteFirst(head);
            }
            else
            {
                prev_temp->next = temp->next;
                temp->next = NULL;
                delete(temp);
            }
        }
    }
}

bool display(StudentNode *head, int displayID)
{
    cout << "************" << displayID << "************" << endl;
    StudentNode *temp = head;
    while (temp != NULL)
    {
        cout << "Student ID: " << temp->studentID << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Birth Year: " << temp->birthYear << endl;
        cout << "-----------" << endl;
        temp = temp->next;
    }
    return true;
}

int main()
{
    int count = 1;
    StudentNode *head;
    init(head);
    StudentsInfo student;
    student.studentID = 1;
    student.birthYear = 2001;
    student.name = "Nguyen Quoc Khanh";
    addFirst(head, student);
    addLast(head, student);
    addLast(head, student);
    display(head,count++);
    deleteFirst(head);
    display(head,count++);
    deleteLast(head);
    display(head,count++);
    addAfter(head,student, student);
    display(head,count++);
    return 0;
}
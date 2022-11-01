// Singly Linked List
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    explicit node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class linkedList
{
public:
    node *head;
    node *tail;
    node *ploc;
    node *loc;

    linkedList()
    {
        head = nullptr;
        tail = nullptr;
        ploc = nullptr;
        loc = nullptr;
    }

    bool isempty() const
    {
        return head == nullptr;
    }
    void insetAtHead(int val)
    {
        node *newnode = new node(val);
        if (isempty())
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }

    void insertAtTail(int val)
    {
        node *newnode = new node(val);
        if (isempty())
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void printll() const
    {
        node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void reversePrint(node *temp)
    {
        if (temp != nullptr)
        {
            reversePrint(temp->next);
            cout << temp->data << endl;
        }
    }
};
// REQUIRED FUNCTION
void reversePrint(node *temp)
{
    if (temp != nullptr)
    {
        reversePrint(temp->next);
        cout << temp->data << endl;
    }
}
int main()
{
    linkedList l;
    l.insetAtHead(7);
    l.insetAtHead(8);
    l.insetAtHead(9);
    l.insetAtHead(1);
    l.insetAtHead(2);
    l.insetAtHead(3);
    l.insetAtHead(5);
    reversePrint(l.head);
}
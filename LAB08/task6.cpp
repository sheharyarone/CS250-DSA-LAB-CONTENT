
// Singly Linked List
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
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

    int length() const
    {
        node *temp = head;
        int n = 0;

        while (temp != nullptr)
        {
            n++;
            temp = temp->next;
        }
        return n;
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
    void reverseList(node *ploc, node *loc)
    {
        if (loc != nullptr)
        {
            reverseList(loc, loc->next);
            loc->next = ploc;
        }
        if (loc == head)
        {
            head = tail;
            tail = loc;
        }
    }
};

int main()
{
    linkedList ll;
    ll.insetAtHead(7);
    ll.insetAtHead(4);
    ll.insertAtTail(9);
    ll.insertAtTail(12);
    ll.insertAtTail(34);
    ll.insertAtTail(41);

    ll.printll();

    node *temp = ll.head;
    ll.reverseList(nullptr, temp);
    ll.printll();
}


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
    linkedList()
    {
        head = nullptr;
        tail = nullptr;
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
    void rearrangeEvenOdd(node *ploc, node *loc)
    {

        if (loc != nullptr)
        {
            if (ploc == nullptr)
            {
                // loc = loc->next;
                rearrangeEvenOdd(loc, loc->next->next);
                loc = loc->next;

            }
            else
            {
                ploc->next = loc;
                ploc = ploc->next;
                rearrangeEvenOdd(loc, loc->next->next);
                loc = loc->next;
            }
            loc->next = ploc;
            if (ploc == nullptr)
            {
                tail = loc;
            }
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
    ll.rearrangeEvenOdd(nullptr, ll.head);
    ll.printll();
}

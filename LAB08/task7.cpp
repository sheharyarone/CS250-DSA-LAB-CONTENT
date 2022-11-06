
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
    void rearrangeEvenOdd(node *ploc, node *loc, node *sloc, int node_num = 1) // ploc:head loc sloc
    {
        // cout << "DATA : " << ploc->data << " " << loc->data << " " << sloc->data << endl;
        if (sloc != nullptr)
        {
            if (node_num % 2 != 0)
            {
                // if (ploc == head)
                // {
                //     loc->next=nullptr;
                //     tail=loc;
                // }

                ploc->next = sloc;
                // cout << "if : ";
                // printll();
                if (sloc == tail)
                {
                    sloc->next = loc;
                }
                else
                {
                    rearrangeEvenOdd(loc, sloc, sloc->next, ++node_num);
                }
                if (ploc == head)
                {
                    loc->next = nullptr;
                    tail = loc;
                }
            }
            else
            {
                sloc = sloc->next;
                loc->next->next = ploc;
                // cout << "else : ";
                // printll();
                rearrangeEvenOdd(loc, loc->next, sloc, ++node_num);
            }
        }
    }
};

int main()
{
    linkedList ll;
    ll.insetAtHead(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.insertAtTail(7);
    ll.insertAtTail(8);
    // ll.insertAtTail(9);
    ll.printll();
    ll.rearrangeEvenOdd(ll.head, ll.head->next, ll.head->next->next);
    ll.printll();
}

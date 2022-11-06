
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
        // ploc : head  loc :head->next  sloc : head->next->next
        // AFTER EACH ITERTAION all *locs will move forward by 1 point
        // node_num will decide the even odd node operation

        if (ploc == head && sloc == nullptr)
        {
            tail->next = head;
            head = tail;
            tail = ploc;
            tail->next = nullptr;
            return;
        }

        if (sloc != nullptr)
        {
            // ODD NODE OEPRATION
            if (node_num % 2 != 0)
            {
                ploc->next = sloc;

                // IF WE GOT TAIL NODE (THAT WILL BE ODD TAIL NODE) IN SLOC NO FURTHER FUNCTION CALLING
                // CONNECTING IT TO LAST EVEN NODE AND NO FURTHER FUNCTION CALLING
                if (sloc == tail)
                {
                    sloc->next = loc;
                }
                else
                {
                    rearrangeEvenOdd(loc, sloc, sloc->next, ++node_num);
                }
                // UPDATING THE TAIL NODE OF LIST
                if (ploc == head)
                {
                    loc->next = nullptr;
                    tail = loc;
                }
            }
            // EVEN NODE OPERATION
            else
            {
                sloc = sloc->next;
                loc->next->next = ploc;
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
    // ll.insertAtTail(3);
    ll.printll();
    ll.rearrangeEvenOdd(ll.head, ll.head->next, ll.head->next->next);
    ll.printll();
}

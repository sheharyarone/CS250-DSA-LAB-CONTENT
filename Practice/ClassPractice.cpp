#include <iostream>
#include <string>
using namespace std;

// SWAPPING THE NODES OF SINLGY LINK
// DELETING THE ODD NUMBER NODES OF SINLGY LINK LIST
struct Node
{
    int data;
    struct Node *next;
}
    *first = NULL;
bool isEmpty()
{
    return first == NULL;
}

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node();
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {

        t = new Node();
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << (p->data) << endl;
        p = p->next;
    }
}

void DisplayRecursive(struct Node *p)
{
    if (p != NULL)
    {
        cout << p->data << endl;
        DisplayRecursive(p->next);
    }
}
void swapping(struct Node *p)
{
    Node *temp = new Node();

    while (p != NULL && p->next != NULL && p->next->next != NULL)
    {
        temp = p->next;                // 2 IN TEMP
        p->next = p->next->next;       // next of 1 is 3
        temp->next = temp->next->next; // next of 2 is 4

        p->next->next = temp; // next of 3 is 2
        p = p->next->next;
    }
}

void dlt_odd_nodes(struct Node *p)
{
    Node *temp = new Node();
    if (p != NULL)
    {
        temp = p;
        p = p->next;
        first = p;
        delete temp;
    }
    while (p != NULL)
    {
        if (p->next == NULL)
        { // LAST EVEN
            break;
        }

        temp = p->next;
        if (p->next->next == NULL) // LAST ODD
        {
            p->next = NULL;
        }
        else
        {
            p->next = p->next->next;
        }
        delete temp;
        p = p->next;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6};

    create(A, sizeof(A) / sizeof(int));
    dlt_odd_nodes(first);
    Display(first);
    return 0;
}
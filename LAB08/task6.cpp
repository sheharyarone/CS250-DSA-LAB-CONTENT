#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}
    *first = NULL;

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
void DisplayRecursive(struct Node *p)
{
    if (p != NULL)
    {
        cout << p->data << endl;
        DisplayRecursive(p->next);
    }
}

void Rec_reverse(Node *q, Node *p)
{

    if (p != NULL)
    {
        Rec_reverse(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5, 6};

    create(A, sizeof(A) / sizeof(int));
    Rec_reverse(NULL, first);
    DisplayRecursive(first);
}
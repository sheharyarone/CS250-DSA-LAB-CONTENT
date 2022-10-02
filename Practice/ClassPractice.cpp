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
    return true;
}
void del(struct Node *p)
{
    if (!isEmpty())
    {
        int counter = 1;

        while (p->next != NULL)
        {
            struct Node *temp;
            temp=p;
            p = p->next;
            counter += 1;
            if (counter % 2 == 0)
            {
                
                delete temp;
            }
        }
    }
}

int main()
{

    return 0;
}
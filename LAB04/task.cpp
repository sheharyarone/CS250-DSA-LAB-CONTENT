#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class CLL
{
    Node *list;
    Node *loc;
    Node *ploc;
    CLL()
    {
        list = NULL;
        ploc = NULL;
        loc = NULL;
    }
    bool isEmpty();
    void insertAtFront(int);
    void insertAtTail(int);
    void printList();
    void Search(int);
    void insertedSorted(int);
    void Delete(int);
};
bool CLL ::isEmpty()
{
    return list == NULL;
}
void CLL ::insertAtFront(int data)
{
    Node *newnode = new Node();
    newnode->data = data;
    // NOT EMPTY CASE
    if (!isEmpty())
    {
        newnode->next = list->next;
        list->next = newnode;
    }
    // EMPTY CASE
    else
    {
        list = newnode;
        list->next = newnode;
    }
}
void CLL ::insertAtTail(int data)
{
    Node *newnode = new Node();
    newnode->data = data;
    // NOT EMPTY CASE
    if (!isEmpty())
    {
        newnode->next = list->next;
        list = newnode;
    }
    // EMPTY CASE
    else
    {
        list = newnode;
        list->next = newnode;
    }
}
void CLL ::printList()
{
    // NOT EMPTY CASE
    Node *p = list->next;
    if (!isEmpty())
    {
        while (p != list->next)
        {
            cout << p->data << endl;
            p = p->next;
        }
    }
    else
    {
        cout << 'LIST IS EMPTY' << endl;
    }
}
void CLL ::Search(int value)
{
    loc, ploc = NULL;
    if (isEmpty())
        return;

    ploc = list;
    loc = ploc->next;
    while (loc->data < value && loc != list)
    {
        ploc = loc;
        loc = loc->next;
    }
    if (loc == list && loc->data < value)
    {
        ploc = list;
        loc = NULL;
        return;
    }
    if (loc->data != value)
    {
        loc = NULL;
    }
}
void CLL::insertedSorted(int data)
{
    Search(data);
    if (loc != NULL)
    {
        cout << "VALUE EXIST" << endl;
    }
    else
    {
        Node *newnode = new Node();
        newnode->data = data;
        if (isEmpty())
        {

            list = newnode;
            list->next = list;
        }
        else if (loc == list)
        {
            insertAtTail(data);
        }
        else
        {
            ploc->next = newnode;
            newnode->next = loc;
        }
    }
}
void CLL::Delete(int data)
{
    Search(data);
    if (loc != NULL)
    {
        cout << "DELETING THE VALUE :" << endl;

        if (list != list->next)
        {
            ploc->next = loc->next;
            if (loc == list)
            {
                list = ploc;
            }
            delete loc;
        }
        else
        {
            delete list;
            list = NULL;
        }
    }
    else
    {
        cout<<"VALUE DOESN'T EXIST"<<endl;
    }
}
int main()
{

    return 0;
}
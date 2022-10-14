#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
class stack
{
public:
    node *top;
    int size;
    stack()
    {
        size = 0;
        top = NULL;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    void Push(int data)
    {
        node *temp = new node();

        temp->data = data;
        temp->next = top;
        top=temp;
        size+=1;
    }
    int Pop()
    {
        if (!isEmpty())
        {
            node *temp = top;
            int d = top->data;
            top = top->next;
            delete temp;
            size-=1;
            return d;
        }
        else
        {
            return -99999;
        }
    }
    int Top(){
        return top->data;
    }
};

int main()
{
    stack F;
    F.Push(5);

    cout<<F.Top()<<endl;
    cout<<F.isEmpty()<<endl;
    cout<<F.Pop()<<endl;
    cout<<F.isEmpty()<<endl;
    

    return 0;
}
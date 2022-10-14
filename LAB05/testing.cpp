#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    char data;
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
    void Push(char data)
    {
        node *temp = new node();

        temp->data = data;
        temp->next = top;
        top = temp;
        size += 1;
    }
    char Pop()
    {
        if (!isEmpty())
        {
            node *temp = top;
            int d = top->data;
            top = top->next;
            delete temp;
            size -= 1;
            return d;
        }
        else
        {
            return ' ';
        }
    }
    char Top()
    {
        return top->data;
    }
};
bool charCheck(char s)
{
    string f = "[{()}]";
    for (int i = 0; f.length() > i; i++)
    {
        if (f[i] == s)
        {
            return true;
        }
    }
    return false;
}


int main()
{
    stack b;
    string toCheck = "(){([])}";
    for (int i = 0; toCheck.length() > i; i++)
    {
        if (charCheck(toCheck[i]))
        {
            if (b.isEmpty())
            {
                b.Push(toCheck[i]);
                cout<<"push"<<toCheck[i]<<endl;
            }
            else if (
                ((b.Top() == '{') && (toCheck[i] == '}'))

            )
            {
                cout<<"1st"<<endl;
                cout<<"pop";
                cout<<b.Pop()<<endl;
            }
            else if (
                ((b.Top() == '[') && (toCheck[i] == ']'))

            )
            {
                cout<<"2nd"<<endl;

                cout<<"pop";
                                cout<<b.Pop()<<endl;

            }
            else if (((b.Top() == '(') && (toCheck[i] == ')')))
            {
                cout<<"3rd"<<endl;

                cout<<"pop";

                cout<<b.Pop()<<endl;

            }
            else
            {
                b.Push(toCheck[i]);
                cout<<"PUSH IN LAST ELSE"<<endl;
            }
        }
    }

    if (b.isEmpty())
    {
        cout << "BALANCED" << endl;
    }
    else
    {

     cout<<"NOT BALANCED"<<endl;
    }

    return 0;
}
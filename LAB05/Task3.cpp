
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
        top = nullptr;
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

bool optrCheck(char s)
{
    string check = "+-/*%^";
    for (int i = 0; i < check.length(); i++)
    {
        if (check[i] == s)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    string toChange = "12+30/5";
    stack f;
    string answer;
    string parts;
    for (int i = 0; i < toChange.length(); i++)
    {
        if (optrCheck(toChange[i]))
        {
            answer += parts + " ";
            parts = "";
            f.Push(toChange[i]);
        }
        else
        {
            parts += toChange[i];
        }
    }
    answer += parts;

    cout << answer;
    for (int i = -1; i < f.size; i++)
    {
        cout << f.Pop();
    }

    return 0;
}
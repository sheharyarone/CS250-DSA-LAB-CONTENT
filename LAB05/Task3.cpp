#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class nodeOfChar
{
public:
    string data;
    nodeOfChar *next;
};
class stackOfChar
{
public:
    nodeOfChar *top;
    int size;
    stackOfChar()
    {
        size = 0;
        top = NULL;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    void Push(string data)
    {
        nodeOfChar *temp = new nodeOfChar();

        temp->data = data;
        temp->next = top;
        top = temp;
        size += 1;
    }
    char Pop()
    {
        if (!isEmpty())
        {
            nodeOfChar *temp = top;
            char d = top->data;
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

class nodeOfStr
{
public:
    string data;
    nodeOfStr *next;
};
class stackOfStr
{
public:
    nodeOfStr *top;
    int size;
    stackOfStr()
    {
        size = 0;
        top = NULL;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    void Push(string data)
    {
        nodeOfStr *temp = new nodeOfStr();

        temp->data = data;
        temp->next = top;
        top = temp;
        size += 1;
    }
    string Pop()
    {
        if (!isEmpty())
        {
            nodeOfStr *temp = top;
            string d = top->data;
            top = top->next;
            delete temp;
            size -= 1;
            return d;
        }
        else
        {
            return "";
        }
    }
    string Top()
    {
        return top->data;
    }
};

bool operatorCheck(char opr)
{
    string s = "+-^*/%";
    for (int i = 0; s.length() > i; i++)
    {
        if (s[i] == opr)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    stackOfStr optrInExp;
    stackOfChar data;
    string toChange = "12+30/5";
    string answer;
    string num="";
    for (int i = 0; i < toChange.length(); i++)
    {
        if (operatorCheck(toChange[i]))
        {
            optrInExp.Push(num);
            string num="";
            data.Push(toChange[i]);
        }
        else
        {
            num+=toChange[i];
        }
    }
    return 0;
}
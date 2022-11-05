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
    char size;
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
        top = temp;
        size += 1;
    }
    char Pop()
    {
        if (!isEmpty())
        {
            node *temp = top;
            char d = top->data;
            top = top->next;
            delete temp;
            size -= 1;
            return d;
        }
        else
        {
            return '-';
        }
    }
    char Top()
    {
        return top->data;
    }
};

void postFix(string s)
{
    stack optrStack;
    string postFix = "";
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        cout << postFix << endl;
        cout << "CHARACTER : " << c << endl;
        if ((int(c) >= int('A') && int(c) <= int('Z')) ||
            (int(c) >= int('a') && int(c) <= int('z')) ||
            (int(c) >= int('0') && int(c) <= int('9')))
        {
            postFix += c;
        }
        else if (c == '{' || c == '[' || c == '(')
        {
            optrStack.Push(c);
        }
        else if (c == '}' || c == ']' || c == ')')
        {
            while (optrStack.Top() != '{' &&
                   optrStack.Top() != '[' &&
                   optrStack.Top() != '(')
            {
                postFix += optrStack.Pop();
            }
            optrStack.Pop();
        }
        else
        {
            // STACK IS EMPTY
            if (optrStack.isEmpty() || optrStack.Top() == '{' || optrStack.Top() == '[' || optrStack.Top() == '(')
            {
                optrStack.Push(c);
            }
            // SAME PRECEDENCE OPERATORS ARE THERE HAVING LEFT TO RIGHT PRECEDENCE
            else if (((c == '+' || c == '-') && (optrStack.Top() == '+' || optrStack.Top() == '-')) ||
                     ((c == '*' || c == '/') && (optrStack.Top() == '*' || optrStack.Top() == '/')))
            {
                // cout<<"SAME RPECEDENCE LEFT TO RIGHT"<<endl;
                postFix += optrStack.Pop();
                optrStack.Push(c);
            }
            // SAME PRECEDENCE BUT PRECEDENCE FROM RIGHT TO LEFT
            else if ((c == '^') && (optrStack.Top() == '^'))
            {
                postFix += c;
            }
            // MORE PRECEDENCE OPERATOR CAME UP
            else if ((c == '/' || c == '*') && (optrStack.Top() == '+' || optrStack.Top() == '-'))
            {
                // cout << "MORE PRECEDENCE CAME UP" << endl;
                optrStack.Push(c);
            }
            // LESS PRECEDENCE OEPRATOR CAME UP ( +  -)
            else if ((c == '+' || c == '-') && (optrStack.Top() == '*' || optrStack.Top() == '/' || optrStack.Top() == '^'))
            {
                postFix += optrStack.Pop();
                while ((optrStack.Top() == '+' || optrStack.Top() == '-'))
                {

                    postFix += optrStack.Pop();

                    if (optrStack.isEmpty())
                    {
                        break;
                    }
                }
                optrStack.Push(c);
            }
            // LESS PRECEDENCE OEPRATOR CAME UP ( *  /)
            else if ((c == '*' || c == '/') && (optrStack.Top() == '^'))
            {
                postFix += optrStack.Pop();
                while (optrStack.Top() == '^')
                {
                    postFix += optrStack.Pop();
                }
                optrStack.Push(c);
            }
        }
    }
    while (!optrStack.isEmpty())
    {

        postFix += optrStack.Pop();
    }

    cout << postFix;
}

int main()
{
    string s = "K+L-M*N+(O^P)*W/U/V*T+Q";
    postFix(s);
    return 0;
}
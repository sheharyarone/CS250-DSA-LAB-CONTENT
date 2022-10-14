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
    string f="[{()}]";
    for (int i=0;f.length()>i;i++){
        if (f[i]==s){
            return true;
        }
    }
    return false;
}
bool bracketCheck(string toCheck){

    stack b;

    for (int i = 0; toCheck.length() > i; i++)
    {
        if (charCheck(toCheck[i]))
        {
            if (b.isEmpty())
            {
                b.Push(toCheck[i]);
            }
            else if (
                (b.Top() == '{') && (toCheck[i] = '}') ||
                (b.Top() == '(') && (toCheck[i] = ')') ||
                (b.Top() == '[') && (toCheck[i] = ']')

            )
            {
                b.Pop();
            }
            else
            {
                b.Push(toCheck[i]);
            }
        }
    }
        if (b.isEmpty())
        {
            return true;
        }
        else
        {
            return false;
        }
 
}



int main()
{
    if(bracketCheck("1 + 2 * [3 * 3 + {4 – 5 (6 (7/8/9) + 10)} – 11 + (12*8) / {13 +13}] + 14")){
        cout<<"BALANCED"<<endl;
    }
    else{
        cout<<"NOT BALANCED"<<endl;
    }
    
    return 0;
}
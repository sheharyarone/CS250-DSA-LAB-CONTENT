#include<iostream>
#include<string>
using namespace std;

// REQUIRED FUNCTION
class node {
    public:
    int data;
    node *next;
};
void reversePrint(node *temp)
{
    if (temp != nullptr)
    {
        reversePrint(temp->next);
        cout << temp->data << endl;
    }
}
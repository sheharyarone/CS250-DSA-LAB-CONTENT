#include<iostream>
#include<string>
using namespace std;

class Node {
    int data;
    Node *next;
};
class CLL {
    Node *list;
    Node *loc;
    Node *ploc;
    CLL(){
        list=NULL;
        ploc=NULL;
        loc=NULL;
    }
    bool isEmpty();
    void insertAtFront(int);


};
bool CLL :: isEmpty(){
    return list==NULL;
}
void CLL :: insertAtFront(int data){
    Node *newnode= new Node();
    
}


int main()
{

    return 0;
}
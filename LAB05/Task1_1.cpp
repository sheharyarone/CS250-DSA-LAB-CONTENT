#include<iostream>
#include<string>
using namespace std;

const int size=100;
int stack[size];
int top=-1;

bool isEmpty(){
    return top==-1;
}
bool isFull(){
        return top==size-1;
}

void Push(int data){
    if(!isFull())
    {   
        top++;
        stack[top]=data;
    }
}
int Pop(){
    if(!isEmpty()){
        return(stack[top--]);
    }
}
int Top(){
    if(!isEmpty()){
        return (stack[top]);
    }
}


int main()
{
    Push(5);
    // cout<<Top()<<endl;
    // cout<<isEmpty()<<endl;
    // cout<<Pop()<<endl;
    // cout<<isEmpty()<<endl;

    

    return 0;
}
#include<iostream>
#include<string>
using namespace std;

const int size=100;
int stack[size];
int top=-1;

bool isEmpty(){
    return top==-1;
}

void Push(int data){
    if(!isFull())
    {   
        top++;
        stack[top]=data;
    }
}

bool isFull(){
        return top==size-1;
}
int main()
{
    
    

    return 0;
}
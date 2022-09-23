#include<iostream>
#include<string>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}
*first=NULL;

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    first = new Node();
    first->data=A[0];
    first->next=NULL;
    last=first;

    for (i=1;i<n;i++){

        t=new Node();
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }

}

void Display(struct Node *p){
    while(p!=NULL){
        cout<<(p->data)<<endl;
        p=p->next;
    }
}

void DisplayRecursive(struct Node *p){
    if(p!=NULL){
        cout<<p->data<<endl;
        DisplayRecursive(p->next);
    }
}
void Rev_DisplayRecursive(struct Node *p){
    if(p!= NULL){
        DisplayRecursive(p->next); //ALL THE CALLS WILL BE MADE AND THEN EACH FUNCTION WILL PRINT THE VALUE IN REVERSE ORDER
        cout<<p->data<<endl;

    }
}
void count(struct Node *p){  // SPACE COMPLEXITY 1
    int c=0;                   // Time Complexity n
    while(p!=NULL){
        c++;
        p=p->next;
    }
    cout<<c<<endl;
}
int Rec_count(struct Node *p){  // Time Taken n
    if(p==NULL){                // Space Complexity n+1
        return 0;
    }
    else{
        return Rec_count(p->next) +1 ;
    }
}

int Add(struct Node *p){
    int sum=0;
    while(p!=NULL){
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}
int Rec_Add(struct Node *p){
    if (p==NULL){
        return 0;
    }
    else{
        return Rec_Add(p->next)+p->data;
    }
}

int main(){
    int A[]={3,5,6,7,89};
    create(A,5);

//    Display(first);
    DisplayRecursive(first);
    cout<<"REVERSE ORDER "<<endl;
    Rev_DisplayRecursive(first);
    cout<<"COUNTING :"<<endl;
    count(first);

    cout<<Rec_count(first)<<endl;
    cout<<Add(first)<<endl;
    cout<<Rec_Add(first)<<endl;
    return 0;
}
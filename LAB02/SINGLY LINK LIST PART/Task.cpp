		
				            //Singly Linked List 
#include <iostream>
using namespace std;
class node{
public:
    int data;
    node * next;
    explicit node(int val){
        data = val;
        next = nullptr;
    }
};

class linkedList{
public:
    node * head;
    node * tail;
    node * ploc;
    node * loc;

    linkedList(){
        head = nullptr;
        tail = nullptr;
        ploc = nullptr;
        loc = nullptr;
    }

    bool isempty() const{
        return head == nullptr;
    }

    int length() const{
        node * temp = head;
        int n = 0;

        while (temp != nullptr){
            n++;
            temp = temp->next;
        }
        return n;
    }


    void insetAtHead(int val){
        node * newnode = new node(val);
        if (isempty()){
            head = newnode;
            tail = newnode;
        }
        else{
            newnode->next =head;
            head = newnode;
        }
    }

    void insertAtTail(int val){
        node * newnode = new node(val);
        if (isempty()){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    void insertAtPos(int val, int idx){
        if (idx == 0){
            insetAtHead(val);
        }
        else if (idx == length()-1){
            insertAtTail(val);
        }
        else{
            node * newnode = new node(val);
            node * temp =head;
            for (int i = 0; i < idx-1; i++) {
                temp = temp->next;
            }
            node * n = temp->next;
            temp->next =newnode;
            newnode->next = n;
        }

    }

    void printll() const{
        node * temp = head;
        while (temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    int search(int val) const{
        node * temp = head;
        int idx =0;
        while(temp != nullptr){
            if (temp->data == val){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    void delidx(int idx){
        if (idx ==0){
            node * k = head;
            head = head->next;
            delete k;
            return;

        }
        else if (idx == length()-1){
            node * temp = head;
            while (temp->next->next != nullptr){
                temp = temp->next;
            }
            node * todel = temp->next;
            tail = temp;
            tail->next = nullptr;
            delete todel;
            return;
        }
        node * temp = head;
        for (int i = 0; i < idx-1; i++) {
            temp = temp->next;
        }
        node * n = temp->next;
        temp->next = temp->next->next;
        delete n;
    }



    void delval(int val){
        int didx =search(val);
        if (didx == -1){
            return;
        }
        delidx(didx);
    }

    void destroy(){
        int i =0;
        while(i < length()){
            delidx(i);
        }
        head = nullptr;
        tail = nullptr;
    }

    void insertSorted(int val){
        node * temp = head;
        int n = 0;
        while (temp->data < val){
            if (temp->next == nullptr){
                insertAtTail(val);
                return;
            }
            temp = temp->next;
            n++;
        }
        insertAtPos(val, n);
    }
};

int main(){
    linkedList ll;
    ll.insetAtHead(7);
    ll.printll();
    ll.insetAtHead(4);
    ll.printll();
    ll.insertAtTail(9);
    ll.printll();
    ll.insertAtTail(12);
    ll.printll();
    ll.insertAtTail(34);
    ll.printll();
    ll.insertSorted(38);
    ll.printll();
    ll.insertAtTail(68);
    ll.printll();
    ll.insetAtHead(1);
    ll.printll();
    cout<<"The length of list is "<<ll.length()<<endl;
    ll.delval(7);
    ll.printll();
    ll.delval(38);
    ll.printll();
    cout<<"The length of list after deletion is "<<ll.length()<<endl;
    ll.insertSorted(10);
    ll.printll();
    ll.destroy();
    cout<<"The length of list after destroying is "<<ll.length()<<endl;

}


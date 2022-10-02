#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *previous;
};
class DLL
{
public:
    node *start;
    node *last;
    node *loc;
    node *ploc;
    node *sloc;
    DLL()
    {
        start = nullptr;
        last = nullptr;
        loc = nullptr;
        ploc = nullptr;
        sloc = nullptr;
    }
    bool isEmpty()
    {
        return start == nullptr;
    }
    void insertAtFront(int val)
    {
        node *nn = new node();
        nn->data = val;
        if (isEmpty())
        {
            start = nn;
            last = nn;
            nn->next = nullptr;
            nn->previous=nullptr;
        }
        else
        {
            nn->next = start;
            nn->previous = nullptr;
            start->previous=nn;
            start = nn;
        }
    }
    void insertAtEnd(int val)
    {
        node *nn = new node();
        nn->data = val;
        if (isEmpty())
        {
            last = nn;
            start = nn;
            nn->next = nullptr;
            nn->previous=nullptr;
        }
        else
        {
            last->next = nn;
            nn->previous=last;
            nn->next=nullptr;
            last = nn;
        }
    }
    void printList()
    {
        node *temp = start;
        if (!(isEmpty()))
        {
            while (temp != nullptr)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }
    void searchValue(int val)
    {
        loc = start;
        ploc = nullptr;
        while (loc != nullptr && loc->data < val)
        {
            ploc = loc;
            loc = loc->next;
        }
        if (loc != nullptr and loc->data != val)
        {
            loc = nullptr;
        }
    }
    void insertSorted(int val)
    {
        searchValue(val);
        if (loc == nullptr)
        {

            if (ploc == nullptr)
            {
                insertAtFront(val);
            }
            else
            {
                if (ploc == last)
                {
                    insertAtEnd(val);
                }
                else
                {
                    node *nn = new node();
                    nn->data = val;
                    nn->next = ploc->next;
                    nn->previous = ploc;
                    (ploc->next)->previous=nn;
                    ploc->next = nn;
                }
            }
        }
    }
    void deleteFront(){
        if(!isEmpty()){
            node *temp = start;
            start = start->next;
            start->previous=nullptr;
            delete temp;
        }
    }
    void deleteLast(){
        if(!isEmpty()){
            node *temp = last;
            last = last->previous;
            last->next=nullptr;
            delete temp;
        }
    }
    void deleteValue(int val)
    {
        if (isEmpty())
        {
            cout << "Invalid Command!" << endl;
        }
        else
        {
            searchValue(val);
            if (loc != nullptr)
            {
                if (ploc == nullptr)
                {
                    deleteFront();

                }
                else
                {
                    if (loc == last)
                    {
                        deleteLast();
                    }
                    else
                    {
                        ploc->next = loc->next;
                        (loc->next)->previous=ploc;
                        delete loc;
                    }
                }
            }
        }
    }
    void destroyList()
    {
        node *temp;
        while (start != nullptr)
        {
            temp = start;
            start = start->next;
            delete temp;
        }
    }
    void reverseList(){
    if (isEmpty()){
        cout<<"INVALID OPERATION TRY AGAIN!"<<endl;
    }
    else{
        ploc = nullptr;
        loc = start;
        last = start;
        while (loc!=nullptr){
            sloc = loc->next;
            loc->next= ploc;
            loc->previous = sloc;
            ploc=loc;
            loc = loc->next;
        }
        start = ploc;
    }
    }
};
int main()
{
    DLL list1;
    list1.isEmpty();
    list1.insertAtFront(5);
    list1.insertAtEnd(6);
    list1.insertSorted(4);
    list1.reverseList();
    list1.printList();
    list1.deleteFront();
    list1.deleteLast();
    return 0;
}



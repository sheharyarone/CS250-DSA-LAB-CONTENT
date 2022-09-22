#include <iostream>

using namespace std;

class staticArrayList{
public:
    const static int size =10;
    int usedSize;
    int array[size]{};

    bool isEmpty() const{
        return !usedSize;
    }
    bool isFull() const{
        return usedSize == size;
    }

    void makeGap(int idx){
        for (int i = size ; i >= idx; i--) {
            array[i] = array[i-1];
        }
    }

    void fillGap(int idx){
        for (int i = idx ; i < size-1; i++) {
            array[i] = array[i+1];
        }
    }

    void replace(int value, int idx){
        idx--;
        if(array[idx]==-1){
            usedSize++;
        }
        array[idx] =value;
    }

    void insertAtPosition(int value, int idx){
        if (isFull()){
            return;
        }
        idx--;
        makeGap(idx);
        array[idx] = value;
        usedSize++;
    }

    void InsertSorted(int value){
        if (isFull()){
            return;
        }
        int idx=0;
        while(value> array[idx]){
            idx++;
        }
        makeGap(idx);
        array[idx] = value;
        usedSize++;
    }

    void printList(){
        for (int i : array) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    void deleteValue(int value){
        if (isEmpty()){
            return;
        }
        int idx = search(value);
        fillGap(idx);
        usedSize--;

    }
    void delValueAtPos(int idx){
        idx--;
        if(isEmpty() || array[idx]==0){
            return;
        }
        fillGap(idx);
        usedSize--;
    }

    int search(int value){
        for (int i=0; i < size; i++) {
            if (array[i]==value){
                return i;
            }
        }
        return -1;
    }

    explicit staticArrayList(){
        usedSize =0;
    }

};


int main(){
    staticArrayList st;st.printList();
    st.insertAtPosition(7, 2);st.printList();
    st.insertAtPosition(6, 2);st.printList();
    st.insertAtPosition(5, 2);st.printList();
    st.insertAtPosition(4, 2);st.printList();
    st.insertAtPosition(3, 2);st.printList();
    st.InsertSorted(1);st.printList();
    st.deleteValue(3);st.printList();
    st.delValueAtPos(3);st.printList();
    st.replace(7, 9);st.printList();
    return 0;
}

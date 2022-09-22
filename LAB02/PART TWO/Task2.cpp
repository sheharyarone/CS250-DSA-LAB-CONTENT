#include <iostream>
#define INITVAL 1000

using namespace std;

class dynamicArrayList{
public:
    const int size;
    int nsize;
    int * pArray = new int[size];
    int usedSize;

    explicit dynamicArrayList(int s): size(s){
        usedSize =0;
        nsize = size;
        for (int i = 0; i < size; i++) {
            pArray[i] = INITVAL;
        }
    }

    bool isEmpty() const{
        return !usedSize;
    }

    bool isFull() const{
        return usedSize == nsize;
    }

    void makeGap(int idx){
        for (int i = nsize-1 ; i >= idx; i--) {
            pArray[i] = pArray[i-1];
        }
        pArray[idx]=INITVAL;
    }

    void fillGap(int idx){
        for (int i = idx ; i < nsize-1; i++) {
            pArray[i] = pArray[i+1];
        }
    }

    void insertSorted(int value){
        if (isFull()){
            return;
        }
        int idx=0;
        while(value> pArray[idx]){
            idx++;
        }
        makeGap(idx);
        *(pArray+idx) = value;
        usedSize++;
    }

    void printList(){
        for (int i=0; i < nsize; i++) {
            if (pArray[i]==INITVAL){
                cout<<"";
            }
            else {
                cout<<pArray[i]<<" ";
            }
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
        pArray[nsize-1]= INITVAL;

    }
    void delValueAtPos(int idx){
        idx--;
        if(isEmpty() || pArray[idx]==0){
            return;
        }
        fillGap(idx);
        usedSize--;
    }

    int search(int value){
        for (int i=0; i < nsize; i++) {
            if (pArray[i]==value){
                return i;
            }
        }
        return -1;
    }

    void dynamicExpansion(){
        nsize *= 2;
        int *resized = new int[nsize];
        for (int i = 0; i < nsize/2; i ++)
            resized[i] = pArray[i];
        delete [] pArray;
        pArray = resized;
        for (int i = (nsize/2); i < nsize; i++) {
            pArray[i] = INITVAL;
        }
    }

    void dynamicReduction(){
        nsize /= 2;
        int *resized = new int[nsize];
        for (int i = 0; i < nsize; i ++)
            resized[i] = pArray[i];
        delete [] pArray;
        pArray = resized;
    }


};


int main(){
    dynamicArrayList st(10);st.printList();
    st.insertSorted(13);st.printList();
    st.insertSorted(34);st.printList();
    st.insertSorted(51);st.printList();
    st.insertSorted(60);st.printList();
    st.insertSorted(202);st.printList();
    st.insertSorted(54);st.printList();
    st.insertSorted(106);st.printList();
    st.insertSorted(96);st.printList();
    cout<<"The Size of array before dynamic expansion is "<<st.nsize<<endl;
    st.dynamicExpansion();
    cout<<"The Size of array after dynamic expansion is "<<st.nsize<<endl;
    st.insertSorted(76);st.printList();
    st.insertSorted(46);st.printList();
    st.insertSorted(64);st.printList();
    st.insertSorted(69);st.printList();
    cout<<"The Size of array before dynamic reduction is "<<st.nsize<<endl;
    st.dynamicReduction();st.printList();
    cout<<"The Size of array after dynamic reduction is "<<st.nsize<<endl;
    st.deleteValue(96);st.printList();
    st.deleteValue(64);st.printList();
    st.delValueAtPos(3);st.printList();
    cout<<"The Size of array before dynamic reduction is "<<st.nsize<<endl;
    st.dynamicReduction();st.printList();
    cout<<"The Size of array after dynamic reduction is "<<st.nsize<<endl;
    return 0;
}

#include<iostream>
#include<string>
using namespace std;
int main(){

    int list[5]={3,6,9,12,15};
	int *pArr= list;
    //LOOP TO PRINT LIST ELEMENTS
    for (int i=0;i<5;i++){
        cout<<*(pArr + i)<<endl; //ADDING ONE WILL MOVE TO POINTER TO NEXT ELEMENT IN LIST
    }
    return 0;
}   
#include <iostream>
#include <string>
using namespace std;


//PART A
void swappingByRef(int &b, int &a)
{
    int temp = a; // Giving value to new variable
    a = b;
    b = temp;
}

//PART B
void swappingByPointers(int *a, int *b)
{
    int temp = *a; // Giving value to new variable
    *a = *b;
    *b = temp;
}
//PART C
void swappingByPointerToPointer(int **a, int **b)
{
    int temp = **a; // Giving value to new variable
    **a = **b;
    **b = temp;
}

int main()
{

    int a = 5, b = 10;
    int *pa = &a; // pa and pb are pointer variables of type int.
    int *pb = &b;

    int **ppa = &pa; // ppa and ppb are called double pointers or pointers-to-pointers.
    int **ppb = &pb;

    // swappingByRef(a,b);
    // swappingByPointers(pa,pb);
    // swappingByPointerToPointer(ppa,ppb);

    cout << a << endl
         << b;

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int fib(int x)
{
    cout<<"Calling Fib for "<<x<<endl;
    if (x == 1 || x == 0)
    {
        return x;
    }
    return (fib(x - 1) + fib(x - 2));
}

int main()
{
    int x = 10;
    int i = 0;
    int arri[x];
    while (i < x)
    {
        arri[i]=fib(i);
        i++;
    }
    cout<<"PRINTING SERIES"<<endl;
    for(int i=0;i<(x);i++){
        cout<<arri[i]<<endl;}

    return 0;
}
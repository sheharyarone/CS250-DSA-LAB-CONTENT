#include <iostream>
#include <string>
using namespace std;

int factorial(int num)
{
    if(num<0){
        cout<<"NO FACTORIAL FOR NEGATIVE NUMBERS.";
        return -9999999;
    }
    cout << "recursive call for : "<<num << endl;
    if (num != 0)
    {
        return num * factorial(num - 1);
    }
    cout<<"BREAK BCZ 0 IS THERE."<<endl;
    return 1;
}

int main()
{
    cout << "ANSWER IS : " << factorial(5);
    return 0;
}
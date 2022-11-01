#include <iostream>
#include <string>
using namespace std;

int factorial(int num)
{
    cout << num << endl;

    if (num != 0)
    {
        return num * factorial(num - 1);
    }
    cout<<"BREAK BCZ 0 IS THERE."<<endl;
    return 1;
}

int main()
{
    cout << "recursive call for : " << endl;
    cout << "ANSWER IS : " << factorial(5);
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

bool divisible(int *prices, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += prices[i];
    }
    // IF SUM IS ODD
    if (sum % 2 != 0)
    {
        return false;
    }
    
}

int main()
{
    int prices[] = {10, 15, 12, 18, 19, 17, 13, 35, 33};
    return 0;
}
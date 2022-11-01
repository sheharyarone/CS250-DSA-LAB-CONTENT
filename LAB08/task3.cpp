#include <iostream>
#include <string>
using namespace std;

// global array of size n
int arr[] = {1, 2, 3, 4};
int sizeOfArr = sizeof(arr) / sizeof(arr[0]);
int search(int x, int index)
{
    if (index < sizeOfArr)  // index should be smaller than length of array
    {
        if (arr[index] == x)  // if found
        {
            return index;
        }
        return search(x, index + 1);
    }
    return -1;
}

int main()
{
    cout << search(90, 0)<<endl;
    cout << search(2, 0)<<endl;
    return 0;
}
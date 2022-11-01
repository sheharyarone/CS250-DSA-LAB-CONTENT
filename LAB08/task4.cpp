#include <iostream>
#include <string>
using namespace std;

bool check(string toCheck, int index)
{
    cout << index << "  " << toCheck.length() - index - 1 << endl;
    if (index > toCheck.length() - index - 1) // WHEN INDEX BECOMES GREATER THAN THE POINTER FROM END
    {
        return true;
    }
    if (toCheck[index] == toCheck[toCheck.length() - index - 1]) // POINTER FROM END VALUE EQUALS START VALUE
    {
        return check(toCheck, index + 1);
    }

    return false;
}

int main()
{
    string f = "10101";
    cout << check(f, 0);
    return 0;
}
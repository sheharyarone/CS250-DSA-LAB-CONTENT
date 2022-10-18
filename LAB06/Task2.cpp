#include <iostream>
#include <string>
using namespace std;

const int length = 8;
class Queue
{
public:
    int items[length];
    int rear, front, count;
    Queue()
    {
        rear = -1;
        front = 0;
        count = 0;
    }
    void Display()
    {
        cout << front << endl;
        cout << rear << endl;
        // cout << count << endl;
    }
    bool isEmpty()
    {
        return count == 0;
    }
    bool isFull()
    {
        return count == length;
    }
    void enqueue(int x)
    {
        if (!isFull())
        {
            rear = (rear + 1) % length;

            count++;
        }
    }
    int dequeue()
    {
        int x = items[front];
        if (!isEmpty())
        {
            front = (front + 1) % length;

            count--;
        }
        return x;
    }
};

int main()
{
    Queue q;
    q.Display();
    cout<<"PK"<<endl;
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(5);
    q.Display();
    
    return 0;
}
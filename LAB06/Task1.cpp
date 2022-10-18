#include <iostream>
#include <string>
using namespace std;

const int length = 5;
class Queue
{
public:
    int items[length];
    int front, rear;
    Queue()
    {
        front = 0;
        rear = -1;
    }
    bool isEmpty()
    {
        return front == (rear + 1);
    }
    bool isFull()
    {
        return (rear + 1) == length;
    }
    void enqueue(int x)
    {
        if (!isFull())
        {
            rear++;
            items[rear] = x;
        }
    }
    int dequeue()
    {
        if (!isEmpty())
            return items[front++];
        else
        {
            return -99999;
        }
    }
    int firstElement()
    {
        return items[front];
    }
    void clear()
    {
        rear = 0;
        front = 0;
    }
};

int main()
{
    Queue q;
    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    cout << q.dequeue();
    cout << q.dequeue();
    cout << q.isFull() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.isEmpty() << endl;

    return 0;
}
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
        return front == (rear+1);
    }
    bool isFull()
    {
        return (rear+1) == length;
    }
    void enqueue(int x)
    {
        rear++;
        items[rear] = x;
    }
    int dequeue()
    {
        return items[front++];
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

    return 0;
}
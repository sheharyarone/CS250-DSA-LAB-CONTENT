#include <iostream>
#include <string>
using namespace std;

class QNode
{
public:
    int data;
    QNode *next;
    QNode(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{
public:
    QNode *front, *rear;
    Queue() { front = rear = nullptr; }

    void enQueue(int x)
    {

        // Create a new LL node
        QNode *temp = new QNode(x);

        // If queue is empty, then
        // new node is front and rear both
        if (rear == nullptr)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            // Add the new node at
            // the end of queue and change rear
            rear->next = temp;
            rear = temp;
        }
    }

    // Function to remove
    // a key from given queue q
    int deQueue()
    {
        // If queue is empty, return NULL.
        if (front == NULL)
            return -9999;

        // Store previous front and
        // move front one node ahead
        QNode *temp = front;
        int data = front->data;
        front = front->next;

        // If front becomes NULL, then
        // change rear also as NULL
        if (front == NULL)
            rear = NULL;

        delete (temp);
        return data;
    }
    void print()
    {
        QNode *start = front;
        cout << front->data << endl;
        enQueue(deQueue());
        while (front != start)
        {
            cout << front->data << endl;
            enQueue(deQueue());
        }
    }
    bool isSorted()
    {
        if (front->data == rear->data)
        {
            return true;
        }
        QNode *start = front;
        enQueue(deQueue());
        while (front != start)
        {
            if (front->data > rear->data)
            {
                enQueue(deQueue());
            }
            else
            {
                while (start != front)
                {
                    enQueue(deQueue());
                }
                // print();
                return false;
            }
        }
        return true;
    }
    void sorting(QNode *top, QNode *nodeToBePlaced = nullptr)
    {
        if (front != nullptr)
        {
            if (nodeToBePlaced == nullptr)
            {
                if (!isSorted())
                {
                    if (front->data < rear->data)
                    {
                        enQueue(deQueue());
                        sorting(front);
                    }
                    else
                    {
                        enQueue(deQueue());
                        cout << "NODE TO BE PACED CReated FOR " << rear->data << endl;
                        QNode *nodeToBePlacedC = new QNode(deQueue());
                        sorting(front, nodeToBePlacedC);
                    }
                }
            }
            else if ((nodeToBePlaced->data > rear->data) && (front->data > nodeToBePlaced->data))
            {
                enQueue(nodeToBePlaced->data);
                sorting(front);
            }
            else
            {
                cout << "GG" << endl;
                enQueue(deQueue());
                sorting(front, nodeToBePlaced);
            }
        }
        else
        {
            cout << "SORTED" << endl;
            print();
        }
    }
};

int main()
{
    Queue test;
    test.enQueue(1);
    test.enQueue(5);

    test.enQueue(2);
    test.enQueue(4);


    test.print();
    cout << "SORTED : " << test.isSorted() << endl;

    // test.sorting(test.front);
    return 0;
}
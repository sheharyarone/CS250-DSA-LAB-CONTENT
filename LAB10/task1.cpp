#include <iostream>
#include <string>

using namespace std;

class BST_Node
{
public:
    int data;
    BST_Node *leftChild;
    BST_Node *rightChild;

    explicit BST_Node(int data_ = -1)
    {
        leftChild = nullptr;
        rightChild = nullptr;
        data = data_;
    }
};

class BST
{
public:
    BST_Node *root;
    BST_Node *ploc;
    BST_Node *loc;

    explicit BST(BST_Node *root_ = nullptr)
    {
        root = root_;
        ploc = nullptr;
        loc = nullptr;
    }

    bool isEmpty() const
    {
        return root == nullptr;
    }

    void Search(int data)
    {
        if (isEmpty())
        {
            return;
        }
        loc = root;
        while (loc != nullptr && loc->data != data)
        {
            // LEFT MOVEMENT
            if (loc->data > data)
            {
                ploc = loc;
                loc = loc->leftChild;
            }
            else
            {
                ploc = loc;
                loc = loc->rightChild;
            }
        }
    }

    void insert(int data)
    {

        Search(data);
        if (loc == nullptr && ploc == nullptr)
        {
            root = new BST_Node(data);
            return;
        }
        if (loc != nullptr && loc->data == data)
        {
            return;
        }
        if (ploc != nullptr)
        {
            // LEFT MOVEMENT
            if (data < ploc->data)
            {
                ploc->leftChild = new BST_Node(data);
            }
            // RIGHT MOVEMENT
            else
            {
                ploc->rightChild = new BST_Node(data);
            }
        }
        ploc = nullptr;
        loc = nullptr;
    }
    void preOrderTraversal(BST_Node *p)
    {
        if (p != nullptr)
        {
            cout << p->data << endl;
            preOrderTraversal(p->leftChild);
            preOrderTraversal(p->rightChild);
        }
    }
    void inOrderTraversal(BST_Node *p)
    {
        if (p != nullptr)
        {
            inOrderTraversal(p->leftChild);
            cout << p->data << endl;
            inOrderTraversal(p->rightChild);
        }
    }
    void largest()
    {
        if (isEmpty())
        {
            cout << "EMPTY" << endl;
            return;
        }
        loc = root;
        while (loc != nullptr)
        {
            ploc = loc;
            loc = loc->rightChild;
        }
        cout << ploc->data << endl;
        loc = nullptr;
        ploc = nullptr;
    }
    void smallest()
    {
        if (isEmpty())
        {
            cout << "EMPTY" << endl;
            return;
        }
        loc = root;
        while (loc != nullptr)
        {
            ploc = root;
            loc = loc->leftChild;
        }
        cout << "SMALLEST : " << ploc->data << endl;
        loc = nullptr;
        ploc = nullptr;
    }
    void postOrderTraversal(BST_Node *p)
    {
        if (p != nullptr)
        {
            postOrderTraversal(p->leftChild);
            postOrderTraversal(p->rightChild);
            cout << "LARGEST : " << p->data << endl;
        }
    }
    // void printLeafNodes(BST_Node *p)
    // {
    // }
};

int main()
{
    BST b;
    b.insert(6);
    b.insert(4);
    b.insert(8);
    b.insert(9);
    b.insert(7);
    b.insert(5);
    b.insert(2);
    b.insert(4);
    // b.preOrderTraversal(b.root);
    // cout << endl;
    // b.inOrderTraversal(b.root);
    // cout << endl;
    // b.postOrderTraversal(b.root);
    // b.smallest();
    // b.largest();
    return 0;
}
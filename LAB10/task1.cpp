#include <iostream>
#include <string>

using namespace std;
int count = 0;

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
    void printLeafNodes(BST_Node *p)
    {
        if (p != nullptr)
        {
            if (p->leftChild == nullptr && p->rightChild == nullptr)
            {
                cout << p->data << endl;
            }
            else
            {
                printLeafNodes(p->leftChild);
                printLeafNodes(p->rightChild);
            }
        }
    }
    int countLeafNodes(BST_Node *p)
    {
        if (p != nullptr)
        {
            if (p->leftChild == nullptr && p->rightChild == nullptr)
            {
                return 1;
            }
            else
            {
                return countLeafNodes(p->leftChild) + countLeafNodes(p->rightChild);
            }
        }
        else
        {
            return 0;
        }
    }
    int countInternalNodes(BST_Node *p)
    {
        if (p != nullptr)
        {
            if (p->leftChild == nullptr && p->rightChild == nullptr)
            {
                return 0;
            }
            else
            {
                return 1 + countInternalNodes(p->leftChild) + countInternalNodes(p->rightChild);
            }
        }
        else
        {
            return 0;
        }
    }
    int heightOfBST(BST_Node *p)
    {
        if (p != nullptr)
        {
            return 1 + max(heightOfBST(p->leftChild), heightOfBST(p->rightChild));
        }
        else
        {
            return -1;
        }
    }
    int maxDepth(BST_Node *p)
    {
        // Root being null means tree doesn't exist.
        if (p == NULL)
            return 0;

        // Get the depth of the left and right subtree
        // using recursion.
        int leftDepth = maxDepth(p->leftChild);
        int rightDepth = maxDepth(p->rightChild);

        // Choose the larger one and add the root to it.
        if (leftDepth > rightDepth)
            return leftDepth + 1;
        else
            return rightDepth + 1;
    }
};
int main()
{
    BST b;
    b.insert(15);
    b.insert(10);
    b.insert(8);
    b.insert(7);
    b.insert(6);
    b.insert(5);
    b.insert(4);
    b.insert(3);
    b.insert(2);

    // b.preOrderTraversal(b.root);
    // cout << endl;
    // b.inOrderTraversal(b.root);
    // cout << endl;
    // b.postOrderTraversal(b.root);
    // b.smallest();
    // b.largest();
    // b.printLeafNodes(b.root);
    // cout << b.countLeafNodes(b.root);
    // cout << b.countInternalNodes(b.root);
    // cout << b.heightOfBST(b.root);

    return 0;
}
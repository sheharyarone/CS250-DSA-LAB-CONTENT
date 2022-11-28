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

        // FIRST ITERATION
        if (loc == nullptr && ploc == nullptr)
        {
            // ROOT DATA IS REQUIRED DATA
            if (data == root->data)
            {
                loc = root;
                return;
            }
            // ROOT DATA IS GRATER => LEFT MOVEMENT
            if (data < root->data)
            {
                ploc = root;

                if (ploc->leftChild != nullptr)
                    loc = ploc->leftChild;

                else
                {
                    loc == nullptr;
                    return;
                }
            }
            // ROOT DATA IS SMALLER => RIGHT MOVEMENT
            else
            {
                ploc = root;
                if (ploc->rightChild != nullptr)
                    loc = ploc->rightChild;
                else
                {
                    loc == nullptr;
                    return;
                }
            }
        }
        // LEFT MOVEMENT
        if (data < loc->data)
        {
            ploc = loc;
            if (loc->leftChild != nullptr)
                loc = loc->leftChild;
            else
            {
                loc == nullptr;
                return;
            }
        }
        // RIGHT MOVEMENT
        else if (data > loc->data)
        {
            ploc = loc;
            if (loc->rightChild != nullptr)
                loc = loc->rightChild;
            else
            {
                loc == nullptr;
                return;
            }
        }
        // VALUE NOT FOUND     // WE EXCEED THE POSITION WHERE IT SHOULD BE SO LOC IS NULL
        if (loc->data != data)
        {
            Search(data);
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
            preOrderTraversal(p->leftChild);
            cout << p->data << endl;
            preOrderTraversal(p->rightChild);
        }
    }
    void postOrderTraversal(BST_Node *p)
    {
        if (p != nullptr)
        {
            preOrderTraversal(p->leftChild);
            preOrderTraversal(p->rightChild);
            cout << p->data << endl;
        }
    }
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
    b.preOrderTraversal(b.root);
    cout << endl;
    b.inOrderTraversal(b.root);
    cout << endl;
    b.postOrderTraversal(b.root);

    return 0;
}
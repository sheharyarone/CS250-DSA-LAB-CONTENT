#include <iostream>
#include <string>

using namespace std;

class BST_Node {
public:
    int data;
    BST_Node *leftChild;
    BST_Node *rightChild;

    explicit BST_Node(int data_ = -1) {
        leftChild = nullptr;
        rightChild = nullptr;
        data = data_;
    }
};

class BST {
public:
    BST_Node *root;
    BST_Node *ploc;
    BST_Node *loc;

    explicit BST(BST_Node *root_ = nullptr) {
        root = root_;
        ploc = nullptr;
        loc = nullptr;
    }

    bool isEmpty() const {
        return root == nullptr;
    }

    void Search(int data) {
        if (isEmpty()) {
            return;
        }

        // FIRST ITERATION
        if (loc == nullptr && ploc == nullptr) {
            // ROOT DATA IS REQUIRED DATA
            if (data == root->data) {
                loc = root;
                return;
            }
            // ROOT DATA IS GRATER => LEFT MOVEMENT
            if (data < root->data) {
                ploc = root;
                loc = root->leftChild;
            }
                // ROOT DATA IS SMALLER => RIGHT MOVEMENT
            else {
                ploc = root;
                loc = root->rightChild;
            }
        }
        // LEFT MOVEMENT
        if (data < loc->data) {
            ploc = loc;
            if (loc->rightChild != nullptr) loc = loc->leftChild;
            else loc == nullptr;
        }
            // RIGHT MOVEMENT
        else if (data > loc->data) {
            ploc = loc;
            if (loc->rightChild != nullptr) loc = loc->rightChild;
            else loc == nullptr;
        }
        //VALUE NOT FOUND     // WE EXCEED THE POSITION WHERE IT SHOULD BE SO LOC IS NULL
        if (loc->data != data && loc != nullptr) {
            Search(data);
        }
    }

    void insert(int data) {
        Search(data);
        if (loc == nullptr && ploc == nullptr) {
            root = new BST_Node(data);
        }
        if (loc == nullptr) {
            // LEFT MOVEMENT
            if (data < ploc->data) {
                ploc->leftChild = new BST_Node(data);
            }
                // RIGHT MOVEMENT
            else {
                ploc->rightChild = new BST_Node(data);
            }
        }

    }
};


int main() {

    BST b;
    b.insert(6);
    b.insert(4);
    b.insert(1);
    b.insert(2);
    b.insert(8);
    b.insert(9);
    b.insert(7);

    return 0;
}
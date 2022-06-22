#include "BinaryTree.h"
#include <iostream>
#include <queue>
using namespace std;

class Node 
{
    int data;
    Node* left;
    Node* right;
public:

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    ~Node() {}

    int getData() { return this->data; }

    Node* getLeft() { return this->left; }
    Node* getRight() { return this->right; }

    void setData(int data) { this->data = data; }
    void setLeft(Node* left) { this->left = left; }
    void setRight(Node* right) { this->right = right; }
};

void print(Node* root) // print in order
{
    if (!root)
        return;
    print(root->getLeft());
    cout << root->getData() << "\t";
    print(root->getRight());
}

void insert(Node* root, int val) // insert node
{
    Node* newNode = new Node(val);
    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty())
    {
        Node *n = Q.front();
        Q.pop();

        if (!n->getLeft())
        {
            n->setLeft(newNode);
            return;
        }
        else if (!n->getRight())
        {
            n->setRight(newNode);
        }
        else
        {
            Q.push(n->getLeft());
            Q.push(n->getRight());
        }
    }
}

Node* deleteNode(Node* root, int val) 
{
    if (root == nullptr)
        return nullptr;

    if (!root->getLeft() && !root->getRight())
    {
        if (root->getData() == val)
        {
            delete root;
            root = nullptr;
            return root;
        }
        return root;
    }

    queue<Node*> Q;
    Q.push(root);

    Node* valNode = nullptr;
    Node* current = nullptr;
    Node* pl = nullptr;
    Node* pr = nullptr;


    while (!Q.empty())
    {
        current = Q.front();
        Q.pop();

        if (current->getData() == val)
        {
            valNode = current;
        }
        if (current->getLeft())
        {
            Q.push(current->getLeft());
            pl = current;
            pr = nullptr;
        }
        if (current->getRight())
        {
            Q.push(current->getRight());
            pr = current;
            pl = nullptr;
        }
    }

    if (valNode)
    {
        valNode->setData(current->getData());
        if (pl)
        {
            pl->setLeft(nullptr);
        }
        if (pr)
        {
            pr->setRight(nullptr);
        }
    }
    return root;
}

bool iterativeSearch(Node* root, int key)
{
    // Traverse until root reaches to dead end
    while (root != NULL) {
        // pass right subtree as new tree
        if (key > root->getData())
            root = root->getRight();

        // pass left subtree as new tree
        else if (key < root->getData())
            root = root->getLeft();
        else
            return true; // if the key is found return 1
    }
    return false;
}

int main()
{	
    /*Node root(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node n7(7);

    root.setLeft(&n2);
    root.setRight(&n3);
    n2.setLeft(&n4);
    n2.setRight(&n5);
    n3.setRight(&n7);

    print(&root);
    cout << endl;

    insert(&root, 6);
    print(&root);
    cout << endl;

    insert(&root, 8);
    print(&root);
    cout << endl;

    insert(&root, 9);
    print(&root);
    cout << endl;*/

    Node root(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);
    Node n6(6);

    root.setLeft(&n2);
    root.setRight(&n3);
    n2.setLeft(&n4);
    n3.setLeft(&n5);
    n4.setRight(&n6);

    print(&root);
    cout << endl;

    deleteNode(&root, 3);
    print(&root);
    cout << endl;

    /*deleteNode(&root, 1);
    print(&root);
    cout << endl;*/

    if (iterativeSearch(&root, 6))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    deleteNode(&root, 6);
    print(&root);
    cout << endl;

    if (iterativeSearch(&root, 6))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

	return 0;
}
#pragma once
class LinkedList
{
private:
    class Node // create node
    {
    public:
        int data;
        Node* next; // pointer to next node in list
        Node* prev; // pointer to previous node in list 
    };
    Node* head;

public:
    LinkedList(); // functions

    void pushFront(int data);
    void popFront();
    void pushBack(int data);
    void popBack();
    int countList();
    bool insertAtLocation(int data, int position);
    void deleteNode(Node* del);
    void erase(int position);
    void remove(int key);
    void empty();
    int begin();
    int end();
    void bubbleSort();
    void clear();
    void printList();
    int getAtPos(int position);
};


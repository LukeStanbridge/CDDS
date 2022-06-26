#include <iostream>
#include "DoubleLinkedList.h"
#include "sstream"
using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
}

#pragma region Inserting and deleting a node at the front of the list
void LinkedList::pushFront(int data) // Insert a node at the front of the list
{
    Node* new_node = new Node(); // create node
    new_node->data = data; // put in the data
    new_node->next = head; // make next of new node as head and previous as NULL
    new_node->prev = NULL;

    if (head != NULL) // change prev of head node to new node
    {
        head->prev = new_node;
    }

    head = new_node; // move the head to point to the new node
}

void LinkedList::popFront() // Delete a node at the front of the list
{
    Node* del = head; // create node and assign head
    if (head == NULL) // checking if list is empty
        return;

    head = del->next; // assign the head to the next node

    deleteNode(del); // send node to be deleted
    return;
}
#pragma endregion

#pragma region Inserting and deleting a node at the end of the list
void LinkedList::pushBack(int data) // Insert a node at the end of the list
{
    Node* new_node = new Node(); // allocate node
    Node* last = head; 
    new_node->data = data; 
    new_node->next = NULL; // this new node is going to be the last node, so make next of it as NULL

    if (head == NULL) // if the list is empty, then make the node as head
    {
        new_node->prev = NULL;
        head = new_node;
        return;
    }

    while (last->next != NULL) // else traverse till the last node
    {
        last = last->next;
    }

    last->next = new_node; // change the next of last node
    new_node->prev = last; // make last node as previous of new node
    return;
}

void LinkedList::popBack() // Delete a node at the end of the list.
{
    if (head == NULL) // check if list is empty
        return;

    Node* del = new Node();
    Node* last = head;

    while (last->next != NULL) // traverse list
    {
        last = last->next;
    }

    del = last; // assign last to node that is to be deleted
    if (last->prev == NULL) // re-assign last as appropriate value
    {
        last = NULL;
    }
    else
    {
        last = last->prev;
    }

    deleteNode(del); // delete node
    return;
}
#pragma endregion

#pragma region Returning a count of how many nodes are in the list
int LinkedList::countList() // Count how many items in the list
{
    Node* temp = head; 

    int count = 0; // initialise variable to count with

    while (temp != NULL) // traverse the list and increment the count
    {
        count++;
        temp = temp->next;
    }
    return count; // return count
}
#pragma endregion

#pragma region Inserting by position and deleting by position or by value in the list
bool LinkedList::insertAtLocation(int data, int position) // Insert node at specific location
{
    Node* temp = head; // declare two nodes
    class Node* newNode = new Node();
    int counter = countList(); // count of total elements in the list

    if (temp == NULL || counter < position) // if list is empty or the position is not valid
        return false;

    else 
    {
        newNode->data = data; // assign the data

        for (int i = 1; i < position - 1; i++) // traverse to the correct location
        {
            temp = temp->next;
        }

        newNode->next = temp->next; // logic to insert new node after temp
        (temp->next)->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;

        return true;
    }
    return false;
}

void LinkedList::deleteNode(Node* del) // Delete a node from list
{
    if (head == NULL || del == NULL) // check if list is empty
        return;

    if (head == del) // check if node to be deleted is head node
        head = del->next;

    if (del->next != NULL) // change next only if node to be deleted is NOT the last node
        del->next->prev = del->prev;

    if (del->prev != NULL) // change prev only if node to be deleted is NOT the first node
        del->prev->next = del->next;

    free(del); // free the memory occupied by del
}

void LinkedList::erase(int position) // Remove an element by its iterator
{
    if (head == NULL || position <= 0) // check if list is empty or invalid position is given
        return;

    class Node* current = head;

    for (int i = 1; current != NULL && i < position; i++) // traverse up to the node at position given
    {
        current = current->next;
    }

    if (current == NULL) // check if position given is greater than the number of nodes in list
        return;

    deleteNode(current); // delete the node
}

void LinkedList::remove(int key) // Remove all elements with matching value
{
    if (head == NULL) // check if list is empty
        return;

    class Node* current = head;
    class Node* newNode = new Node();
    class Node* deleteTemp = new Node();
    newNode->data = key; // set key value to node

    while (current != NULL) // traverse list
    {
        if (current->data == newNode->data) // check if key value equals current node
        {
            deleteTemp = current;
            if (current->prev == NULL) // if first node in list to be deleted
            {
                current = current->next;
            }
            else // if any position but first in list
            {
                current = current->prev;
            }
            deleteNode(deleteTemp); // delete node
        }
        else
        {
            current = current->next;
        }
    }

    if (current == NULL) // if value to delete is not in list
        return;
}
#pragma endregion

#pragma region Checking if the list is empty
void LinkedList::empty() // Check list for contents
{
    if (head == NULL) // check if empty
    {
        cout << " This list is empty" << endl;
    }
    else
    {
        cout << " The list is not empty" << endl;
    }
}
#pragma endregion

#pragma region Returning the first or last node in the list
int LinkedList::begin() // Return the first element
{
    if (head == NULL) // check if list is empty
    {
        cout << " The first node is NULL" << endl;
        return NULL;
    }

    cout << " The first element is: " << head->data << endl; // print first element in list
    return head->data;;
}

int LinkedList::end() // Return last element
{
    Node* last = new Node();

    if (head == NULL) // check if list is empty
    {
        cout << " The last node is NULL";
        return NULL;
    }

    last = head; // assign last as head

    while (last->next != NULL) // traverse list
    {
        last = last->next;
    }

    cout << " The last element is: " << last->data << endl; // print last node
    return last->data;
}
#pragma endregion

#pragma region Sorting the list
void LinkedList::bubbleSort() // Sort list in ascending order
{
    int swapped;
    Node* ptr1 = new Node();
    Node* lptr = NULL;

    if (head == NULL) // check if list is empty
        return;

    do
    {
        swapped = 0; // stop do-while loop
        ptr1 = head;

        while (ptr1->next != lptr) // traverse list
        {
            if (ptr1->data > ptr1->next->data) // check if current node is greater than next node
            {
                swap(ptr1->data, ptr1->next->data); // swap nodes
                swapped = 1; // continue checking for swaps
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped); // keep looping through list until all values are in order
}
#pragma endregion

#pragma region Clearing and printing the list
void LinkedList::clear() // Remove all elements from the list
{
    while (head != NULL) // traverse list
    {
        class Node* current = head; 
        head = current->next;
        deleteNode(current); // delete node
    }
}

void LinkedList::printList() // Print contents of the list
{
    Node* temp = head;
    cout << " Contents of list >> |"; // formating
    while (temp != NULL) // treverse list
    {
        cout << " " << temp->data << " "; // print node data
        temp = temp->next;
    }
    cout << "|" << endl; // formating
    delete temp; // delete node
}
#pragma endregion

int LinkedList::getAtPos(int position) // Get node at certain position
{
    if (head == NULL || position <= 0) // check if list is empty or invalid position is given
        return NULL;

    class Node* current = head;

    for (int i = 1; current != NULL && i < position; i++) // traverse up to the desired position in list
        current = current->next;

    if (current == NULL) // if position is greater than the number of nodes in list
        return NULL;

    return current->data; // return value
}
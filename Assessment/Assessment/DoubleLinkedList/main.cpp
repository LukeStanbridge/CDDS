#include "DoubleLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
    LinkedList List; // create list
    int choice = 0; // variable to store user choice

    do
    {
        system("CLS"); // clear screen after every choice
        cout << endl // print menu
            << " 1 - Insert at front of list.\n"
            << " 2 - Pop front.\n"
            << " 3 - Insert at end of list.\n"
            << " 4 - Pop back.\n"
            << " 5 - Insert at specific location in list.\n"
            << " 6 - Delete at specific location in list.\n"
            << " 7 - Delete a specific value in list.\n"
            << " 8 - Sort the list.\n"
            << " 9 - Clear contents of list.\n"
            << " 10 - Exit Program.\n\n";
        List.printList(); // update list
        cout << endl;
        cout << " There is " << List.countList() << " node(s) in the list.\n"; // update count
        List.empty(); // check if list is empty
        List.begin(); // diplay first node in list
        List.end(); // display last node in list
        cout << endl << endl;
        cout << " Enter your choice and press return: ";
        cin >> choice; // take in user input

        switch (choice) // carry out desired function
        {
        case 1:
            int insertFront;
            cout << " Enter a value to put at the front of the list and press return: ";
            cin >> insertFront;
            List.pushFront(insertFront); // insert at front of list
            break;

        case 2:
            List.popFront(); // remove from front of list
            break;

        case 3:
            int insertBack;
            cout << " Enter a value to put at the end of the list and press return: ";
            cin >> insertBack;
            List.pushBack(insertBack); // insert at back of list
            break;

        case 4:
            List.popBack(); // remove from back of list
            break;

        case 5:
            int insert;
            int position;
            cout << " Enter a value to insert in the list and press return: ";
            cin >> insert;
            cout << " Enter the position you want to insert into the list and press return: ";
            cin >> position;
            List.insertAtLocation(insert, position); // insert at specific location
            break;

        case 6:
            int erase;
            cout << " Enter the position you want to remove from in the list and press return: ";
            cin >> erase;
            List.erase(erase); // remove from specific position
            break;

        case 7:
            int remove;
            cout << " Enter the value you want to remove from the list and press return: ";
            cin >> remove;
            List.remove(remove); // remove by value
            break;

        case 8:
            List.bubbleSort(); // sort list in ascending order
            break;

        case 9:
            List.clear(); // clear all contents in list
            break;

        case 10:
            cout << " End of Program.\n"; // exit program
            break;

        default:
            break; // check if valid option
        }
    } while (choice != 10);

    return 0;
}

#include "LinkedLists.h"
#include <iostream>
using namespace std;

int main()
{
    LinkedList List;
    int choice = 0;

    do
    {
       cout << endl
            << " 1 - Insert a node at the front of the list.\n"
            << " 2 - Delete a node at the front of the list.\n"
            << " 3 - Insert a node at the end of the list.\n"
            << " 4 - Delete a node at the end of the list.\n"
            << " 5 - Insert a node at an arbitrary location in the list.\n"
            << " 6 - Delete a node at an arbitrary location in the list.\n"
            << " 7 - Delete a node with a specific value in the list.\n"
            << " 8 - Sort the list.\n"
            << " 9 - Clear the contents of the list.\n"
            << " 10 - Exit Program.\n\n";
            List.printList();
            cout << endl;
            cout << " There is " << List.countList() << " node(s) in the list.\n";
            List.empty();
            List.begin();
            List.end();
            cout << endl << endl;
            cout << " Enter your choice and press return: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int insertFront;
            cout << " Enter a value to put at the front of the list and press return: ";
            cin >> insertFront;
            List.pushFront(insertFront);
            system("CLS");
            break;

        case 2:
            List.popFront();
            system("CLS");
            break;

        case 3:
            int insertBack;
            cout << " Enter a value to put at the end of the list and press return: ";
            cin >> insertBack;
            List.pushBack(insertBack);
            system("CLS");
            break;

        case 4:
            List.popBack();
            system("CLS");
            break;

        case 5:
            int insert;
            int position;
            cout << " Enter a value to insert in the list and press return: ";
            cin >> insert;
            cout << " Enter the position you want to insert into the list and press return: ";
            cin >> position;
            List.insertAtLocation(insert, position);
            system("CLS");
            break;

        case 6:
            int erase;
            cout << " Enter the position you want to remove from in the list and press return: ";
            cin >> erase;
            List.erase(erase);
            system("CLS");
            break;

        case 7:
            int remove;
            cout << " Enter the node you want to remove from the list and press return: ";
            cin >> remove;
            List.remove(remove);
            system("CLS");
            break;

        case 8:
            List.bubbleSort();
            system("CLS");
            break;

        case 9:
            List.clear();
            system("CLS");
            break;

        case 10:
            cout << " End of Program.\n";
            break;

        default:
            system("CLS");
            break;
        }
    } while (choice != 10);

    return 0; 
}


  
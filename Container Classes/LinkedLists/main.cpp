#include "LinkedLists.h"
#include <iostream>
#include "raylib.h"
using namespace std;

int main()
{
    LinkedList List;
    int choice = 0;

    int screenWidth = 1600;
    int screenHeight = 800;

    const char* header = "Dooblay Linked List";
    const char* option1 = "1 - Insert a node at the front of the list.";
    const char* option2 = "2 - Delete a node at the front of the list.";
    const char* option3 = "3 - Insert a node at the end of the list.";
    const char* option4 = "4 - Delete a node at the end of the list.";
    const char* option5 = "5 - Insert a node at an arbitrary location in the list.";
    const char* option6 = "6 - Delete a node at an arbitrary location in the list.";
    const char* option7 = "7 - Delete a node with a specific value in the list.";
    const char* option8 = "8 - Return a count of how many nodes are in the list.";
    const char* option9 = "9 - Check if the list is empty.";
    const char* option10 = "10 - Return the first node in the list.";
    const char* option11 = "11 - Return the last node in the list.";
    const char* option12 = "12 - Sort the list.";
    const char* option13 = "13 - Clear the contents of the list.";
    const char* option14 = "14 - Print the list.";
    const char* option15 = "15 - Exit Program.";
    const char* option16 = "Enter your choice and press return:";
    const char* option17 = "[Contents of Dooblay Linked List] >> ";

    InitWindow(screenWidth, screenHeight, "DooblayLinkedList");

    /*List.pushBack(6);
    List.pushFront(7);
    List.pushFront(1);
    List.pushBack(4);
    cout << "Created DLL is:";
    List.printList();
    List.popFront();
    cout << "popFront DLL is:";
    List.printList();
    List.popBack();
    cout << "popBack DLL is:";
    List.printList();
    List.begin();
    List.end();
    cout << "The number of nodes in the list is: " << List.countList() << endl;
    List.pushFront(3);
    List.pushFront(4);
    List.pushFront(5);
    cout << "New DLL is: ";
    List.printList();
    List.insertAtLocation(24, 3);
    cout << "Inserted DLL is: ";
    List.printList();
    List.erase(5);
    cout << "Removed DLL is: ";
    List.printList();
    List.remove(8);
    cout << "Deleted DLL is: ";
    List.printList();
    List.remove(4);
    cout << "Deleted DLL is: ";
    List.printList();
    cout << "The number of nodes in the list is: " << List.countList() << endl;
    List.pushBack(45);
    List.pushBack(32);
    List.printList();
    List.erase(1);
    List.printList();
    List.begin();
    List.end();
    List.pushFront(69);
    List.begin();
    List.printList();
    List.bubbleSort();
    cout << "Doubly Linked List After Sorting:";
    List.printList();
    List.clear();
    List.empty();*/

    

    // delete front
    List.popFront();

    
    

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Header and options
        DrawText(header, 700, 30, 20, RED);
        
        // Add front
        List.pushFront(1);
        List.pushFront(2);
        List.pushFront(3);
        DrawText(option1, 50, 75, 15, RED);
        /*List.draw(80);*/

        // delete front
        List.popFront();
        DrawText(option2, 50, 100, 15, RED);
        /*List.draw(105);*/
        
        //Add back
        List.pushBack(4);
        List.pushBack(5);
        List.pushBack(6);
        DrawText(option3, 50, 125, 20, RED);
        /*List.draw(130);*/
       
        //DrawText(option4, 50, 150, 20, RED);

        //DrawText(option5, 50, 175, 20, RED);
        //DrawText(option6, 50, 200, 20, RED);
        //DrawText(option7, 50, 225, 20, RED);
        //DrawText(option8, 50, 250, 20, RED);
        //DrawText(option9, 50, 275, 20, RED);
        //DrawText(option10, 50, 300, 20, RED);
        //DrawText(option11, 50, 325, 20, RED);
        //DrawText(option12, 50, 350, 20, RED);
        //DrawText(option13, 50, 375, 20, RED);
        //DrawText(option14, 50, 400, 20, RED);
        //DrawText(option15, 50, 425, 20, RED);
        //DrawText(option16, 50, 450, 20, RED);

        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}


    //do
    //{
    //    /*cout << endl
    //        << " 1 - Insert a node at the front of the list.\n"
    //        << " 2 - Delete a node at the front of the list.\n"
    //        << " 3 - Insert a node at the end of the list.\n"
    //        << " 4 - Delete a node at the end of the list.\n"
    //        << " 5 - Insert a node at an arbitrary location in the list.\n"
    //        << " 6 - Delete a node at an arbitrary location in the list.\n"
    //        << " 7 - Delete a node with a specific value in the list.\n"
    //        << " 8 - Return a count of how many nodes are in the list.\n"
    //        << " 9 - Check if the list is empty.\n"
    //        << " 10 - Return the first node in the list.\n"
    //        << " 11 - Return the last node in the list.\n"
    //        << " 12 - Sort the list.\n"
    //        << " 13 - Clear the contents of the list.\n"
    //        << " 14 - Print the list.\n"
    //        << " 15 - Exit Program.\n\n"
    //        << " Enter your choice and press return: ";*/
    //    cin >> choice;
    //    cout << endl;

    //    switch (choice)
    //    {
    //    case 1:
    //        int insertFront;
    //        cout << "Enter a value to put at the front of the list and press return: ";
    //        cin >> insertFront;
    //        List.pushFront(insertFront);
    //        break;

    //    case 2:
    //        cout << "Deleted the node at the front of the list.\n";
    //        List.popFront();
    //        break;

    //    case 3:
    //        int insertBack;
    //        cout << "Enter a value to put at the front of the list and press return: ";
    //        cin >> insertBack;
    //        List.pushBack(insertBack);
    //        break;

    //    case 4:
    //        cout << "Deleted the node at the end of the list.\n";
    //        List.popBack();
    //        break;

    //    case 5:
    //        //code
    //        break;
    //    case 6:
    //        //code
    //        break;
    //    case 7:
    //        //code
    //        break;
    //    case 8:
    //        //code
    //        break;
    //    case 9:
    //        //code
    //        break;
    //    case 10:
    //        //code
    //        break;
    //    case 11:
    //        //code
    //        break;
    //    case 12:
    //        //code
    //        break;
    //    case 13:
    //        //code
    //        break;

    //    case 14:
    //        cout << "Contents of list >> ";
    //        List.printList();
    //        break;

    //    case 15:
    //        cout << "End of Program.\n";
    //        break;

    //    default:
    //        cout << "Not a Valid Choice. \n"
    //            << "Choose again.\n";
    //        break;
    //    }

    //} while (choice != 15);
    //return 0;

   /* List.pushBack(6);
    List.pushFront(7);
    List.pushFront(1);
    List.pushBack(4);

    cout << "Created DLL is:";
    List.printList();

    List.popFront();

    cout << "popFront DLL is:";
    List.printList();

    List.popBack();
    cout << "popBack DLL is:";
    List.printList();

    List.begin();
    List.end();
    cout << "The number of nodes in the list is: " << List.countList() << endl;

    List.pushFront(3);
    List.pushFront(4);
    List.pushFront(5);

    cout << "New DLL is: ";
    List.printList();

    List.insertAtLocation(24, 3);

    cout << "Inserted DLL is: ";
    List.printList();

    List.erase(5);

    cout << "Removed DLL is: ";
    List.printList();

    List.remove(8);

    cout << "Deleted DLL is: ";
    List.printList();

    List.remove(4);

    cout << "Deleted DLL is: ";
    List.printList();

    cout << "The number of nodes in the list is: " << List.countList() << endl;

    List.pushBack(45);
    List.pushBack(32);
    List.printList();

    List.erase(1);
    List.printList();

    List.begin();


    List.end();

    List.pushFront(69);
    List.begin();
    List.printList();

    List.bubbleSort();
    cout << "Doubly Linked List After Sorting:";
    List.printList();

    List.clear();
    List.empty();

    return 0;*/


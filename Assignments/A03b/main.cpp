/*****************************************************************************
*                    
*  Author:           Paras Raj Shahi
*  Email:            parasshahi700@gmail.com
*  Label:            04 - A03b
*  Title:            Commenting on code
*  Course:           3013 Advanced Structures & Algorithms
*  Semester:         Spring 2022
* 
*  Description:
*              This is a linked list program. It add two linked programs
*              by overloading addition operator.              
* 
*  Usage:
*        N/A
* 
*  Files:           
         main.cpp : driver program
*****************************************************************************/

#include <iostream>

using namespace std;

int A[100];

/**
 * Node
 * 
 * Description:
 *             This is a Node stuct which contain the data in the linked 
 *             list.
 *      
 * Methods:    
 * Public:
 *        Node()
 *        Node(int val) 
 * 
 * Private:
 *      N/A    
 */

struct Node {
    int x;
    Node *next;
    Node() {
        x = -1;
        next = NULL;
    }
    Node(int n) {
        x = n;
        next = NULL;
    }
};

/**
* List
* Description: A class is use to create a linked list.
* Methods:
* public:  
*       List()
*       void Push(int val)    
*       void Insert(int val)
*       void PrintTail()
*       string Print()
*       int Pop()
*       List operator+(const List &Rhs)
*       int operator[](int index)
*       friend ostream &operator<<(ostream &os, List L)
*
* private:
*       N/A
*
*/

class List {
private:
    Node *Head;
    Node *Tail;
    int Size;

public:

    /**
    *
    * Public : List
    * Description: 
    *            Default constructor which creates a new linked list.
    * 
    * param:
    *       N/A
    *
    * return: 
    *       N/A
    */

    List() {
        Head = Tail = NULL;
        Size = 0;
    }
    /**
    *
    * Public method: Push
    * Description: 
    *            Add a node with integer value in the linked list.
    * 
    * param:
    *       int val - integer value to be added into the node.
    *
    * return: 
    *       It doesn't return value.
    */
    void Push(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail) {
            Head = Tail = Temp;
        } else {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

   /**
    *
    * Public method: Insert
    * Description: 
    *            It will add a node with integer value in a specific location of the linked list.
    * 
    * param:
    *       int val - integer value to be added into the node.
    *
    * return: 
    *       It doesn't return value.
    */
  
    void Insert(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }

    /**
    *
    * Public: PrintTail
    * Description: 
    *            Prints the tail value of the linked list.
    * 
    * param:
    *       N/A
    *
    * return: 
    *       It doesn't return value.
    */

    void PrintTail() {
        cout << Tail->x << endl;
    }
    /**
    *
    * Public: Print
    * Description: 
    *            Print the whole list.
    * 
    * param:
    *       N/A
    *
    * return: 
    *       It returns list.
    */
    string Print() {
        Node *Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }
    /**
    *
    * Public: Pop
    * Description: 
    *            It delete an item from the list.
    * 
    * param:
    *       N/A
    *
    * return: 
    *       It returns the value which is popped.
    */
    // not implemented
    int Pop() {
        Size--;
        return 0; //
    }
    /**
    *
    * Public: List operator+
    * Description: 
    *            Add two lists together to form a new list.
    * 
    * param:
    *       const List &Rhs
    *
    * return: 
    *       new linked list
    */
    List operator+(const List &Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    /**
    *
    * Public: operator[]
    * Description: 
    *            This function reutrns an int value value as if the list were an array.
    * 
    * param:
    *       int index
    *
    * return: 
    *       the integer value that is accessed.
    */

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index) {
        Node *Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }
    /**
    * Overloaded operator that allows ostream operator to read linked list variable and print it out.
    * 
    * param:
    *       ostream &os : ostream object.
    *       List L : List to be printed.
    *
    * return: 
    *       it will return ostream.
    */
    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv) {

  
    List L1;
    List L2;

    for (int i = 0; i < 25; i++) {
        L1.Push(i);
    }

    for (int i = 50; i < 100; i++) {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;
    cout << L3 << endl;

    cout << L3[5] << endl;
    return 0;
}

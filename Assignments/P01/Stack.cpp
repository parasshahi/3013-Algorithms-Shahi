/*****************************************************************************
*
*  Author:           Paras Raj Shahi
*  Email:            parasshahi700@gmail.com
*  Label:            05 - P01
*  Title:            Resizing the Stack
*  Course:           3013 Advanced Structures & Algorithms
*  Semester:         Spring 2022
*
*  Description:
*
*  Usage:
*        N/A
*
*  Files:
         main.cpp : driver program
*****************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * ArrayStack
 *
 * Description:
 *      Array based stack
 *
 * Public Methods:
 *      - See class below
 *
 * Usage:
 *      - See main program
 *
 */
class ArrayStack{
private:
  int *A;           // pointer to array of int's
  int size;         // current max stack size
  int top;          // top of stack

  int noItems=0;  //number of items in an array

  double ShrinkThreshold = 0.15;
  double EnlargeThreshold = 0.85;
  double GrowThreshold = 2.0;
  double ReduceThreshold = 0.5;
  int maxSize = 0;
  int maxSizeAttained = 0; //maximum items ever reached
  int NumberOfResizes = 0;


public:
 /**
  * ArrayStack
  *
  * Description:
  *      Constructor no params
  *
  * Params:
  *     - None
  *
  * Returns:
  *     - NULL
  */
  ArrayStack(){
    size = 30;
    A = new int[size];
    top = -1;

  }

 /**
  * ArrayStack
  *
  * Description:
  *      Constructor size param
  *
  * Params:
  *     - int size
  *
  * Returns:
  *     - NULL
  */
  ArrayStack(int s){
    size = s;
    A = new int[s];
    top = -1;
  }

 /**
  * Public bool: Empty
  *
  * Description:
  *      Stack empty?
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      [bool] true = empty
  */
  bool Empty(){
    return (top <= -1);
  }

 /**
  * Public bool: Full
  *
  * Description:
  *      Stack full?
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      [bool] true = full
  */
  bool Full()
  {
    return (top >= size-1);
  }
  void CheckResize()
  {
  if (size > 15 || Empty())
  {
    ContainerShrink();
  }
  if(Full())
  {
    ContainerGrow();
  }


}

 /**
  * Public int: Peek
  *
  * Description:
  *      Returns top value without altering the stack
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      [int] top value if any
  */
  int Peek(){
    if(!Empty()){
      return A[top];
    }

    return 0;
  }

 /**
  * Public int: Pop
  *
  * Description:
  *      Returns top value and removes it from stack
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      [int] top value if any
  */
  int Pop(){
    if(!Empty()){

      return A[top--];
;
    }

    return 0;
  }

 /**
  * Public void: Print
  *
  * Description:
  *      Prints stack to standard out
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      NULL
  */
  void Print(){
    cout<<"##############################################\n";
    cout<<"Assignment 4 - Resizing the Stack\n";
    cout<<"CMPS 3013\n";
    cout<<"Paras Raj Shahi\n\n\n";
    cout<<"Config Params:\n";
    cout<<"\t\tFull Threshold: "<<GrowThreshold<<"\n";
    cout<<"\t\tShrink Threshold: "<<ShrinkThreshold<<"\n";
    cout<<"\t\tGrow Ratio: "<<EnlargeThreshold<<"\n";
    cout<<"\t\tShrink Ratio: "<<ReduceThreshold<<"\n";
    cout<<"\n";
    cout<<"Processed\n";
    cout<<"\n";
    cout<<"Max Stack Size: "<<getMaxSize()<<"\n";
    cout<<"End Stack Size: "<<size<<"\n";
    cout<<"Stack resized: "<<NumberOfResizes<<"\n";
    cout<<"##############################################\n";


  }
/** \brief check the stack operations push (+) or pop (-) and keep track of the number of items, maxSize and maxSizeAttained
 *
 * \param string
 * \param
 * \return void
 *
 */

  void addItem(string sign){

      if (sign=="+"){
        maxSize++;
        maxSizeAttained = std::max(maxSizeAttained,maxSize);


      }
      else{
         maxSize--;
         maxSizeAttained = std::max(maxSizeAttained,maxSize);


      }

  }
/** method to track maximum size attained
 *params : null
 *
 * \return int maxSizeAttained
 *
 */

  int getMaxSize(){
  return maxSizeAttained;
  }
/** \brief method to track the size of the stack
 *
 * params : null
 * \return the size of the stack
 *
 */

  int getSize(){
  return size;
  }

 /**
  * Public bool: Push
  *
  * Description:
  *      Adds an item to top of stack
  *
  * Params:
  *      [int] : item to be added
  *
  * Returns:
  *      [bool] ; success = true
  */
  bool Push(int x){
    if(Full()){
      ContainerGrow();
    }
    if(!Full()){
      A[++top] = x;

      return true;
    }

    return false;

  }

 /**
  * Public void: Resize
  *
  * Description:
  *      Resizes the container for the stack by doubling
  *      its capacity
  *
  * Params:
  *      NULL
  *
  * Returns:
  *      NULL
  */
  void ContainerShrink()
{
  int newSize = size * ReduceThreshold; //new size
  int *temp = new int[newSize];
  for (int i = 0; i < top; i++)
  {
    temp[i] = A[i];
  }
  delete[] A;
  size = newSize;
  A = temp;
  NumberOfResizes++;


}
  void ContainerGrow(){
    int newSize = size*GrowThreshold;
    int *B = new int[newSize];

    for(int i=0;i<size;i++){
      B[i] = A[i];
    }

    delete [] A;

    size = newSize;
    A = B;
    NumberOfResizes++;


  }


};
// MAIN DRIVER
int main(int argc, char* argv[] ) {
  int y = 0;
ArrayStack stack;
      ifstream infile;
      infile.open("data.dat"); //read the file for test data
      int stackSize ;
      cout<<"Enter the stack size"<<endl;//request for user inputs
      cin>>stackSize;//wait for user input
      if (stackSize<=0){
        stack = ArrayStack();//initialize the stack
      }
      else{
        stack = ArrayStack(stackSize);//initialize the stack
      }


     while(infile >> y){
        if(y%2 == 0){
        stack.Push(y);
        stack.addItem("+");

        }
        else{
        stack.Pop();
        stack.addItem("-");


        }

      }

      stack.Print();

      //return 0;
    }

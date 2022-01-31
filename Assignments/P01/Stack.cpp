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

  double ShrinkThreshold = 0.15;
  double EnlargeThreshold = 0.85;
  double GrowThreshold = 2.0;
  double ReduceThreshold = 0.5;
  int maxSize = 0;
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
    size = 10;
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
  bool Full(){
    return (top >= size-1);
  }
  void CheckResize()
{
  if (size > 15 && Empty())
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
    cout<<"Max Stack Size: "<<maxSize<<"\n";
    cout<<"End Stack Size: "<<size<<"\n";
    cout<<"Stack resized: "<<NumberOfResizes<<"\n";
    cout<<"##############################################\n";


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
  int newSize = size - 1; //new size
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
    int newSize = size*2;       
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
      ifstream infile;
      infile.open(argv[1]);       
      ArrayStack stack;
      while(infile >> y){ 
        if(y%2 == 0){
        
        stack.Push(y);
        }
        else{
        
        stack.Pop();             
        }      
      }
      stack.Print();
      //return 0;
    }

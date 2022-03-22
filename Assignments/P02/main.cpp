
/*****************************************************************************
*
*  Author:           Paras Raj Shahi
*  Email:            parasshahi700@gmail.com
*  Label:            06 - P02
*  Title:            Processing in Linear Time 
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
#include "mygetch.hpp"
#include "termcolor.hpp"
#include "timer.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

#define RED termcolor::red
struct wordNodes{
   public: 
      wordNodes(string str){
        word = str;
        next = nullptr;
      };
    wordNodes(string str, wordNodes* N){
      word = str;
      next = N;
    }
  string word;
  wordNodes* next;
};
class LL
{
  public:
     wordNodes* head;
     LL()
     {
        head = nullptr;
     }
   void add(std::string word)
        {
            
            if(head == nullptr)
            {
                head = new wordNodes(word, nullptr);
            }

            else if(head->next == nullptr)
            {
                head->next = new wordNodes(word, nullptr);
            }

            else
            {
                wordNodes* temp = head;

                while(temp->next)
                {
                    temp = temp->next;
                }

                temp->next = new wordNodes(word, nullptr);
            }
        }
};
/**
 * Description:
 *      Originally wrote this to count size of input file so
 *      I could allocate enough memory for an array of strings
 *      but I went with a vector below. But I'm keeping it and
 *      using it anyway!
 * Params:
 *      string file_name - file to get the line count
 * 
 * Returns:
 *      int - line count
 */
int CountLines(string file_name) {
    ifstream inFile(file_name);
    return count(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>(), '\n');
}

/**
 * Description:
 *      Loads a file of strings (words, names, whatever) reading them in
 *      with one word per line. So words must be delimited by newlines '\n'
 * Params:
 *      string file_name - file to get the line count
 * 
 * Returns:
 *      int - line count
 */

LL LoadDict(std::string file_name) 
{
    ifstream fin;                            // file to get animal names
    int count = (CountLines(file_name) + 1); // get size of input file
    LL dictList;                 
    fin.open(file_name);                    // open file for reading
    std::string readIn;
    for (int i = 0; i < count; i++) 
    {
        fin >> readIn;
       dictList.add(readIn);         // read in words
    }

    return dictList;
}
vector<string> FindMatches(LL dictList, std::string substring) 
{
    vector<string> matches; // to hold any matches
    size_t found;           // size_t is an integer position of
                            // found item. -1 if its not found.

    wordNodes* temp = dictList.head; //points to head

    while(temp->next)       // loop through list
    {   
        found = temp->word.find(substring);    // check for substr match

        if(found == 0)           
        {  
            matches.push_back(temp->word);     // add to matches
        }

        temp = temp->next; // traverseres list
    }

    return matches;
}

int main() {
    char k;                 // holder for character being typed
    string word = "";       // var to concatenate letters to
    LL ListofWords;
    vector<string> words; // any matches found in vector of animals
    ofstream fout("temp.txt");
    
    Timer T;   // create a timer
    T.Start(); // start it
    T.End(); // end the current timer
    cout << "Type keys and watch what happens. Type capital Z to quit." << endl;

    // While capital Z is not typed keep looping
    while ((k = getch()) != 'Z') {
        T.Start(); // start it
        // Tests for a backspace and if pressed deletes
        // last letter from "word".
        if ((int)k == 127) {
            if (word.size() > 0) {
                word = word.substr(0, word.size() - 1);
            }
        } else {
            // Make sure a letter was pressed and only letter
            if (!isalpha(k)) {
                cout << "Letters only!" << endl;
                continue;
            }

            // We know its a letter, lets make sure its lowercase.
            // Any letter with ascii value < 97 is capital so we
            // lower it.
            if ((int)k < 97) {
                k += 32;
            }
            word += k; // append char to word
        }

      }  
    return 0;
}

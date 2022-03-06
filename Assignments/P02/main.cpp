
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
vector<string> LoadDictionary(string file_name) {
    ifstream fin;                            // file to get animal names
    int count = (CountLines(file_name) + 1); // get size of input file
    LL ListofWords;             
    fin.open("dictionary.txt"); // open file for reading

    string read;
    for (int i = 0; i < count; i++) {
        fin >> read; 
        ListofWords.add(read);
      }  
    //return ListofWords;
}

/**
 * Description:
 *      Finds partial matches in an array of strings and returns them. It
 *      doesn't matter where in the string the match is.
 * Params:
 *      vector<string>  array       - array to search
 *      string          substring   - substring to search for in each word
 * 
 * Returns:
 *      vector<string> - holding all the matches to substring
 */
/*vector<string> Findwords(const LL, ListofWords, string substr) {
    vector<string> words; 
    size_t found; 
    
    return words;
}
*/
int main() {
    char k;                 
    string word = "";       
    LL ListofWords;
    vector<string> words; 
    int loc;                

    ofstream fout("temp.txt");

    Timer T;   // create a timer
    T.Start(); // start it

    ListofWords = LoadDictionary("dictionary.txt");

    T.End(); 

   
    cout << T.Seconds() << " seconds to read in and print json" << endl;
    cout << T.MilliSeconds() << " milli to read in and print json" << endl;
    
    cout << "Type keys and watch what happens. Type capital Z to quit." << endl;

    
    while ((k = getch()) != 'Z') {
        T.Start(); // start it
        
        if ((int)k == 127) {
            if (word.size() > 0) {
                word = word.substr(0, word.size() - 1);
            }
        } else {
            
            if (!isalpha(k)) {
                cout << "Letters only!" << endl;
                continue;
            }

            
            if ((int)k < 97) {
                k += 32;
            }
            word += k; 
        }
      
        words = findwords(dictionary, word);

        
    return 0;
}

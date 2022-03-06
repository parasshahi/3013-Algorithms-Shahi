
/*****************************************************************************
*
*  Author:           Paras Raj Shahi
*  Email:            parasshahi700@gmail.com
*  Label:            08 - P03
*  Title:            Processing in Trie Tree Time 
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
#include <list>
#include <fstream>
#include "nlohmann/json.hpp"
#include "timer.hpp"

using namespace std;

using json = nlohmann::json;

#define MAX_CHARS (26)

struct WordNode {

    WordNode *word[MAX_CHARS];

    bool isEnd;

    WordNode() {

        for (auto &i: this->word) {
            i = nullptr;
        }

        this->isEnd = false;
    }
};

class Trie {
    WordNode *root;

    WordNode *_searchSubString(string subStr) {
        WordNode *currNode = root;
        for (char val: subStr) {
            if (currNode->word[val - 'a'] == nullptr) {
                return nullptr;
            }
            currNode = currNode->word[val - 'a'];
        }
        return currNode;
    }

public:
    Trie() {
        root = new WordNode();
    }

    ~Trie() {

    }

    void addWord(string word) {
        WordNode *currNode = root;
        for (char val: word) {
            if (currNode->word[val - 'a'] == nullptr) {
                currNode->word[val - 'a'] = new WordNode();
            }
            currNode = currNode->word[val - 'a'];
        }
        currNode->isEnd = true;
    }

    bool searchWord(string word) {
        WordNode *currNode = root;
        for (char val: word) {
            if (currNode->word[val - 'a'] == nullptr) {
                return false;
            }
            currNode = currNode->word[val - 'a'];
        }

        return currNode->isEnd;
    }

    void suggestions(WordNode *root, string subStr, list<string> &results) {

        WordNode *curr = root;

        if (curr == nullptr) {
            return;
        }

        if (curr->isEnd) {
            results.push_back(subStr);
        }

        for (int i = 0; i < MAX_CHARS; i++) {

            string str = subStr + string(1, (char) ('a' + i));

            if (curr->word[i] != nullptr) {
                suggestions(curr->word[i], str, results);
            }

        }
    }

    list<string> dictWords(string subStr) {

        WordNode *currNode = _searchSubString(subStr);

        if (currNode != nullptr) {
            list<string> result;
            suggestions(currNode, subStr, result);
            return result;
        }

        return list<string>();
    }
};

int main() {

    // Declare variables
    Timer T;

    Trie trie;

    string search;

    fstream file;

    cout << "Enter a string:" << endl;
    getline(cin, search);

    // Start Timer
    T.Start();

    // Open file
    file.open("dict_w_defs.json", ios::in);

    // check file stream
    if (!file) {
        cout << "Failed to open dictionary file";
        return 0;
    }

    // Parse data
    json data = json::parse(file);

    // close file
    file.close();

    // add keys to trie tree
    for (const auto &item: data.items()) {
        string key = item.key();

        // sanitize key
        key.erase(std::remove(key.begin(), key.end(), ' '), key.end());
        key.erase(std::remove(key.begin(), key.end(), '-'), key.end());

        // Check for empty strings
        if (!key.empty()) {
            trie.addWord(key);
        }
    }


    // Generate suggestions
    list<string> words = trie.dictWords(search);

    // End timer
    T.End();

    // Iterator
    auto itr = words.begin();

    // Output Header
    cout << endl << words.size() << " words found in " << T.Seconds() << " seconds" << endl;

    cout << endl;

    // Output Words
    for (int i = 0; i < 10; ++i) {
        cout << *itr << endl;
        itr++;
    }

    cout << endl;

    return 0;
}

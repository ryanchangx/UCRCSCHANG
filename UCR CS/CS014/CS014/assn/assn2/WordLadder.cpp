#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <iterator>
#include "WordLadder.h"
using namespace std;

WordLadder::WordLadder(){}

//writes the dict file to list
WordLadder::WordLadder(const string& listFile){
    ifstream inFS;
    inFS.open(listFile);
    if(!inFS.is_open()){
        cerr << "Could not open file." << endl;
        exit(1);
    }
    string word;
    while(getline(inFS,word)){
        dict.push_back(word);
    }
    inFS.close();
}

WordLadder::~WordLadder(){}

void WordLadder::outputLadder(const string& start, const string& end){
    stack<string> theStack;
    theStack.push(start);
    queue<stack<string>> theQueue;
    theQueue.push(theStack);
    //if you erase you dont check the one after the one that is erased
    while(!theQueue.empty()){
        list<string>::iterator iter;
        for(iter = dict.begin(); iter != dict.end(); ++iter){
            if(offByOne(*iter,theQueue.front().top())){
                if(*iter == end){
                    theQueue.front().push(end);
                    outputLadder(theQueue.front(), start);
                    return;
                }
                else{
                    stack<string> newStack = theQueue.front();
                    newStack.push(*iter);
                    theQueue.push(newStack);
                    iter = dict.erase(iter); //what node does it point to
                    --iter;
                }
            }
        }
        theQueue.pop();
    }
    cout << "No Ladder found!" << endl;
}

void WordLadder::outputLadder(stack<string>& s, const string& start){
    while(s.top() != start){
        cout << s.top() << endl;
        s.pop();
    }
    cout << start << endl;
}

void WordLadder::printDictionary(){
    for(list<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter){
        cout << *iter << " ";
    }
}

bool WordLadder::offByOne(const string& s1, const string& s2){
    if(s1 == s2){
        return false;
    }
    bool offby1 = false;
    for(unsigned int i = 0; i < s1.size(); ++i){
        if(s1.at(i) != s2.at(i) && offby1){
            return false;
        }
        else if(s1.at(i) != s2.at(i)){
            offby1 = true;
        }
    }
    return offby1;
}

/**
 * Create a stack of strings.
 * Push the start word on this stack.
 * Create a queue of stacks.
 * Enqueue this stack.
 *
 * while the queue is not empty
 *  for each word in the dictionary
 *      if a word is exactly 1 letter different than the top string of the front stack
 *          then
 *              if this word is the end word
 *              then
 *                  word ladder found, it is the front stack plus the end word
 *              else
 *                  Make a copy of the front stack.
 *                  Push the found word onto the copy.
 *                  Enqueue the copy.
 *      Dequeue front stack.
 * end while loop
 */

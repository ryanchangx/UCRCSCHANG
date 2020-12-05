#include <iostream>
#include <cstdlib>
#include <list>

#define SEQ_SIZE 100
#define ASSERT(condition) { if(condition) { cerr << "Assertion passed: " << #condition << endl; } else { cerr << "Assertion failed: " << #condition << endl; } }

using namespace std;

void InsertionSort(list<int>& S) {
    list<int>::iterator iter;
    list<int>::iterator iter2;
    //keeps track of the oustide loop
      for(iter = next(S.begin()); iter != S.end(); ++iter){
        iter2 = iter;
        while(iter2 != S.begin() && *iter2 < *prev(iter2)){
          swap(*iter2,*prev(iter2));
          --iter2;
        }
      }
}

void Display(list<int>& S) {
  for(list<int>::iterator it = S.begin(); it != S.end(); ++it)
    cout << *it << " ";
  cout << endl;
}

bool InsertionSortBackwards() {
    list<int> seq;
    
    for (int i = SEQ_SIZE; i > 0; i--) {
        seq.push_back(i);
    }
    
    // cout << "Unsorted list: " << endl;
    // Display(seq);
    
    InsertionSort(seq);
    
    // cout << "Sorted list: " << endl;
    // Display(seq);
    
    list<int>::iterator iter = seq.begin();
    int key = *iter;
    
    for(iter++; iter != seq.end(); iter++)
    {
        if(!(key <= *iter))
            return false;
        else
            key = *iter;
    }
    
    return true;
}

bool InsertionSortRandom() {
    list<int> seq;
    
    for (int i = SEQ_SIZE; i > 0; i--) {
        seq.push_back((rand() % SEQ_SIZE) + 1);
    }
    
    // cout << "Unsorted list: " << endl;
    // Display(seq);
    
    InsertionSort(seq);
    
    // cout << "Sorted list: " << endl;
    // Display(seq);
    
    list<int>::iterator iter = seq.begin();
    int key = *iter;
    
    for(iter++; iter != seq.end(); iter++)
    {
        if(!(key <= *iter))
            return false;
        else
            key = *iter;
    }
    
    return true;
}

int main() {
    ASSERT(InsertionSortBackwards());
    ASSERT(InsertionSortRandom());
}

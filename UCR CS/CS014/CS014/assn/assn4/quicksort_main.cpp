#include "Quicksort.H"
#include <iostream>
#include <cstdlib> 
#include <vector>
#include <algorithm>

#define SEQ_SIZE 150
#define ASSERT(condition) { if(condition) { cerr << "Assertion passed: " << #condition << endl; } else { cerr << "Assertion failed: " << #condition << endl; } }

using namespace std;

// template<typename T>
// vector<T>& QuickSort(vector<T>& S, string pivot) {
//     sort(S.begin(), S.end());
//     return S;
// }

template<typename T>
bool QuickSortRandom(vector<T>& seq) {
    // cout << "Unsorted list: ";
    // Display(seq);
    // cout  << endl;
    
    QuickSort(seq, "random");
    
    // cout << "Sorted list: ";
    // Display(seq);
    // cout  << endl;
    
    typename vector<T>::iterator iter = seq.begin();
    int key = *iter;
    
    for(iter++; iter != seq.end(); iter++)
    {
        if(!(key <= *iter))
            return false;
        else
            key = *iter;
    }
    // for (vector<int>::iterator it = seq.begin() ; it != seq.end(); ++it)
    // cout << *it << "\t";
    // cout << endl;
    return true;
}

template<typename T>
bool QuickSortMedianThree(vector<T>& seq) {
    // cout << "Unsorted list: ";
    // Display(seq);
    // cout  << endl;
    
    QuickSort(seq, "median_three");
    
    // cout << "Sorted list: ";
    // Display(seq);
    // cout  << endl;
    
    typename vector<T>::iterator iter = seq.begin();
    int key = *iter;
    
    for(iter++; iter != seq.end(); iter++)
    {
        if(!(key <= *iter))
            return false;
        else
            key = *iter;
    }
    // for (vector<int>::iterator it = seq.begin() ; it != seq.end(); ++it)
    // cout << *it << "\t";
    // cout << endl;
    return true;
}

int main() {
    vector<int> seq1;
    
    for (int i = SEQ_SIZE; i > 0; i--) {
        seq1.push_back((rand() % SEQ_SIZE) + 1);
    }
    ASSERT(QuickSortRandom<int>(seq1));
    
    vector<int> seq2;
    
    for (int i = SEQ_SIZE; i > 0; i--) {
        seq2.push_back((rand() % SEQ_SIZE) + 1);
    }
    ASSERT(QuickSortMedianThree<int>(seq2));
}
/**
 * Course: CS014 Summer 2020
 *
 * First Name: Ryan
 * Last Name: Chang
 * Username: rchan123
 * email address: rchan123@ucr.edu
 *
 *
 * Assignment: assn4
 * Filename : Quicksort.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#ifndef _quicksort_
#define _quicksort_

#include<vector>
#include<algorithm>
#include<string>
#include<iterator>
#include<cstdlib>
#include<iostream>
using namespace std;

//maybe make a helper that takes in 2 arguments, and calls a quicksort that calls 3 arguments
template <typename T> vector<T> quicksort(vector<T>& v,const string& mode);
template <typename T> int Partition(vector<T>& v, int pivot);
template <typename T> int median(vector<T>& v);
template <typename T> void Display(const vector<T>& v);
template <typename T> int random(vector<T>& v);

template <typename T> 
vector<T> QuickSort(vector<T>& v,const string& mode){
    //if the size is small, then do insertion sort
    if(v.size() > 1){
        int j;
        //partion will make all values less than pivot be before the pivot
        if(mode == "median_three") j = Partition(v,median(v));
        else if(mode == "random") j = Partition(v,random(v));
        
        //used to make subvectors left and right
        typename vector<T>::iterator iter = v.begin() + j;
        vector<T> left(v.begin(),iter);
        vector<T> right(iter,v.end());

        //recursive calls to quicksort
        left = QuickSort(left,mode);
        right = QuickSort(right,mode);
        
        //put the two parts together
        left.insert(left.end(),right.begin(),right.end());
        v = left;
    }
    //gets returns vector if size 1 or 0, already sorted.
    return v;
}

template <typename T>
int Partition(vector<T>& v, int pivot){
    T temp;
    //m keeps track of the previous position, only in the case that a swap occurs.
    int m = -1;
    //for all the values in the vector
    for(int i = 0; i < pivot; ++i){
        //if the value at a point in the vector is less than the value at the pivot(which is the back in this case)
        if(v.at(i) <= v.at(pivot)){
            //swap to the back since it is in the right spot; values that are greater than the pivot will stay where they are and eventually end up on the right side. 
                //m represents the index before where the pivot will be after the pivot returns to it's correct spot
            ++m;
            temp = v.at(m);
            v.at(m) = v.at(i);
            v.at(i) = temp;
        }
    }
    //swap the index back where it belongs, as the number after m must be greater than or equal to the pivot.
        //hence the pivot is now in its final position in the vector.
    temp = v.at(m+1);
    v.at(m+1) = v.at(pivot);
    v.at(pivot) = temp;
    //returning the index of the pivot.
    return m+1;
}

template <typename T>
int median(vector<T>& v){
    T temp;
    vector<int> pivots;
    for(int i = 0; i < 3; ++i){
        pivots.push_back(rand() % v.size());
    }
    //get the median by picking the middle rand in a sorted list.
    stable_sort(pivots.begin(),pivots.end());
    //swaps the selected value with the value at the end.
    int rMed = pivots.at(1);
    int k = v.size() - 1;
    temp = v.at(k);
    v.at(k) = v.at(rMed);
    v.at(rMed) = temp; 
    return k;
}

template <typename T> 
int random(vector<T>& v){
    T temp;
    //swap the random number with the value at the end.
    int rNum = rand() % v.size();
    int k = v.size() - 1;
    temp = v.at(k);
    v.at(k) = v.at(rNum);
    v.at(rNum) = temp;  
    return k;
}

template <typename T> 
void Display(const vector<T>& v){
    for(unsigned int i = 0; i < v.size(); ++i){
        cout << v.at(i) << " ";
    }
}

#endif
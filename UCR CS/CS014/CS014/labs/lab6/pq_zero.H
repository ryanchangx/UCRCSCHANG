/**
 * Course: CS014 Summer 2020
 *
 * First Name: Ryan
 * Last Name: Chang
 * Username: rchan123
 * email address: rchan123@ucr.edu
 *
 *
 * Assignment: lab6
 * Filename : pq_zero.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include<iostream>
#include<cstdlib>
#include<map>
#include<vector>
using namespace std;

//make sure this is a PRIORITY BASED QUEUE, not based on THE ITEM, but the PRIORITY
  //fix yo dumbass code
template< class Item > 
class pq_zero {
private:
  vector<Item> heap; // The heap expands/shrinks to fit data
  typedef int indx;  // index with heap
  map<Item,indx> index;  // records each Item's place in heap
  map<Item,float> priority; // records each Item's priority
  
  //find children can only be used on a parent node
    //left child = 2 * (parent index) + 1
    //right child = 2 *(parent index) + 2
    //returns -1 if invalid
  indx leftChild(indx par){
      return (2 * par) + 1;
  }
  indx rightChild(indx par){
      return (2 * par) + 2;
  }
  
  //find parents gives the position of the parent based on the location of the children, 
    //passes in index of the child
      //parent index = (child index - 1) / 2
  indx pIndex(indx child){
      return ((child - 1) / 2);
  }
  
  void swap(indx i, indx j){
    //swap heap
    Item temp = heap.at(i);
    heap.at(i) = heap.at(j);
    heap.at(j) = temp;
    
    //swap indicies
    indx temp1 = index.at(heap.at(i));
    index.at(heap.at(i)) = index.at(heap.at(j));
    index.at(heap.at(j)) = temp1;
  }
  
  //lower priority to be at the top
  
  //add maps to this.
  //find parent
  //USE ON CHILD PARENT
  void percolate_up(indx i){ 
    //pero up keeps going until the node is at the right spot
    //while its not the root
      //set the parent index of the node
      //if node is at right spot, then stop
      //otherwise, swap parent and child
      //set new child to old parent
    while(i > 0){
      indx parentIndex = pIndex(i);
      if(priority.at(heap.at(i)) >= priority.at(heap.at(parentIndex))){
        return;
      }
      else{
        swap(i,parentIndex);
        i = index.at(heap.at(parentIndex));
      }
    }
  }
  //find child
  //ONLY USE ON PARENT INDEX
  void percolate_down(indx i){ // takes in root
  //everytime this is called, new children are set based on the formulae
    indx left = leftChild(i);
    indx right = rightChild(i);
  // if the right index is the edge WDO WE EVEN NEED THIS HAH WE DONT
    // if(right == size()-1){
    //   if(priority.at(heap.at(i)) > priority.at(heap.at(right))){
    //     swap(i,right);
    //     return;
    //   }
    // }
  //iff the left edge is it then...
    if(left == size() - 1){
      if(priority.at(heap.at(i)) > priority.at(heap.at(left))){
        swap(i,left);
        return;
      }
    }
    if(right > size()-1 || left > size()-1){
      return;
    }
    //if prio is the same, then swap
    //two if statements, checks if left OR right, not together, make 2 if statements
    //checks if both leafs exist
    if(priority.at(heap.at(left)) <= priority.at(heap.at(right))){
      if(priority.at(heap.at(i)) >= priority.at(heap.at(left))){
        swap(left,i);
        percolate_down(left);
        return;
      }
    }
    else if(priority.at(heap.at(i)) >= priority.at(heap.at(right))){
      swap(right,i);
      percolate_down(right);
      return;
    }
  }
  //swap helper function
  //set prio and values first, and then indices
public: 
  // These use the min-heap functions above.
  int size() const{
    return heap.size();
  }
  bool empty() const{
    return heap.size() == 0;
  }
  const Item& front() const{
    return heap.at(0);
  }
  //only percolates down
    //percolate node all the way down, and then use pop_back
  void pop(){
      if(size() == 0){
       return; 
      }
        //remove from map
      if(size() > 1){
        swap(0,size()-1);
        //remove from map
        priority.erase(heap.at(heap.size()-1));
        index.erase(heap.at(heap.size()-1));
        heap.pop_back();
        percolate_down(0);
      }
      else{
        //remove from map
        priority.erase(heap.at(heap.size()-1));
        index.erase(heap.at(heap.size()-1));
        heap.pop_back();
        return;
      }
  }
  //should be able to percolate on every single node
  void push( const Item& w, float prio ){
      //push into vector
          //map priority
          //Highest priority is at the root
      //map index from vector
      //creation of the node, in the WRONG SPOT
      //if thing is already in the heap
      
      //if the priority is the same, then update the priority with the new priority
      for(unsigned int i = 0; i < heap.size(); ++i){
        if(heap.at(i) == w){
          priority.at(w) = prio;
          percolate_down(0);
          return;
        }
      }
      heap.push_back(w);
      priority.insert(pair<Item,float>(w,prio));
      index.insert(pair<Item,indx>(w,heap.size()-1));
      percolate_up(index.at(w));
      percolate_down(0);
      return;
  }
  // void display(){
  //   for(unsigned int i = 0; i < heap.size(); ++i){
  //     cout << "Key: " << heap.at(i) <<
  //     ", VI: " << i <<
  //     ", I: " << index.at(heap.at(i)) << 
  //     ", P: " << priority.at(heap.at(i)) << endl;
  //   }
  // }
};
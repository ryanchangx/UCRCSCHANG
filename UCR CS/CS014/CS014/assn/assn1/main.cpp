/**
 * Course: CS014 Summer 2020
 *
 * First Name: Ryan
 * Last Name: Chang
 * Username: rchan123
 * email address: rchan123@ucr.edu
 *
 *
 * Assignment: assn1
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 


#include <iostream>
#include <vector>
#include "MyList.h"

using namespace std;

int main() {

  char c = 'a';
  MyList l1;
  
  cout << "push_back z: " ;
  l1.push_back('z');
  l1.print();
  
  l1.pop_back();
  cout << "pop_back z: " ;
  l1.print();
  
  cout << "push_front 0 0 z 0 z: " ;
  l1.push_front('0');
  l1.push_front('0');
  l1.push_front('z');
  l1.push_front('0');
  l1.push_front('z');
  l1.print();
  
  int loc_size = l1.size();
  cout << "array style print: " ;
  for(int i = 0; i < loc_size; i++)
    cout << l1[i] << " ";
  cout << endl;
  
  cout << "insert_at_pos a 0 on left and right of middle z: " ;
  l1.insert_at_pos(2, '0');
  l1.insert_at_pos(5, '0');
  l1.print();
  
  cout << "push_back letters f-j: ";
  for(int i = 0; i < 10; i++)
    l1.push_back(c+i);
  l1.print();
  
  cout << "pop_front z z: ";
  for(int i = 0; i < 2; i++)
    l1.pop_front();
  l1.print();
  
  cout << "pop_back f-j: ";
  for(int i = 0; i < 5; i++)
    l1.pop_back();
  l1.print();
  
  cout << "reverse odd sized list: ";
  l1.reverse();
  l1.print();
  
  cout << "push_front f: ";
  l1.push_front('f');
  l1.print();
  
  cout << "reverse even sized list: ";
  l1.reverse();
  l1.print();
  
  // make some copies for later use
  cout << "Construct new lists l2,l3,l4:\n";
  cout << "MyList l4(l1);\nMyList l3 = l4;\nMyList l2(l3);" << endl;
  MyList l4(l1);
  MyList l3 = l4;
  MyList l2(l3);
  
  // test pop_back
  cout << "pop_back entire list, l1: ";
  loc_size = l1.size();
  
  for(int i = 0; i < loc_size; i++)
    l1.pop_back();
  l1.print();

  // test reverse
  cout << "reverse empty list, l1: ";
  l1.reverse();
  l1.print();

  cout << "pop_back entire list but one item, l2: ";
  loc_size = l2.size();
  
  for(int i = 0; i < loc_size-1; i++)
    l2.pop_back();
  l2.print();;
  
  cout << "reverse one item list, l2: ";
  l2.reverse();
  l2.print();
  
  cout << "pop_back entire list but two items, l3: ";
  loc_size = l3.size();
  
  for(int i = 0; i < loc_size-2; i++)
    l3.pop_back();
  l3.print();
  
  cout << "reverse two item list, l3: ";
  l3.reverse();
  l3.print();
  
  cout << "list l4: ";
  l4.print();
  
  cout << "list l4 + l3: ";
  l4 + l3; 
  l4.print();
  
  cout << "list l4 + l2: ";
  l4 + l2; 
  l4.print();
  
  cout << "list l4 + l1: ";
  l4 + l1; 
  l4.print();
  
  cout << "Good Bye!" << endl;
  
  //NEED TO FIX: merge_list, find(query_str),
  /*
  MyList list1 = MyList("LIMELIGHT");
  list1.print();
  MyList list2 = MyList("LIGHT");
  list2.print();
  
  cout << list1.find(list2) << endl;

  
  
  MyList list1;
  list1.push_back('0');
  list1.push_back('2');
  list1.push_back('4');
  list1.push_back('5');
  list1.push_back('6');
  list1.push_back('8');
  list1.print();
  cout << endl;
  
  MyList list2;
  list2.push_back('0');
  list2.push_back('1');
  list2.push_back('3');
  list2.push_back('5');
  list2.push_back('7');
  list2.push_back('9');
  list2.print();
  cout << endl;
  
  MyList list3;
  list3.merge_list(list1,list2);
  list3.print();
  cout << endl;
  */
  return 0;
}
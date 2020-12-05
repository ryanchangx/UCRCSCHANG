#ifndef __NODE_H
#define __NODE_H

#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

class Node {

public:
  Node* left;
  Node* right;
  string str;
  int count;
  
public:
  Node ( string s ) { left = right = NULL; count = 1; str = s; };
  Node ( ) { left = right = NULL; count = 0; str = "\0";};
  ~Node ( );
  const Node& operator=( const Node& right );
  
  // Add any additional variables/functions here
  
};

#endif
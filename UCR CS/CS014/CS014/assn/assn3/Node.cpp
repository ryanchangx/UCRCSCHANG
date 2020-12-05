#include "Node.h"
#include <iostream>

using namespace std;

Node::~Node(){
  if (right) {
    delete right;
  }

  if (left) {
    delete left;
  }
}

//------------------------------------------------------------------------

const Node& Node::operator=( const Node& right ) {
  if ( &right != this ) {
    this->str = right.str;
    this->count = right.count;
  }
  return *this;
}
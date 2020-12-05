#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

using namespace std;

class Tree {

private:
  Node *root;

public:
  void insert(const string &);
  bool search(const string &);
  void inOrder();
  void postOrder();
  void preOrder();
  string largest();
  string smallest();
  int height(const string &);
  //constructor
  Tree(): root(){}
  //destructor
  ~Tree(){delete root;};
  void remove(const string &);

  // Add any additional variables/functions here
  // these are probably all the recursive helper functions
private:
  void insert(const string&, Node*);
  bool search(const string &, Node*);
  void preOrder(Node*);
  void inOrder(Node*);
  void postOrder(Node*);
  string largest(Node*);
  string smallest(Node*);
  int height(const string&, Node*);
  void remove(const string& s, Node* t);
  Node* getParent(Node*);
  Node* getParent(Node*,Node*);
};

#endif
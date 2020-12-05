/**
 * Course: CS014 Summer 2020
 *
 * First Name: Ryan
 * Last Name: Chang
 * Username: rchan123
 * email address: rchan123@ucr.edu
 *
 *
 * Assignment: lab4-5
 * Filename : BST.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */


#ifndef BST_H_
#define BST_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class BST {

private:
  struct BinaryNode {

    int value;
    BinaryNode* left;
    BinaryNode* right;
    int depth;
    int height;
    int inorder_num;
    int preorder_num;
    int postorder_num;
    BinaryNode(int& v) : value(v), left(NULL), right(NULL) {}
    static BinaryNode* insert(int v, BinaryNode* t) {
      if(t == NULL){
	      t = new BinaryNode(v);
      }
      else if(v == t->value){
        cerr << "int is already in tree." << endl;
      }
      else if (v < t->value)
	      t->left = insert(v, t->left);
      else if (v > t->value)
	      t->right = insert(v, t->right);
      else
	      t->value = v;
      return t;
    }

    static BinaryNode* remove(int v, BinaryNode* t) {
      if(t) {
        if(v != t->value && t->left == NULL && t->right == NULL){
	        cerr << "int is NOT in the tree" << endl;
	      }
	      else if(v < t->value)
	        t->left = remove(v, t->left);
	      else if(t->value < v)
	        t->right = remove(v, t->right);
	      else if(t->left != NULL && t->right != NULL) {
	        t->value = find_min(t->right)->value;
	        t->right = remove(t->value, t->right);
	      }
	      else {
	       BinaryNode* oldNode = t;
	       t = (t->left != NULL) ? t->left : t->right;
	       delete oldNode;
	      }
      }
      return t;
    }

    static BinaryNode* find_min(BinaryNode* t) {
      if(t == NULL)
	      return NULL;
      if(t->left == NULL)
	      return t;
      return find_min(t->left);
    }


  };

public:
  BST(): root(NULL) {}
  ~BST() {
    delete root;
  }
  void insert(int v) { root = BinaryNode::insert(v, root); }
  void remove(int v) { root = BinaryNode::remove(v, root); }

  void display() { display(root); }
  void display( BinaryNode* t ) {
    // in-order traversal with indented display.
    static int depth = 0;
    ++depth;
    if ( t == NULL ) return;
    if ( t->right != NULL ) display(t->right);
    for( int i = 0; i != depth; ++i )
      cout << " ";
    cout << t->value << " " << endl;
    if ( t->left != NULL )
      display(t->left);
    --depth;
  }

  void inorder(){ inorder(root); }
  void inorder(BinaryNode *t){
    static int inorder_i = 0;
    if(t){
      inorder(t->left);
      ++inorder_i;
      t->inorder_num = inorder_i;
      cout << t->value << ", ";
      inorder(t->right);
    }
    return;
  }

  void preorder(){ preorder(root); }
  void preorder(BinaryNode *t){
    static int preorder_i = 0;
    if(t){
      ++preorder_i;
      t->preorder_num = preorder_i;
      cout << t->value << ", ";
      preorder(t->left);
      preorder(t->right);
    }
    return;
  }

  void postorder(){ postorder(root); }
  void postorder(BinaryNode *t){
    static int postorder_i = 0;
    if(t){
      postorder(t->left);
      postorder(t->right);
      ++postorder_i;
      t->postorder_num = postorder_i;
      cout << t->value << ", ";
    }
    return;
  }
  
  ostream& outMode(ostream& outMode, string mode){
    outMode << "\n//nodes\n";
    if(mode == "preorder"){
      preorder();
      cout << endl;
      outPre(outMode,root);
    }
    else if(mode == "inorder"){
      inorder();
      cout << endl;
      outIn(outMode,root);
    }
    else if(mode == "postorder"){
      postorder();
      cout << endl;
      outPost(outMode,root);
    }
    else if(mode == "height"){
      height();
      cout << endl;
      outH(outMode,root);
    }
    else if(mode == "1"){
      operator<<(outMode);
    }
    outMode << "\n//edges\n";
    setEdge(outMode,root);
    return outMode;
  }
  
  ostream& outPre(ostream& pre, BinaryNode* t){
    if(t){
      pre << t->value << "[label=\"key=" << t->value << ", pre=" << t->preorder_num << "\"];\n";
      outPre(pre,t->left);
      outPre(pre,t->right);
    }
    return pre;
  }
  
  ostream& outIn(ostream& in, BinaryNode* t){
    if(t){
      in << t->value << "[label=\"key=" << t->value << ", in=" << t->inorder_num << "\"];\n";
      outIn(in,t->left);
      outIn(in,t->right);
    }
    return in;
  }
  
  ostream& outPost(ostream& post, BinaryNode* t){
    if(t){
      post << t->value << "[label=\"key=" << t->value << ", post=" << t->postorder_num << "\"];\n";
      outPost(post,t->left);
      outPost(post,t->right);
    }
    return post;
  }
  
  ostream& outH(ostream& h, BinaryNode* t){
    if(t){
      h << t->value << "[label=\"key=" << t->value << ", h=" << t->height << "\"];\n";
      outH(h,t->left);
      outH(h,t->right);
    }
    return h;
  }

  //output.dot should have in, post, pre, and height.

  //master function that uses all 5 of the following?
    //for every node in the tree
      //ostream a node letter, color, peripheries, style, label
        //label depends on the mode, so this function should take in mode
  //returns an ostream so it can be couted to ofs

  //get height(probably recursive)
  int height(){ return height(root); }
  int height(BinaryNode* t){
    if(!t){
      return -1;
    }
    int leftHeight = height(t->left);
    int rightHeight = height(t->right);
    t->height =  1 + max(leftHeight,rightHeight);
    cout << "V H" << endl;
    cout << t->value << " " << t->height << endl;
    return t->height;
  }
  //set edges???
  ostream& operator<<(ostream& out){
    postorder();
    cout << endl;
    preorder();
    cout << endl;
    inorder();
    cout << endl;
    height();
    setNode(out,root);
    return out;
  }

  ostream& setNode(ostream& outNode, BinaryNode* t){
    if(t){
        outNode << t->value << "[label=\"key=" << t->value <<
        ", h=" << t->height <<
        ", pre=" << t->preorder_num <<
        ", in=" << t->inorder_num <<
        ", post=" << t->postorder_num << "\"];\n";
        if(t->left){
          setNode(outNode,t->left);
        }
        if(t->right){
          setNode(outNode,t->right);
        }
    }
    return outNode;
  }

  ostream& setEdge(ostream& outEdge, BinaryNode* t){
    if(t){
      if(t->left){
        outEdge << t->value << " -> " << t->left->value << ";" << endl;
        setEdge(outEdge,t->left);
      }
      if(t->right){
        outEdge << t->value << " -> " << t->right->value << ";" << endl;
        setEdge(outEdge,t->right);
      }
    }
    return outEdge;
  }

  private:
    BinaryNode* root;
};

#endif /* BST_H_ */
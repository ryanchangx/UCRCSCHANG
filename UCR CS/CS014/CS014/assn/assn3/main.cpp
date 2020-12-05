//password for zyBooks: stoic.
/*  digraph G {
      hoppy->gadget
      hoppy->reel
      reel->madness
      reel->trap
      gadget->aeon
      gadget->X1
      aeon->House
      aeon->alphabet
      House->"A+"
      House->X2
      alphabet->X3
      alphabet->basket
      basket->X4
      basket->hit
      madness->hut
      madness->X5
      hut->X6
      hut->jungle
      jungle->ink
      jungle->X7
      ink->X8
      ink->jab
    }
*/

#include <iostream>
#include "Tree.h"

using namespace std;

void
printOrders ( Tree* tree ) {
  cout << "Preorder = ";
  tree->preOrder ( );
  cout << "Inorder = ";
  tree->inOrder ( );
  cout << "Postorder = ";
  tree->postOrder ( );
}

int 
main ( ) {

  Tree tree;

  cout << "Test 1: Testing simple insert" << endl;
  tree.insert ( "hoppy" );
  tree.insert ( "gadget" );
  printOrders ( &tree );
  cout << "----------------------------------------------------------------" 
       << endl;

  cout << "Test 2: Testing duplicates" << endl;
  tree.insert ( "hoppy" );
  tree.insert ( "gadget" );
  printOrders ( &tree );
  cout << "----------------------------------------------------------------" 
       << endl;

  cout << "Test 3: Insert testing 1" << endl;
  tree.insert ( "reel" );
  tree.insert ( "trap" );
  tree.insert ( "madness" );
  tree.insert ( "aeon" );
  tree.insert ( "hoppy" );
  tree.insert ( "gadget" );
  tree.insert ( "hoppy" );
  tree.insert ( "gadget" );
  printOrders ( &tree );
  cout << "----------------------------------------------------------------" 
       << endl;

  cout << "Test 4: Insert testing 2" << endl;
  tree.insert ( "reel" );
  tree.insert ( "trap" );
  tree.insert ( "madness" );
  tree.insert ( "aeon" );
  tree.insert ( "alphabet" );
  tree.insert ( "alphabet" );
  tree.insert ( "basket" );
  tree.insert ( "basket" );
  tree.insert ( "hut" );
  printOrders ( &tree );
  cout << "----------------------------------------------------------------" 
       << endl;

  cout << "Test 5: Insert testing 3" << endl;  
  tree.insert ( "hit" );
  tree.insert ( "House" );
  tree.insert ( "A+" );
  tree.insert ( "jungle" );
  tree.insert ( "ink" );
  tree.insert ( "jab" );
  printOrders ( &tree );
  cout << "----------------------------------------------------------------" 
       << endl;




  cout << "Test 11: Remove testing 1" << endl;
  // cout << "Removing \"hit\"" << endl;
  tree.remove ( "hit" );
  // cout << "Removing \"hoppy\"" << endl;
  tree.remove ( "hoppy" );
  // cout << "Removing \"hut\"" << endl;
  tree.remove ( "hut" );
  // cout << "Removing all \"madness\"" << endl;
  tree.remove ( "madness" );
  tree.remove ( "madness" );
  printOrders ( &tree );
  cout << "----------------------------------------------------------------" 
       << endl;

  cout << "Test 12: Remove testing 2" << endl;
  // cout << "Removing all \"hoppy\"" << endl;
  tree.remove ( "hoppy" );
  tree.remove ( "hoppy" );
  tree.remove ( "hoppy" );
  tree.remove ( "hoppy" );
  // cout << "Removing \"ink\"" << endl;
  tree.remove ( "ink" );
  // cout << "Removing all \"basket\"" << endl;
  tree.remove ( "basket" );
  tree.remove ( "basket" );
  // cout << "Removing all \"gadget\"" << endl;
  tree.remove ( "gadget" );
  tree.remove ( "gadget" );
  tree.remove ( "gadget" );
  tree.remove ( "gadget" );
  // cout << "Removing \"nothing\"" << endl;
  tree.remove ( "nothing" );
  printOrders ( &tree );
  cout << "----------------------------------------------------------------" 
      << endl;

  return 1;
}
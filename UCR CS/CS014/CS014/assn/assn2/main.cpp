#include <cstdlib>
#include <iostream>
#include <string>
#include "WordLadder.h"
#include <vector>


using namespace std;

int main(int argc, char* argv[]){
  if (argc != 4) {
    cerr << "Usage error, expected: ./a.out words*.txt start_word end_word\n";
    exit(1);
  }
  
  string dict_file = argv[1];
  string s2 = argv[2];
  string s3 = argv[3];
  
  
  WordLadder w(dict_file);
  w.outputLadder(s2, s3);
  
    
   // 4-letter words
  if (dict_file == "words4.txt") {
    //cout << "4-letter test" << endl;
    // fast-slow
    /*
    string w01_4char_start = "fast";
    string w01_4char_end = "slow";
    WordLadder w01_4char(dict_file);
    w01_4char.outputLadder(w01_4char_start, w01_4char_end);
    */
    
  } 
  else if (dict_file == "words5.txt") {   // 5-letter words

    //cout << "5-letter test" << endl;  
    // brave-heart
    /*
    string w12_5char_start = "brave";
    string w12_5char_end = "heart";
    WordLadder w12_5char(dict_file);
    w12_5char.outputLadder(w12_5char_start, w12_5char_end);
    */
    
    // stack-steak
    /*
    string w13_5char_start = "start";
    string w13_5char_end = "steak";
    WordLadder w13_5char(dict_file);
    w13_5char.outputLadder(w13_5char_start, w13_5char_end);
    */
    
    // stone-money
    /*
    string w14_5char_start = "stone";
    string w14_5char_end = "money";
    WordLadder w14_5char(dict_file);
    w14_5char.outputLadder(w14_5char_start, w14_5char_end);
    */
    
    // crazy-style
    /*
    string w15_5char_start = "crazy";
    string w15_5char_end = "style";
    WordLadder w15_5char(dict_file);
    w15_5char.outputLadder(w15_5char_start, w15_5char_end);
    */
  }
  else if (dict_file == "words6.txt") {  // 6-letter words
  
    //cout << "6-letter test" << endl;
    // sleepy-babies
    /*
    string w21_6char_start = "sleepy";
    string w21_6char_end = "babies";
    WordLadder w21_6char(dict_file);
    w21_6char.outputLadder(w21_6char_start, w21_6char_end);
    */
  }
  else if (dict_file == "words7.txt") {  // 7-letter words
  
    //cout << "7-letter tests" << endl;
    // brewing-whiskey
    /*
    string w31_7char_start = "brewing";
    string w31_7char_end = "whiskey";
    WordLadder w31_7char(dict_file);
    w31_7char.outputLadder(w31_7char_start, w31_7char_end);
    */
  } 
  else {
    cout << "A valid dictionary file was not provided." << endl;
    cout << "Valid files: *.txt, e.g., words4.txt, words5.txt, etc." << endl;
    exit(1);
  }
  
  string name = "Neo";
  Stack<string> s1; // empty Stack of strings

  try {   // try block
    // ternary operator, displays warning if Stack instance is empty
    s1.is_empty() ? cout << "\nNon-Exception check: Empty stack\n" : cout  
      << "Non-Exception check: Non-empty Stack<string>\n";

    s1.push(name);
    s1.push(name);
    s1.push(name);
    s1.push(name);
    s1.push(name);
   // s1.push(name);  // test 1: Raises Stack overflow_error exception, uncomment this line in try block to test

  } catch(overflow_error& e) { // catch block
    cerr << "Overflow Exception: "<< e.what() << endl;
  } catch(...) {
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }

  try {
	  cout << s1.top() << endl;
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
  } catch(underflow_error& e) { // catch block
    cerr << "Underflow Exception: "<< e.what() << endl;
  } catch(...) { // catch-all block
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }
  
  try {
    //s1.top(); // test 2: Raises underflow exception, uncomment this line only in try block to test
    s1.push("Trinity"); 
    s1.pop();
    //s1.pop(); // test 3: Raises underflow exception, uncomment this line only in try block to test
  } catch(underflow_error& e) { // catch block
    cerr << "Underflow Exception: "<< e.what() << endl;
  } catch(...) { // catch-all block
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }
  
  Stack<int> s2; // empty Stack of ints
  try {
    // ternary operator, displays warning if Stack instance is empty
    s2.is_empty() ? cout << "\nNon-Exception check: Empty stack\n" : cout  
      << "Non-Exception check: Non-empty Stack<int>\n";
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    s2.push(5);
    //s2.push(6);  // test 4: Raises Stack overflow_error exception, uncomment this line in try block to test

  } catch(overflow_error& e) {
    cerr << "Overflow Exception: "<< e.what() << endl;
  } catch(...) {
    cerr << "Whoops! Catch-all block, Stack<int>, terminating program.\n";
  }
  
  try {
	  cout << s2.top() << endl;
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();
  } catch(underflow_error& e) { // catch block
    cerr << "Underflow Exception: "<< e.what() << endl;
  } catch(...) { // catch-all block
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }

  try {
    //s2.top(); // test 5: Raises underflow exception, uncomment this line only in try block to test
    s2.push(77); 
    s2.pop();
    //s.pop(); // test 6: Raises underflow exception, uncomment this line only in try block to test
  } catch(underflow_error& e) { // catch block
    cerr << "Underflow Exception: "<< e.what() << endl;
  } catch(...) { // catch-all block
    cerr << "Whoops! Catch-all block, Stack<int>, terminating program.\n";
  }
  
  /* This code demonstrates that the std::vector m,ember function at()
   * automatically checks whether n is within the bounds of valid elements
   * in the vector, throwing an out_of_range exception if the argument n in
   * v.at(n) is not in range 0 to v.size()-1.
   */
  try {
    // Raises out_of_range exception, uncomment next two lines in try block to test
    // vector<int> myvector(10);
    // cout << myvector.at(20); // vector::at throws an out-of-range
  } catch(out_of_range& e) { // catch block
    cerr << "Out of range error: "<< e.what() << endl;
  } catch(...) { // catch-all block
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }

  cout << "\nThe program flow continues...\n";
  cout << "The \"return 0;\" statement will cause the program to exit.\n";
  return 0;
}
/**
 * UCR CS&E
 * CS014 Lab 1
 * main.cpp
 */
/**
 * Course: CS014 Summer 2020
 *
 * First Name: Ryan
 * Last Name: Chang
 * Username: rchan123
 * email address: rchan123@ucr.edu
 *
 *
 * Assignment: Lab 1
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#include <iostream>
#include "List.h"
#include "Iterator.h"
#include "Node.h"

#define fibo_number 11

int fibonacci(int n);

using namespace std;

int main()
{
	/* Instantiate two Lists */
	List myList;
	List myList2;
	List emptyList;
	
	/* Try to print an empty List */
	cout << "\nTest printing an empty list:";
	myList.print();
	
	cout << "\nPushing back first " << fibo_number << " Fibonacci numbers:";
	for(int i = 0; i < fibo_number; i++)
	{
		myList.push_back(fibonacci(i));
		myList.print();
	}
	
	cout << "\nReverse myList pushing front contents of myList into myList2:";
	for(Iterator iter = myList.begin(); !iter.is_equal(myList.end()); iter.next_pos())
	{
		myList2.push_front(iter.get_value());
		myList2.print();
	}
	
	cout << "\n***SORTED_INSERT TESTS***\n";
	
	cout << "\nTest sorted insert with -7:";
	myList.sorted_insert(-7);
	myList.print();
	
	cout << "\nTest sorted insert with 7:";
	myList.sorted_insert(7);
	myList.print();
	
	cout << "\nTest sorted insert with 77:";
	myList.sorted_insert(77);
	myList.print();
	/*
	cout << "\n***INSERT_AFTER TESTS***\n";	
	
	cout << "\nTest insert_after(2,26):";
	myList.insert_after(2,26);
	myList.print();
	
	cout << "\nTest insert_after(-4,26):";
	myList.insert_after(-4,26);
	myList.print();
	
	cout << "\nTest insert_after(20,26):";
	myList.insert_after(20,26);
	myList.print();
	*/
	cout << "\n***INSERT_BEFORE TESTS***\n";	
	
	cout << "\nTest insert_before(14,61):";
	myList.insert_before(14,61);
	myList.print();
	
	cout << "\nTest insert_before(0,615):";
	myList.insert_before(0,615);
	myList.print();
	
	cout << "\nTest insert_before(-1,461):";
	myList.insert_before(-1,461);
	myList.print();
	
	cout << "\nTest insert_before(1000,631):";
	myList.insert_before(1000,631);
	myList.print();
	cout << "\n***PRINT_REVERSE TESTS***\n";
	
	cout << "\nTest print forward:";
	myList.print();
	cout << "\nTest print reverse:";
	myList.print_reverse();

	cout << "\nTest print reverse on emptyList:";
	emptyList.print_reverse();	
	
	cout << "\n***COUNT TESTS***\n";
	
	cout << "\nTest count(61), expecting 3, result: " << myList.count(61) << endl;
	cout << "Test count(178), expecting 0, result: " << myList.count(178) << endl;
	cout << "Test count(0), expecting 1, result: " << myList.count(0) << endl;
	
	return 0;
}

/**
 * Local Fibonacci function for filling and testing Lists 
 * @param n the Fibonacci number to calculate
 * @return fibonacci(n)
 */
int fibonacci(int n)
{
	if((n == 0) | (n == 1))
	{
		return n;
	}
	else
	{
		return fibonacci(n-2) + fibonacci(n-1);
	}
}

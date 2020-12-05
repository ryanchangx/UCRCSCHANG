/**
 * UCR CS&E
 * CS014 Lab 1
 * List.cpp
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
 * Filename : List.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#include <iostream>
#include <cstdlib>
#include "List.h"
#include "Node.h"
#include "Iterator.h"

using namespace std;

/**
 * Constructor
 */
List::List()
{
	head = NULL;
	tail = NULL;
}

/**
 * Destructor
 */
List::~List()
{
	cout << "\nList Destructor called...\n";
	
	while(head)
	{
		Node* temp = head;
		head = head->get_next();
		cout << "Deleting.... " << temp->get_value() << endl;
		delete temp;
	}	
}

/**
 * push_back() inserts a new node at the tail
 * end of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_back(int value)
{
	Node* new_node = new Node(value);
	
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_prev(tail);
		tail->set_next(new_node);
		tail = new_node;
	}
}
/**
 * push_front() inserts a new node at the 
 * front of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_front(int value)
{
	Node* new_node = new Node(value);
		
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_next(head);
		head->set_prev(new_node);
		head = new_node;			
	}
}

/**
 * print()const prints the contents of 
 * the list to the console, starting
 * at the head of the list
 * @param none
 * @return none
 */
void List::print()const
{
	cout << "\nList contents:\n";

	/* list is empty */
	if(!head)
	{
		cout << "empty\n";
		return;
	}
	
	for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos())
	{
		cout << iter.get_value() << ", ";
	}
	cout << "\n";
}

/**
 * get_head()const returns the head
 * Node pointer which points to the
 * first element in the list
 * @param none
 * @return List's head Node pointer
 */
Node* List::get_head()const
{
	return head;
}

/**
 * get_tail()const  returns the tail
 * Node pointer which points to the
 * last element in the list
 * @param none
 * @return List's tail Node pointer
 */
Node* List::get_tail()const
{
	return tail;
}

/**
 * begin()const gets beginning postion of the list
 * @param none
 * @return an Iterator pointing to the beginning of the list
 */
Iterator List::begin()const
{
	Iterator iter;
	iter.set_curr_pos(get_head());
	iter.set_last_pos(get_tail());
	return iter;
}

/**
 * end()const gets past-the-end postion of the list
 * @param none
 * @return an Iterator pointing just past the end of the list
 */
Iterator List::end()const
{
	Iterator iter;
	iter.set_curr_pos(NULL);
	iter.set_last_pos(get_tail());
	return iter;
}

/**functions inserts new node with value into list. 
 * This insert_sort should preserve the increasing ordering of the list. 
 * For example, if value == 5, then the new node would have a value of 5 and be inserted 
 * after the last instance (furthest from head node) of a existing node with value 5. 
 * To test create a list object with sorted values. 
 * NOTE: When inserting at the front or back of list, 
 * you can call pushfront and pushback in the body of the sortedinsert function. 
 * DO NOT, however, call pushback or push_front directly in main function. 
 */
void List::sorted_insert(int value){
	//create new node
	//check if before first node
	if(value < head->get_value()){
		push_front(value);
		return;
	}
	//if value is in between node and prevNode
	for(Node* i = head->get_next(); i != NULL; i = i->get_next()){
		if((value <= i->get_value()) && (value >= i->get_prev()->get_value())){
			Node* newNode = new Node(value);
			newNode->set_next(i);
			newNode->set_prev(i->get_prev());
			i->get_prev()->set_next(newNode);
			i->set_prev(newNode);
			return;
		}
	}
	//else it is inserted at the end
	push_back(value);
}

/**
 * function prints the contents of a list backwards. 
 * NOTE: Implement a void Iterator::prev_pos() 
 * function to make for use in this function.
 */
void List::print_reverse()const{
	cout << "\nList contents:\n";
	/* list is empty */
	if(!head){
		cout << "empty\n";
		return;
	}

	
	Iterator iter = begin();
	for(Node* k = head->get_next(); k != NULL; k = k->get_next()){
		iter.next_pos();
	}
	//print out last value
	cout << iter.get_value() << ", ";
	
	//print out the rest of them
	while(!iter.is_equal(begin())){
		iter.prev_pos();
		cout << iter.get_value() << ", ";
	}
	cout << "\n";
}

/**
 * function inserts a new node with value at position i + 1 in the list. 
 * If position passed in is outside of the list’s current boundaries (i < 0 or i > size - 1), 
 * have a policy to handle this.
 */
void List::insert_after(int i, int value){
	int size = 0;
	for(Node* k = head; k != NULL; k = k->get_next()){
		++size;
	}
	if(i < 0){
		push_front(value);
		return;
	}
	else if(i > size-1){
		push_back(value);
		return;
	}
	else{
		Iterator iter = begin();
		for(int j = 0; j < i; ++j){
			iter.next_pos();
		}
		Node* newNode = new Node(value);
		newNode->set_next(iter.get_curr_pos()->get_next());
		newNode->set_prev(iter.get_curr_pos());
		iter.get_curr_pos()->get_next()->set_prev(newNode);
		iter.get_curr_pos()->set_next(newNode);
		return;
	}
}

void List::insert_before(int i, int value){
	int size = 0;
	for(Node* k = head; k != NULL; k = k->get_next()){
		++size;
	}
	if(i <= 0){
		push_front(value);
		return;
	}
	else if(i > size-1){
		push_back(value);
		return;
	}
	else{
		Iterator iter = begin();
		for(int j = 1; j < i; ++j){
			iter.next_pos();
		}
		Node* newNode = new Node(value);
		newNode->set_next(iter.get_curr_pos()->get_next());
		newNode->set_prev(iter.get_curr_pos());
		iter.get_curr_pos()->get_next()->set_prev(newNode);
		iter.get_curr_pos()->set_next(newNode);
		return;
	}
}

int List::count(int value)const{
	int j = 0;
	for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos()){
		if(iter.get_value() == value){
			++j;
		}
	}
	return j;
}
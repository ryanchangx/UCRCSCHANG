/**
 * UCR CS&E
 * CS014 Lab 1
 * Iterator.h
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
 * Filename : Iterator.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#ifndef ITERATOR_H_
#define ITERATOR_H_

#include "Node.h"

class Iterator
{
public:
	Iterator();
	~Iterator();
	int get_value()const;
	Node* get_curr_pos()const;
	Node* get_last_pos()const;
	void set_curr_pos(Node*);
	void set_last_pos(Node*);
	bool is_equal(Iterator rhs)const;
	void next_pos();
	
	/* You must implement this ! */
	void prev_pos();
	
private:
	Node* curr_pos;
	Node* last_pos;
};

#endif /*ITERATOR_H_*/

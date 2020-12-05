/**
 * UCR CS&E
 * CS014 Lab 1
 * Node.h
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
 * Filename : Node.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#ifndef NODE_H_
#define NODE_H_

class Node
{
public:
	Node();
	Node(int value);
	~Node();
	Node* get_next()const;
	Node* get_prev()const;
	int get_value()const;
	void set_next(Node*);
	void set_prev(Node*);
	void set_value(int value);
	
private:
	Node* next;
	Node* prev;
	int value;
};

#endif /*NODE_H_*/

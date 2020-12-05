/**
 * UCR CS&E
 * CS014 Lab 1
 * Node.cpp
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
 * Filename : Node.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#include "Node.h"
#include <cstdlib>

using namespace std;

/* Default Constructor */
Node::Node()
{
	next = NULL;
	prev = NULL;
	value = 0;
}

/* Overloaded Constructor
 * @param value integer node value
 */
Node::Node(int value)
{
	next = NULL;
	prev = NULL;
	this->value = value;
}

/* Destructor */
Node::~Node()
{}

/*
 * Mutators
 */
void Node::set_next(Node* temp)
{
	next = temp;
}

void Node::set_prev(Node* temp)
{
	prev = temp;
}

/* 
 * Accessors
 */
Node* Node::get_next()const
{
	return next;
}

Node* Node::get_prev()const
{
	return prev;
}

int Node::get_value()const
{
	return value;
}


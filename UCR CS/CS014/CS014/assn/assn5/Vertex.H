/**
 * Course: CS014 Summer 2020
 *
 * First Name: Ryan
 * Last Name: Chang
 * Username: rchan123
 * email address: rchan123@ucr.edu
 *
 *
 * Assignment: assn5
 * Filename : Vertex.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 


#ifndef VERTEX_H_
#define VERTEX_H_

#include <string>
#include <list>

using namespace std;

class Vertex {
public:
    Vertex(){
        label = "\0";
        distance = 1000;
    }
    ~Vertex(){}
    string label;
    int distance;
    list<int> neighbors;
};

#endif /* VERTEX_H_ */
/**
 * Course: CS014 Summer 2020
 *
 * First Name: Ryan
 * Last Name: Chang
 * Username: rchan123
 * email address: rchan123@ucr.edu
 *
 *
 * Assignment: lab3
 * Filename : Stack.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#ifndef _STACK_H_
#define _STACK_H_


#include <stdexcept>
#include <cstdlib>
using namespace std;

int MAX_SIZE = 100;

template<typename T>
class Stack{
    public:
        void push(const T& x){
            if(topIndex + 1 >= MAX_SIZE){
                throw overflow_error("throw overflow_error exception returned");
            }
            stk[++topIndex] = x;
        }
        T& top(){
            if(isEmpty()){
                throw underflow_error("throw underflow_error exception returned");
            }
            return stk[topIndex];
        }
        void pop(){
            if(isEmpty()){
                throw underflow_error("throw underflow_error exception returned");
            }
            --topIndex;
        }
        int size(){
            return topIndex + 1;
        }
        bool isEmpty() const{
            return (topIndex < 0);
        }
        
    private:
        T* stk = new T[MAX_SIZE];
        int topIndex = -1;
};

#endif
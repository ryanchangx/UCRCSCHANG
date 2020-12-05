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
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include "Stack.H"

using namespace std;

vector<string> split(string str, char del){
    stringstream ss(str);
    string item;
    vector<string> splstr;
    while (getline(ss, item, del))
    {
       splstr.push_back(item);
    }
    return splstr;
}

string infix_to_postfix(string infix){
    vector<string> IV = split(infix,' ');
    
    string final;
    Stack<string> operators;
    
    for(unsigned int i = 0; i < IV.size(); ++i){
        if(IV.at(i) != "+" && IV.at(i) != "-" && IV.at(i) != "*"  && IV.at(i) != "/" && IV.at(i) != "(" && IV.at(i) != ")"){
            final.append(IV.at(i));
            final.append(" ");
        }
        else if(IV.at(i) == ")"){
            while(!operators.isEmpty() && operators.top() != "("){
                final.append(operators.top());
                final.append(" ");
                operators.pop();
            }
            if(operators.top() == "("){
                operators.pop();
            }
        }
        else if(IV.at(i) == "("){
            operators.push(IV.at(i));
        }
        else if(IV.at(i) == "*" || IV.at(i) == "/"){
            operators.push(IV.at(i));
        }
        else if(IV.at(i) == "+" || IV.at(i) == "-"){
            while(!operators.isEmpty() && operators.top() != "("){
                final.append(operators.top());
                final.append(" ");
                operators.pop();
            }
            operators.push(IV.at(i));
        }
    }
    
    while(!operators.isEmpty()){
        if(operators.top() != "(" && operators.top() != ")"){
            final.append(operators.top());
            final.push_back(' ');
        }
        operators.pop();
    }
    final.pop_back();
    return final;
}

double evaluate_rpn(string infix){
    vector<string> postfix = split(infix_to_postfix(infix),' ');
    Stack<double> S;
    for(unsigned int i = 0; i < postfix.size(); ++i){
        bool isNumber = true;
        unsigned int j = 0;
        if(postfix.at(i).at(0) == '-'){
            j = 1;
        }
        if(j == postfix.at(i).size()){
            isNumber = false;
        }
        while(j < postfix.at(i).size()){
            if(!isdigit(postfix.at(i).at(j))){
                isNumber = false;
            }
            ++j;
        }
        if(isNumber){
            S.push(stod(postfix.at(i)));
        }
        else{
            if(S.isEmpty()){
                throw invalid_argument(infix);
            }
            else{
                double b = S.top();
                S.pop();
                if(S.isEmpty()){
                    throw invalid_argument(infix);
                }
                else{
                    double a = S.top();
                    S.pop();
                    double c;
                    if(postfix.at(i) == "+"){
                        c = a + b;
                        S.push(c);
                    }
                    else if(postfix.at(i) == "-"){
                        c = a - b;
                        S.push(c);
                    }
                    else if(postfix.at(i) == "*"){
                        c = a * b;
                        S.push(c);
                    }
                    else if(postfix.at(i) == "/"){
                        c = a / b;
                        S.push(c);
                    }
                }
            }
        }
    }
    double v = S.top();
    S.pop();
    if(!S.isEmpty()){
        throw invalid_argument(infix);
    }
    else{
        return v;
    }
}

int main(){
    /*
    try{
        cout << "Push tests: " << endl;
        Stack<int> S1;
        for(int i = 0; i < 100; ++i){
            S1.push(i+1);
        }
        cout << "Top: " << S1.top() << endl;
        
        cout << "Trying to push 101... " << endl;
        S1.push(101);
        cout << S1.top() << endl;
        
    }catch(overflow_error& is){
        cerr << is.what() << endl;
    }catch(...){
        cerr << "Catch-all block" << endl;
    }
    
    try{
        cout << "Pushing ints 1-100: " << endl;
        Stack<int> S1;
        for(int i = 0; i < 100; ++i){
            S1.push(i+1);
        }
        cout << "Top: " << S1.top() << endl;
        
        cout << "Popping until empty..." << endl;
        while(!S1.isEmpty()){
            S1.pop();
        }
        
        cout << "Popping while already empty..." << endl;
        S1.pop();
        cout << S1.top() << endl;
    }catch(underflow_error& is){
        cerr << is.what() << endl;
    }catch(...){
        cerr << "Catch-all block" << endl;
    }
    */
    int correct = 0;
    int total = 0;
    
    ifstream fin("input.txt");
    assert(fin.is_open());
    
    string line;
    
    while (getline(fin, line)) 
    {
        total++;
        
        vector<string> splstr = split(line, '=');
        string expr = splstr[0];
        double val = stod(splstr[1].c_str());
        
        try 
        {
            if (evaluate_rpn(expr) == val) 
            {
                correct++;       
            }
        }
        catch (exception& e)
        {
            cout << "Error in: " << e.what() << endl;
        }
    }
    
    fin.close();
    
    cout << "Grade: " << correct * 100.0 / total << endl;
    return 0;
}
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
 * Filename : Graph.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 


#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include "Vertex.H"

using namespace std;

class Graph {
public:
    Graph(){}
    Graph(ifstream& ifs){
        //the question is do we use the new keyword? no we shouldn't cuz we storing it in a vector
        //declare
        int numVert;
        int numEdges;
        string tempstr;
        //set values
        ifs >> numVert;
        ifs >> numEdges;
        ifs >> tempstr;
        //set vertices
            //first node is source node, so set distance to 0, but dont set the rest of them;
        Vertex temp;
        temp.label = tempstr;
        //source node is distance 0 away from itself
        temp.distance = 0;
        //source node is at the very front of the vector. 
        vertices.push_back(temp);
        vIndex.insert(pair<string,int>(vertices.at(vertices.size()-1).label,vertices.size()-1));
        for(int i = 1; i < numVert; ++i){
            ifs >> tempstr;
            temp.label = tempstr;
            //big enough number, represents infinity for our purposes
            temp.distance = 1000;
            vertices.push_back(temp);
            vIndex.insert(pair<string,int>(vertices.at(vertices.size()-1).label,vertices.size()-1));
        }
        string first;
        string second;
        for(int j = 0; j < numEdges; ++j){
            // takes in 2 strings
            // can use two loops to find each word in the vector, using l1's adjacency list.
            //     or a map
            //     finds all the indices of the neighbors in a list. 
            ifs >> first;
            ifs >> second;
            vertices.at(vIndex.at(first)).neighbors.push_front(vIndex.at(second));
        }
    }
    ~Graph(){}
    void output_graph(){
        ofstream oFS("graph.dot");
        if(!oFS){
            cerr << "Error openning file: graph.dot: " << endl;
            exit(1);
        }
        //include bfs in here somewhere
        oFS << "digraph G{\n";
            oFS << "\t//vertices\n";
            for(unsigned int i = 0; i < vertices.size(); ++i){
                oFS << "\t" << vertices.at(i).label << "[label=\"" << vertices.at(i).label << "(" << vertices.at(i).distance << ")\"]" << ";\n";
            }
            oFS << "\n";
            oFS << "\t//edges\n";
            for(unsigned int i = 0; i < vertices.size(); ++i){
                for(list<int>::iterator iter = vertices.at(i).neighbors.begin(); iter != vertices.at(i).neighbors.end(); ++iter){
                    oFS << "\t"<< vertices.at(i).label << "->" << vertices.at(*iter).label << ";\n";
                }
            }
            oFS << "}";
        oFS.close();
    }
    void bfs(){
        queue<Vertex> Q;
        Q.push(vertices.at(0));
        while(!Q.empty()){
            Vertex temp = Q.front();
            Q.pop();
            for(list<int>::iterator iter = temp.neighbors.begin(); iter != temp.neighbors.end(); ++iter){
                if(vertices.at(*iter).distance == 1000){
                    vertices.at(*iter).distance = temp.distance + 1;
                    Q.push(vertices.at(*iter));
                }
            }
        }
    }
private:
    vector<Vertex> vertices;
    map<string,int> vIndex;
};

#endif /* GRAPH_H_ */
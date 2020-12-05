/**
 * Course: CS014 Summer 2020
 *
 * First Name: Ryan
 * Last Name: Chang
 * Username: rchan123
 * email address: rchan123@ucr.edu
 *
 *
 * Assignment: assn1
 * Filename : MyList.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include "MyList.h"
#include <cstdlib>
#include <cassert>

using namespace std;

MyList::MyList(){ 
    head = nullptr;
}

MyList::MyList(const MyList& cpy){
    head = nullptr;
    for(Node* temp = cpy.head; temp != nullptr; temp = temp->next){
        push_back(temp->value);
    }
}

MyList::MyList(const string& str){
    for(unsigned int i = 0; i < str.size(); ++i){
        push_back(str[i]);
    }
}

MyList::MyList(const char* str){
    head = nullptr;
    string temp = str;
    for(unsigned int i = 0; i < temp.size(); ++i){
        push_back(temp[i]);
    }
}

MyList::~MyList(){
    //see if you really need this at all
    //what do i really need in here
    delete head;
}

void MyList::push_front(char value){
    Node* newNode = new Node;
    newNode->value = value;
    if(head == nullptr){
        newNode->next = nullptr;
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

void MyList::push_back(char value){
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    if(head == nullptr){
        head = newNode;
    }
    else{
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void MyList::pop_front(){
    if(head != nullptr){
        head = head->next;
    }
}

void MyList::pop_back(){
    if(head->next == nullptr){
        head = head->next;
        return;
    }
    Node* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        } 
    temp->next = nullptr;
}

void MyList::swap(int i, int j){
    Node* tempA = head;
    Node* tempB = head;
    //find position of first node
    for(int l = 0; l < i; ++j){
        tempA = tempA->next;
        if(tempA == nullptr){
            return;
        }
    }
    //find position of second node
    for(int k = 0; k < j; ++k){
        tempB = tempB->next;
        if(tempB == nullptr){
            return;
        }
    }
    //swap the values, but not the actual nodes
    char temp = tempA->value;
    tempA->value = tempB->value;
    tempB->value = temp;
}

void MyList::insert_at_pos(int i, char value){
    assert(i >= 0 && i <= size());
    if(i == 0){
        push_front(value);
        return;
    }
    Node* temp = head;
    //see if making j = 0 or j = -1 makes a difference.
    //get temp to the right position
    for(int j = 1; j < i; ++j){
        temp = temp->next;
    }
    //make the node
    Node* newNode = new Node;
    newNode->value = value;
    //insert the node
    newNode->next = temp->next;
    temp->next = newNode;
}

void MyList::reverse(){
    if(head != nullptr){
        int listSize = size();
        Node* tempNode = head;
        char temp[listSize];
        char tempReverse[listSize];
        for(int i = 0; i < listSize; ++i){
            temp[i] = tempNode->value;
            tempNode = tempNode->next;
        }
        int j = listSize - 1;
        int k = 0;
        while(j >= 0){
            tempReverse[k] = temp[j];
            ++k;
            --j;
        }
        tempNode = head;
        for(int l = 0; l < listSize; ++l){
            tempNode->value = tempReverse[l];
            tempNode = tempNode->next;
        }
    }
}

int MyList::size() const{
    int counter = 0;
    for(Node* temp = head; temp != nullptr; temp = temp->next){
        ++counter;
    }
    return counter;
}

void MyList::print() const{
    for(Node* temp = head; temp != nullptr; temp = temp->next){
        cout << temp->value;
        if(temp->next != nullptr){
            cout << ", ";
        }
    }
    cout << endl;
}

int MyList::find(char value) const{
    int index = 0;
    for(Node* i = head; i != nullptr; i = i->next){
        if(i->value == value){
            return index;
        }
        ++index;
    }
    return -1;
}

int MyList::find(MyList& query_str) const{
    //need a loop through l1, probably a while loop
    //need to check if the first letter matches
    int index = 0;
    for(Node* list1 = head; list1 != nullptr; list1 = list1->next){
        //if the two values are the same, go through query_str until query_str is nullptr
        Node* temp1 = list1;
        Node* temp2 = query_str.head;
        while(temp1->value == temp2->value){
            temp1 = temp1->next;
            temp2 = temp2->next;
            if(temp2 == nullptr){
                return index;
            }
        }
        ++index;
    }
    return -1;
}

MyList& MyList::operator=(const MyList& str){
    head = nullptr;
    for(Node* temp = str.head; temp != nullptr; temp = temp->next){
        push_back(temp->value);
    }
    return *this;
}

char& MyList::operator[](const int i){
    assert(i >= 0 && i < size());
    Node* temp = head;
        for(int j = 0; j < i; j++){
            temp = temp->next;
        }
    return temp->value;
}

MyList MyList::operator+(const MyList& str){
    if(str.head == nullptr){
        return *this;
    }
    else if(head == nullptr){
        *this = str;
        return *this;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = str.head;
    return *this;
}

bool MyList::is_palindrome()const{
    //use reverse, and if the forward and reverse are the same, return true, else return false
    MyList reverseString = *this;
    reverseString.reverse();
    
    Node* i = head;
    Node* j = reverseString.head;
    while(i != nullptr && j != nullptr){
        if(i->value != j->value){
            return false;
        }
        i = i->next;
        j = j->next;
    }
    return true;
}

void MyList::merge_list(MyList A, MyList B){
    head = nullptr;
    Node* aNode = A.head;
    Node* bNode = B.head;
    while(aNode != nullptr && bNode != nullptr){
        if(aNode->value < bNode->value){
            push_back(aNode->value);
            aNode = aNode->next;
        }
        else{
            push_back(bNode->value);
            bNode = bNode->next;
        }
    }
    if(aNode == nullptr){
        while(bNode != nullptr){
            push_back(bNode->value);
            bNode = bNode->next;
        }
    }
    else if(bNode == nullptr){
        while(aNode != nullptr){
            push_back(aNode->value);
            aNode = aNode->next;
        }
    }
}

bool MyList::remove_char(char c){
    //while head value is that c, remove it, else move on ONLY MOVE ON IF THAT VALUE IS NOT C
    bool removed = false;
    if(head != nullptr){
        while(head->value == c){
            head = head->next;
            removed = true;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            if(temp->next->value == c){
                temp->next = temp->next->next;
                removed = true;
            }
            else{
                temp = temp->next;
            }
        }
    }
    return removed;
}

char MyList::front()const{
    return head->value;
}
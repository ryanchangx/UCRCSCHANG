#include <cstdlib> 
#include <string>
#include "Node.h"
#include "Tree.h"
using namespace std;

//insert
void Tree::insert(const string &s){
    insert(s,root);
}
void Tree::insert(const string& s, Node* t){
    //check for root is null, could possibly check 
        // for left and right if they are empty?
    if(!root){
        Node* temp = new Node(s);
        root = temp;
        return;
    }
    //if s is t->str, then increase count
    else if(s == t->str){
        ++(t->count);
        return;
    }
    //else if s is less that t->str, call insert with t->left
    else if(s < t->str){
        //is this necessary if we have the first if statement?
        if(!t->left){
            Node* temp = new Node(s);
            t->left = temp;
            return;
        }
        insert(s,t->left);
    }
    //else if s is greater than t->str, call insert with t->right
    else if(s > t->str){
        //is this necessary if we have the first if statement?
        if(!t->right){
            Node* temp = new Node(s);
            t->right = temp;
            return;
        }
        insert(s,t->right);
    }
}

//search
bool Tree::search(const string &s){
    return search(s,root);
}
bool Tree::search(const string &s, Node* t){
    
    
    //if value is less than, then search left
    if(t){
        if(s < t->str){
            return search(s,t->left);
        }
        //if greater than, search right
        else if(s > t->str){
            return search(s,t->right);
        }
        //if it passes the first 2, it must be true;
        return true;
    }
    return false;
}

//preorder
void Tree::preOrder(){
    preOrder(root);
    cout << endl;
}
void Tree::preOrder(Node* t){
    if(t){
        cout << t->str << "(" << t->count << "), ";
        preOrder(t->left);
        preOrder(t->right);
    }
}

//inorder
void Tree::inOrder(){
    inOrder(root);
    cout << endl;
}
void Tree::inOrder(Node* t){
    if(t){
        inOrder(t->left);
        cout << t->str << "(" << t->count << "), ";
        inOrder(t->right);
    }
}

//postorder
void Tree::postOrder(){
    postOrder(root);
    cout << endl;
}
void Tree::postOrder(Node* t){
    if(t){
        postOrder(t->left);
        postOrder(t->right);
        cout << t->str << "(" << t->count << "), ";
    }
}

//returns largest
string Tree::largest(){
    return largest(root);
}
string Tree::largest(Node* t){
    //if a right node exists, call on right
    if(t->right){
        return largest(t->right);
    }
    //if t right is not found, then largest value found
    return t->str;
}

//returns smallest
string Tree::smallest(){
    return smallest(root);
}
string Tree::smallest(Node* t){
    //if left node exists, call on left
    if(t->left){
        return smallest(t->left);
    }
    //if t left is not found, then smallest value found
    return t->str;
}

int Tree::height(const string& s){
    return height(s,root);
}
int Tree::height(const string& s, Node* t){
    static int rCount = -1;
    //value is found
    if(t){
        //starts at root
        //if less than root, then go left
            //return something + 1?
        //if more than, then go right
        if(s < t->str){
            --rCount;
            return height(s,t->left) + 1;
        }
        else if(s > t->str){
            --rCount;
            return height(s,t->right) + 1;
        }
            return 0;
    }
    //how to recursively return so that result is -1
        //case where leaf is not found
        return rCount;
    
}

void Tree::remove(const string &s){
    remove(s,root);
}

/**
 * Cases:
 * 1) The node has been found, and
 *      there is no left and right
 *          just delete the node
 *      there is a right and a left
 *          replace with next left,
 *              iterate until the left's right is a leaf
 *              make the left's last right point to the original right.
 * 
 */
 
void Tree::remove(const string& s, Node* t){
    if(t){
        if(s > t->str){
            remove(s,t->right);
            return;
        }
        if(s < t->str){
            remove(s,t->left);
            return;
        }
        //count is greater than 1
        if(t->count > 1){
            --(t->count);
            return;
        }
        //if leaf
        if(!t->left && !t->right){
            //if root is leaf
            if(t == root){
                root = nullptr;
                return;
            }
            //get parent
            if(t->str < getParent(t)->str){
                getParent(t)->left = nullptr;
            }
            else{
                getParent(t)->right = nullptr;
            }
            return;
        }
        Node* b;
        if(t->left){
            //go left one and then find the right most value
                //if the right most value has a left, then the parent's right is the left of the right
            Node* temp = t->left;
            b = t;
            while(temp->right){
                b = temp;
                temp = temp->right;
            }
            *t = *temp;
            if(t->left && !t->left->right){
                t->left = temp->left;
            }
            else if(temp->left){
                b->right = temp->left;
            }
            else{
                b->right = nullptr;
            }
            return;
        }
        if(t->right){
            //go right one and then find the left most value
                //if the left most value has a right, then the parent's left is the right of the left
            Node* temp = t->right;
            b = t;
            while(temp->left){
                b = temp;
                temp = temp->left;
            }
            *t = *temp;
            if(t->right && !t->right->left){
                t->right = temp->right;
            }
            else if(temp->right){
                b->left = temp->right;
            }
            else{
                b->left = nullptr;
            }
            return;
        }
    }
}

Node* Tree::getParent(Node* child){
    return getParent(root,child);
}

Node* Tree::getParent(Node* temp, Node* child){
    if(temp){
        if(temp->left == child || temp->right == child){
            return temp;   
        }
        if(child->str < temp->str){
            return getParent(temp->left,child);
        }
        if(child->str > temp->str){
            return getParent(temp->right,child);
        }
    }
    cout << "parent not found" << endl;
    return nullptr;
}
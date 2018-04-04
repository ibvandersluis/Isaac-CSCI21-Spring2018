#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <sstream>
#include "node.h"
using namespace std;

class Stack {
    private:
        Node* head_;
        unsigned int size_;
    public:
        Stack();
        ~Stack();
        
        // void SetHead(Node &node);
        // Node* GetHead();
        
        string print();
        Node pop();
        void push(T data);
        int size();
}

#endif
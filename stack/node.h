#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
    public:
        Node();
        Node(string contents);
        
        void set_contents(string contents);
        void set_next_node(Node* next);
        
        string contents() const;
        Node* next_node() const;
    private:
        string contents_;
        Node* next_node_;
};

#endif
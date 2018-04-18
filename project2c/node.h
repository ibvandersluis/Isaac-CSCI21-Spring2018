#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template<typename T>;
class Node {
    public:
        Node();
        Node(T contents);
        
        void set_contents(T contents);
        void set_next_node(Node* next);
        
        T contents() const;
        Node* next_node() const;
    private:
        T contents_;
        Node* next_node_;
};

Node::Node() {
    contents_ = "";
    next_node_ = NULL;
}

Node::Node(T contents) {
    contents_ = contents;
    next_node_ = NULL;
}

void Node::set_contents(T contents) {
    contents_ = contents;
    
    return;
}

void Node::set_next_node(Node* next) {
    next_node_ = next;
    
    return;
}

T Node::contents() const {
    return contents_;
}

Node* Node::next_node() const {
    return next_node_;
}

#endif
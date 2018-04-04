#include "node.h"

Node::Node() {
    contents_ = "";
    next_node_ = NULL;
}

Node::Node(string contents) {
    contents_ = contents;
    next_node_ = NULL;
}

void Node::set_contents(string contents) {
    contents_ = contents;
    
    return;
}

void Node::set_next_node(Node* next) {
    next_node_ = next;
    
    return;
}

string Node::contents() const {
    return contents_;
}

Node* Node::next_node() const {
    return next_node_;
}
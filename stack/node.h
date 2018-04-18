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

#endif
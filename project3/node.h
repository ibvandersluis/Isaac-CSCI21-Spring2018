#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ios>
using namespace std;

class Node {
    public:
        Node();
        Node(string word, unsigned int weight);
        
        void set_contents(string contents);
        void set_weight(unsigned int weight);
        void set_left_node(Node* left);
        void set_right_node(Node* right);
        
        string contents() const;
        unsigned int weight() const;
        Node* left_node() const;
        Node* right_node() const;
    private:
        string contents_;
        unsigned int weight_;
        Node* left_node_;
        Node* right_node_;
};

#endif
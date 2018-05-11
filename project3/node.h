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
        Node();                                                                 // Default constructor
        Node(string word, unsigned int weight);                                 // Overload constructor
        
        void set_contents(string contents);                                     // Mutator
        void set_weight(unsigned int weight);                                   // Mutator
        void set_left_node(Node* left);                                         // Mutator
        void set_right_node(Node* right);                                       // Mutator
        
        string contents() const;                                                // Accessor
        unsigned int weight() const;                                            // Accessor
        Node* left_node() const;                                                // Accessor
        Node* right_node() const;                                               // Accessor
    private:
        string contents_;                                                       // Stores the contents of the node
        unsigned int weight_;                                                   // Stores the weight of the word in contents_
        Node* left_node_;                                                       // Points to left node
        Node* right_node_;                                                      // Points to right node
};

#endif
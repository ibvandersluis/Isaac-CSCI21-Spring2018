#ifndef TREE_H
#define TREE_H

#include "node.h"


class Tree {
    public:
        Tree();                                                                 // Default constructor
        
        Node* root() const;                                                     // Accessor
        unsigned int size() const;                                              // Accessor
        
        void print(Node* root) const;                                           // PrintInOrder function
        void insert(string word, unsigned int weight);                          // Insert function
        void insert(Node* root, Node* node);                                    // Overload insert function (for recursion)
        void prefixes(string pf, Node* node) const;                             // Prints prefixes
    private:
        Node* root_;                                                            // Points to the root node
        unsigned int size_;                                                     // Returns the size of the tree
};

#endif
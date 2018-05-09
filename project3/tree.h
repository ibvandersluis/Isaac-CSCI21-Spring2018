#ifndef TREE_H
#define TREE_H

#include "node.h"


class Tree {
    public:
        Tree();
        
        unsigned int size();
        void printTree();
        void insert(string word, unsigned int weight);
        void remove(string word);
    private:
        Node* root_;
        unsigned int size_;
};

#endif
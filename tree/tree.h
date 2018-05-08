#ifndef TREE_H
#define TREE_H

#include "node.h"

template<typename T>
class Tree {
    public:
        Tree();
        
        unsigned int size();
        void printTree();
        void insert(T value);
        void remove(T value);
    private:
        Node<T>* root_;
        unsigned int size_;
};

template<typename T>
unsigned int Tree<T>::size() {
    return size_;
}

template<typename T>
void Tree<T>::printTree() {
    
}

template<typename T>
void Tree<T>::insert(T value) {
    
}

template<typename T>
void Tree<T>::remove(T value) {
    
}

#endif
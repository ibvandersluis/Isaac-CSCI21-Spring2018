#include "tree.h"

Tree::Tree() {
    root_ = NULL;
    size_ = 0;
}

unsigned int Tree::size() {
    return size_;
}

void Tree::printTree() {
    
}

void Tree::insert(string word, unsigned int weight) {
    Node* temp = new Node(word, weight);
    if (root_ == NULL) {
        root_ = temp;
    } else {
        Node* current = root_;
        if (temp.contents() < current.contents()) {
            current = current->left_node();
        }
    }
}


void Tree::remove(string word) {
    
}
#include "stack.h"

Stack::Stack() {
    size_ = 0;
}

// Stack::~Stack() {
//     for (int j = 0; j < size(); j++) {
//         delete jjjj
//     }
// }

string Stack::print() {
    stringstream SS;
    string print;
    
    //FIXMESTUFF
    
    print = SS.str();
    return print;
}

Node Stack::pop() {
    size_--;
}

void Stack::push(Node* data) {
    head = data;
    size_++;
}

int Stack::size() {
    return size_;
}
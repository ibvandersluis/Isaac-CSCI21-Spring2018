#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <ios>
using namespace std;

template<typename T>
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

/*  Purpose :   Default constructor
 *  Input   :   None
 *  Output  :   None
 */
template<typename T>
Node<T>::Node() {
    contents_ = T();
    next_node_ = NULL;
}

/*  Purpose :   Overload constructor, sets contents_ to specified value
 *  Input   :   1 T value
 *  Output  :   None
 */
template<typename T>
Node<T>::Node(T contents) {
    contents_ = contents;
    next_node_ = NULL;
}

/*  Purpose :   Sets contents to specified value
 *  Input   :   1 T value
 *  Output  :   None
 */
template<typename T>
void Node<T>::set_contents(T contents) {
    contents_ = contents;
    
    return;
}

/*  Purpose :   Sets next_node_ to a specified Node pointer
 *  Input   :   1 Node pointer
 *  Output  :   None
 */
template<typename T>
void Node<T>::set_next_node(Node* next) {
    next_node_ = next;
    
    return;
}

/*  Purpose :   Returns the contents of the node
 *  Input   :   None
 *  Output  :   1 T value
 */
template<typename T>
T Node<T>::contents() const {
    return contents_;
}

/*  Purpose :   Returns next_node_
 *  Input   :   None
 *  Output  :   1 Node pointer
 */
template<typename T>
Node<T>* Node<T>::next_node() const {
    return next_node_;
}

#endif
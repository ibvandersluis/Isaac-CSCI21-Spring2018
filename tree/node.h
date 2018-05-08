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
        void set_left_node(Node* left);
        void set_right_node(Node* right);
        
        T contents() const;
        Node* left_node() const;
        Node* right_node() const;
    private:
        int contents_;
        Node* left_node_;
        Node* right_node_;
};

/*  Purpose :   Default constructor
 *  Input   :   None
 *  Output  :   None
 */
template<typename T>
Node<T>::Node() {
    contents_ = T();
    left_node_ = NULL;
    right_node_ = NULL;
}

/*  Purpose :   Overload constructor, sets contents_ to specified value
 *  Input   :   1 int value
 *  Output  :   None
 */
template<typename T>
Node<T>::Node(T contents) {
    contents_ = contents;
    left_node_ = NULL;
    right_node_ = NULL;
}

/*  Purpose :   Sets contents to specified value
 *  Input   :   1 int value
 *  Output  :   None
 */
template<typename T>
void Node<T>::set_contents(T contents) {
    contents_ = contents;
    
    return;
}

/*  Purpose :   Sets left_node_ to a specified Node pointer
 *  Input   :   1 Node pointer
 *  Output  :   None
 */
template<typename T>
void Node<T>::set_left_node(Node* left) {
    left_node_ = left;
    
    return;
}

/*  Purpose :   Sets right_node_ to a specified Node pointer
 *  Input   :   1 Node pointer
 *  Output  :   None
 */
template<typename T>
void Node<T>::set_right_node(Node* right) {
    right_node_ = right;
    
    return;
}

/*  Purpose :   Returns the contents of the node
 *  Input   :   None
 *  Output  :   1 int value
 */
template<typename T>
T Node<T>::contents() const {
    return contents_;
}

/*  Purpose :   Returns left_node_
 *  Input   :   None
 *  Output  :   1 Node pointer
 */
template<typename T>
Node<T>* Node<T>::left_node() const {
    return left_node_;
}

/*  Purpose :   Returns right_node_
 *  Input   :   None
 *  Output  :   1 Node pointer
 */
template<typename T>
Node<T>* Node<T>::right_node() const {
    return right_node_;
}

#endif
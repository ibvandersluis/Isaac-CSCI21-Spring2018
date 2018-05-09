#include "node.h"

/*  Purpose :   Default constructor
 *  Input   :   None
 *  Output  :   None
 */
Node::Node() {
    contents_ = "";
    weight_ = 0;
    left_node_ = NULL;
    right_node_ = NULL;
}

/*  Purpose :   Overload constructor, sets contents_ to specified value
 *  Input   :   1 int value
 *  Output  :   None
 */
Node::Node(string word, unsigned int weight) {
    contents_ = word;
    weight_ = weight;
    left_node_ = NULL;
    right_node_ = NULL;
}

/*  Purpose :   Sets contents to specified value
 *  Input   :   1 int value
 *  Output  :   None
 */
void Node::set_contents(string contents) {
    contents_ = contents;
    
    return;
}

/*  Purpose :   Sets weight to specified value
 *  Input   :   1 unsigned int value
 *  Output  :   None
 */
void Node::set_weight(unsigned int weight) {
    weight_ = weight;
}

/*  Purpose :   Sets left_node_ to a specified Node pointer
 *  Input   :   1 Node pointer
 *  Output  :   None
 */
void Node::set_left_node(Node* left) {
    left_node_ = left;
    
    return;
}

/*  Purpose :   Sets right_node_ to a specified Node pointer
 *  Input   :   1 Node pointer
 *  Output  :   None
 */
void Node::set_right_node(Node* right) {
    right_node_ = right;
    
    return;
}

/*  Purpose :   Returns the contents of the node
 *  Input   :   None
 *  Output  :   1 int value
 */
string Node::contents() const {
    return contents_;
}

/*  Purpose :   Returns the weight of the node
 *  Input   :   None
 *  Output  :   1 unsigned int value
 */
unsigned int Node::weight() const {
    return weignt_;
}

/*  Purpose :   Returns left_node_
 *  Input   :   None
 *  Output  :   1 Node pointer
 */
Node* Node::left_node() const {
    return left_node_;
}

/*  Purpose :   Returns right_node_
 *  Input   :   None
 *  Output  :   1 Node pointer
 */
Node* Node::right_node() const {
    return right_node_;
}
#include "tree.h"

/*  Purpose :   Default constructor
 *  Input   :   None
 *  Output  :   None
 */
Tree::Tree() {
    root_ = NULL;
    size_ = 0;
}

/*  Purpose :   Returns the Node pointer stored in root_
 *  Input   :   None
 *  Output  :   1 Node pointer
 */
Node* Tree::root() const {
    return root_;
}

/*  Purpose :   Returns the integer stored in size_
 *  Input   :   None
 *  Output  :   1 unsigned int
 */
unsigned int Tree::size() const {
    return size_;
}

/*  Purpose :   Prints entire contents of the tree in ascending order
 *  Input   :   1 Node pointer indicating the tree's root
 *  Output  :   None
 */
void Tree::print(Node* root) const {
    if (root == NULL) {                                                         // If root is NULL,
        return;                                                                 // Returns
    }
    
    print(root->left_node());                                                   // Calls print on left node
    cout << root->contents() << " ";                                            // Prints contents of current node
    print(root->right_node());                                                  // Calls print on right node
    
    return;
}

/*  Purpose :   Inserts a new node of specified value into the tree. Increments size_
 *  Input   :   1 string, 1 unsigned int
 *  Output  :   None
 */
void Tree::insert(string word, unsigned int weight) {
    Node* temp = new Node(word, weight);                                        // Creates Node pointer temp to new node
    if (root_ == NULL) {                                                        // If the tree's root is NULL,
        root_ = temp;                                                           // Sets root_ to temp
    } else {                                                                    // Else,
        insert(root_, temp);                                                    // Calls insert on the new node, starting at the root node
    }
    size_++;                                                                    // Increments size_
    
    return;
}

/*  Purpose :   Inserts a new node of specified value into the tree. Increments size_
 *  Input   :   2 Node pointers
 *  Output  :   None
 */
void Tree::insert(Node* root, Node* node) {
    if (node->weight() <= root->weight()) {                                     // If weight is less than current node's weight,
        if (root->left_node() == NULL) {                                        // And if the node's left node is null,
            root->set_left_node(node);                                          // Sets left node to new node
        } else {                                                                // Else,
            insert(root->left_node(), node);                                    // Calls insert() on the left node
        }
    } else {                                                                    // If weight is greater than current node's weight,
        if (root->right_node() == NULL) {                                       // And if the node's right node is null,
            root->set_right_node(node);                                         // Sets left node to new node
        } else {                                                                // Else
            insert(root->right_node(), node);                                   // Calls insert() on the right node
        }
    }
    
    return;
}

/*  Purpose :   Prints words that have the specified prefix
 *  Input   :   1 string, 1 Node pointer
 *  Output  :   None
 */
void Tree::prefixes(string pf, Node* node) const {
    bool same = false;                                                          // Bool is true if the word contains the prefix
    bool cont = true;                                                           // Bool is true if iteration should continue
    unsigned int i = 0;                                                         // Int for tracking iteration
    if (node == NULL) {                                                         // Returns if node is NULL
        return;
    }
    
    prefixes(pf, node->right_node());                                           // Calls function on right node
    
    if (pf.length() < node->contents().length()) {                              // If prefix is shorter than word,
        while ((cont == true) && (i < pf.length())) {                           // Given these conditions,
            if (pf.at(i) == node->contents().at(i)) {                           // If the letters are equal,
                same = true;                                                    // Set same to true
            } else {                                                            // Else,
                same = false;                                                   // Set same to false
                cont = false;                                                   // Set cont to false
            }
            i++;                                                                // Increment i
        }
        if (same == true) {                                                     // If same is true,
            cout << node->contents() << endl;                                   // Print word
        }
    }
    
    prefixes(pf, node->left_node());                                            // Calls function on left node
}
#ifndef STACK_H
#define STACK_H

#include "node.h"

template<typename T>
class Stack {
    public:
        Stack();                                                                // Default Constructor
        ~Stack();                                                               // Destructor
    
        void set_head(Node<T>* address);                                        // Mutator
        
        void push(T contents);                                                  // Adds an item to the stack
        T pop();                                                                // Removes an item from the stack
        void print();                                                           // Prints all items in the stack
        unsigned int size();                                                    // Returns the number of items in the stack
        bool empty();
    private:
        Node<T>* head_;                                                         // Points to first node in stack
        unsigned int size_;
};

/*  Purpose :   Default constructor
 *  Input   :   None
 *  Output  :   None
 */
template<typename T>
Stack<T>::Stack() {
    head_ = NULL;
    size_ = 0;
}

/*  Purpose :   Destructor
 *  Input   :   None
 *  Output  :   None
 */
template<typename T>
Stack<T>::~Stack() {
    while (head_ != NULL) {
        pop();
    }
}

/*  Purpose :   Sets head_ to a specified Node pointer
 *  Input   :   1 Node pointer
 *  Output  :   None
 */
template<typename T>
void Stack<T>::set_head(Node<T>* address) {
    head_ = address;
    
    return;
}

/*  Purpose :   Pushes contents onto the top of the stack, increments size_
 *  Input   :   1 T value
 *  Output  :   None
 */
template<typename T>
void Stack<T>::push(T contents) {
    Node<T>* temp = new Node<T>;                                                // Created new node of type T, pointed to by temp
    temp->set_contents(contents);                                               // Set new node's contents to specified value
    temp->set_next_node(head_);
    head_ = temp;                                                               // Set head_ to point to new node
    size_++;                                                                    // Increment size_
    
    return;
}

/*  Purpose :   Removes 1 node from the top of the stack, decrements size_
 *  Input   :   None
 *  Output  :   1 T value
 */
template<typename T>
T Stack<T>::pop() {
    Node<T>* temp = head_;                                                      // Create node pointer Temp, point to head_
    T data = head_->contents();                                                 // Store head's contents in a T variable data
    head_ = head_->next_node();                                                 // Point head to head's next node
    delete temp;                                                                // Delete temp
    size_--;                                                                    // Decrement size_
    
    return data;                                                                // Return T value data
}

/*  Purpose :   Prints a statement if empty, prints contents of stack otherwise
 *  Input   :   None
 *  Output  :   None
 */
template<typename T>
void Stack<T>::print() {
    if (empty()) {                                                              // If Stack is empty,
        cout << "The stack is empty" << endl;                                   // Prints statement to user
    } else {                                                                    // Else,
        Node<T>* current;                                                       // Create node pointer current
        cout << "Contents: ";                                                   // Begin print statement
        current = head_;                                                        // Point current to head_
        while (current != NULL) {                                               // While current is not null,
            if (current->next_node() != NULL) {                                 // If current's next node is not null,
                cout << current->contents() << ", ";                            // Prints current's contents with a comma and space appended
            } else {                                                            // If current's next node is null,
                cout << current->contents() << endl;                            // Prints current's contents and a new line
            }
            current = current->next_node();                                     // Set current to current's next node
        }
    }
}

/*  Purpose :   Returns size_
 *  Input   :   None
 *  Output  :   1 unsigned int
 */
template<typename T>
unsigned int Stack<T>::size() {
    return size_;
}

/*  Purpose :   Returns true if empty and false otherwise
 *  Input   :   None
 *  Output  :   1 bool
 */
template<typename T>
bool Stack<T>::empty() {
    return (head_ == NULL);
}

#endif
#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

template<typename T>
class Queue {
    public:
        Queue();                                                                // Default Constructor
        ~Queue();                                                               // Destructor
        
        void set_head(Node<T>* address);                                        // Mutator
        void set_tail(Node<T>* address);                                        // Mutator
        
        void push(T contents);                                                  // Adds an item to the queue
        T pop();                                                                // Removes an item from the queue
        void print();                                                           // Prints all items in the queue
        unsigned int size();                                                    // Returns the number of items in the queue
        bool empty();                                                           // Returns true if the queue is empty
    private:
        Node<T>* head_;                                                         // Points to first node in stack
        Node<T>* tail_;                                                         // Points to last node in stack
        unsigned int size_;                                                     // Stores the size of the queue
};

/*  Purpose :   Default constructor
 *  Input   :   None
 *  Output  :   None
 */
template<typename T>
Queue<T>::Queue() {
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

/*  Purpose :   Destructor
 *  Input   :   None
 *  Output  :   None
 */
template<typename T>
Queue<T>::~Queue() {
    while (head_ != NULL) {
        pop();
    }
}

/*  Purpose :   Sets head_ to a specified Node pointer
 *  Input   :   1 Node pointer
 *  Output  :   None
 */
template<typename T>
void Queue<T>::set_head(Node<T>* address) {
    head_ = address;
    
    return;
}

/*  Purpose :   Sets tail_ to a specified Node pointer
 *  Input   :   1 Node pointer
 *  Output  :   None
 */
template<typename T>
void Queue<T>::set_tail(Node<T>* address) {
    tail_ = address;
    
    return;
}

/*  Purpose :   Pushes contents onto the back of the queue, increments size_
 *  Input   :   1 T value
 *  Output  :   None
 */
template<typename T>
void Queue<T>::push(T contents) {
    Node<T>* temp = new Node<T>;                                                // Created new node of type T, pointed to by temp
    temp->set_contents(contents);                                               // Set new node's contents to specified value
    if (empty()) {                                                              // If queue is empty,
        head_ = temp;                                                           // Set head_ to point to new node
        tail_ = temp;                                                           // Set tail_ to point to new node
    } else {                                                                    // Else,
        tail_->set_next_node(temp);                                             // Set current tail's next node to new node
        tail_ = temp;                                                           // Set tail_ to point to new node
    }
    size_++;                                                                    // Increment size_
    
    return;
}

/*  Purpose :   Removes 1 node from the front of the queue, decrements size_
 *  Input   :   None
 *  Output  :   1 T value
 */
template<typename T>
T Queue<T>::pop() {
    Node<T>* temp = head_;                                                      // Create node pointer Temp, point to head_
    T data = head_->contents();                                                 // Store head's contents in a T variable data
    head_ = head_->next_node();                                                 // Point head to head's next node
    delete temp;                                                                // Delete temp
    size_--;                                                                    // Decrement size_
    
    return data;                                                                // Return T value data
}

/*  Purpose :   Prints a statement if empty, prints contents of queue otherwise
 *  Input   :   None
 *  Output  :   None
 */
template<typename T>
void Queue<T>::print() {
    if (empty()) {                                                              // If queue is empty,
        cout << "The queue is empty" << endl;                                   // Prints statement to user
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
unsigned int Queue<T>::size() {
    return size_;
}

/*  Purpose :   Returns true if empty and false otherwise
 *  Input   :   None
 *  Output  :   1 bool
 */
template<typename T>
bool Queue<T>::empty() {
    return (head_ == NULL);
}

#endif
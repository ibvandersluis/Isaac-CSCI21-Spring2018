#include "node.h"

template<typename T>;
class Stack {
    public:
        Stack();                                                                // Default Constructor
        ~Stack();                                                               // Destructor
    
        void set_head(Node* address);                                           // Mutator
        void set_tail(Node* address);                                           // Mutator
        
        void push();                                                            // Adds an item to the stack
        void pop();                                                             // Removes an item from the stack
        void print();                                                           // Prints all items in the stack
        unsigned int size();                                                    // Returns the number of items in the stack
    private:
        Node<T>* head_;                                                         // Points to first node in stack
};
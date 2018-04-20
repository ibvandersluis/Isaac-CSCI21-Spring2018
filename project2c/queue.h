#include "node.h"

template<typename T>;
class Queue {
    public:
        Queue();                                                                // Default Constructor
        ~Queue();                                                               // Destructor
        
        void set_head(Node* address);                                           // Mutator
        void set_tail(Node* address);                                           // Mutator
        
        void push();                                                            // Adds an item to the queue
        void pop();                                                             // Removes an item from the queue
        void print();                                                           // Prints all items in the queue
        unsigned int size();                                                    // Returns the number of items in the queue
    private:
        Node* head_;                                                            // Points to first node in stack
        Node* tail_;                                                            // Points to last node in stack
};
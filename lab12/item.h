/*
 *  Name:               Lab 12
 *  Written by:         Isaac Vander Sluis
 *  Created on:         2/18/18
 *
 *  Description:        Class header file
 *
 */
#ifndef item_h
#define item_h

#include <string>
#include <iostream>

class Item {
    public:
        Item(string name, unsigned int val);                                    // Constructor
        virtual ~Item();                                                        // Destructor
        
        void SetName(string name);                                              // Mutator
        void SetValue(unsigned int val);                                        // Mutator
        
        string GetName() const;                                                 // Accessor
        unsigned int GetValue() const;                                          // Accessor
        
        string ToString() const;                                                // Returns name_ and value_ in a string
    private:
        string name_;                                                           // Holds name of item
        unsigned int value_;                                                    // Holds value of item
};

#endif
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
#include <sstream>
using namespace std;

class Item {
    public:
        Item();                                                                 // Default constructor
        Item(string name, unsigned int val);                                    // Secondary constructor
        virtual ~Item();                                                        // Destructor
        
        void name(string name);                                                 // Mutator
        void value(unsigned int val);                                           // Mutator
        
        string GetName() const;                                                 // Accessor
        unsigned int GetValue() const;                                          // Accessor
        
        string ToString() const;                                                // Returns name_ and value_ in a string
    private:
        string name;                                                           // Holds name of item
        unsigned int value;                                                    // Holds value of item
};

#endif
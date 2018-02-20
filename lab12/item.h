/*
 *  Name:               Lab 12
 *  Written by:         Isaac Vander Sluis
 *  Created on:         2/17/18
 *
 *  Description:        Class header file
 *
 */
#ifndef item_h
#define item_h

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ios>
using namespace std;
using std::setprecision;

class Item {
    public:
        Item();                                                                 // Default constructor
        Item(string name, unsigned int val);                                    // Secondary constructor
        virtual ~Item();                                                        // Destructor
        
        void set_name(string name);                                             // Mutator
        void set_value(unsigned int val);                                       // Mutator
        
        string name() const;                                                    // Accessor
        unsigned int value() const;                                              // Accessor
        
        string ToString() const;                                                // Returns name_ and value_ in a string
    protected:
        string name_;                                                           // Holds name of item
        unsigned int value_;                                                    // Holds value of item
};

#endif
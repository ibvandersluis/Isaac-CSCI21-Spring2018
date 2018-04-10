#ifndef PROJ1AUX_H                                                              // Header Guards
#define PROJ1AUX_H

#include <iostream>                                                             // #include appropriate libraries
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <queue>
using namespace std;

class Computer;

class Board {                                                                   // Board class
    public:
        Board();                                                                // Default constructor
        Board(vector<char> board);                                              // Overload constructor
        
        void setBoard(char c);                                                  // Mutator
        void setBoard(unsigned int index, char c);                              // Overload mutator
        
        vector<char> getBoard() const;                                          // Accessor
        char getBoard(unsigned int index) const;                                // Overload accessor
        
        void print() const;                                                     // Prints formatted board
        void populate(string filename);                                         // Populates a game board from a specified file
    private:
        vector<char> board_;                                                    // The game board stored as a char vector
};

class Player {                                                                  // Base class for Human and Computer
    public:
        void printTop();                                                        // Function that prints the player's top board
        void setTop(char c);                                                    // Mutator
        void setTop(unsigned int index, char c);                                // Overload mutator
        
        void printBottom();                                                     // Function that prints the player's bottom board
        void setBottom(char c);                                                 // Mutator
        void setBottom(unsigned int index, char c);                             // Overload mutator
        
        void setHits(unsigned int hits);                                        // Mutator
        
        vector<char> getTop() const;                                            // Accessor
        char getTop(unsigned int index) const;                                  // Overload accessor
        
        vector<char> getBottom() const;                                         // Accessor
        char getBottom(unsigned int index) const;                               // Overload accessor
        
        unsigned int getHits();                                                 // Accessor
        
        void populateBottom(string filename);                                   // Populates the player's bottom board with the contents of a specified file
        
        virtual void attack();                                                  // Requires subclasses to define "attack"
    protected:
        Board top_;                                                             // Shows the player's "top" screen, with the shots they've made and their hits and misses
        Board bottom_;                                                          // Shows the player's "bottom" screen, with their ships and the opponent's hits and misses
        unsigned int hits_;                                                     // Tracks the number of hits the player has. Player wins when they have 17 hits.
};

class Human : public Player {                                                   // Human class
    public:
        Human();                                                                // Constructor
        
        void attack(unsigned int index, Computer &target);                      // Attacks a square on the opponents's board
    private:
        
};

class Computer : public Player {                                                // Computer class
    public:
        Computer();                                                             // Constructor
        
        void setNext(unsigned int index);                                       // Mutator
        
        int getNext();                                                          // Accessor
        
        void attack(Human &target);                                             // Attacks random square if queue is empty, else attacks the next item in the queue
    private:
        queue<int> next_;                                                       // Stores the computer's next attacks, if applicable
};

#endif
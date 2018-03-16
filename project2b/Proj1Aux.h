#ifndef PROJ1AUX_H                                                              // Header Guards
#define PROJ1AUX_H

#include <iostream>                                                             // #include appropriate libraries
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Player {                                                                  // Empty class Player, base class for Human and Computer
    public:
    protected:
};

class Human : public Player {                                                   // Human class
    public:
        Human();
    private:
};

class Computer : public Player {                                                // Computer class
    public:
        Computer();
    private:
};

class Board {                                                                   // Board class
    public:
        Board();                                                                // Default constructor
        Board(vector<char> board);                                              // Overload constructor
        
        void SetBoard(char ch);                                                 // Mutator
        void SetBoard(unsigned int index, char ch);                             // Overload mutator
        
        vector<char> GetBoard() const;                                          // Accessor
        char GetBoard(unsigned int index) const;                                // Overload accessor
        
        void Print() const;                                                     // Prints formatted board
        void Populate();                                                        // Prompts user for import file and populates board from it
    private:
        vector<char> board_;                                                    // The game board stored as a char vector
};

void PlayBattleship(Board &player, Board &game);                                // Function for playing Battleship

#endif
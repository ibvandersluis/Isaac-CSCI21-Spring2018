#ifndef PROJ1AUX_H                                                              // Header Guards
#define PROJ1AUX_H

#include <iostream>                                                             // #include appropriate libraries
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Player {                                                                  // Empty class Player, base class for Human and Computer
    public:
        
        virtual void PrintBoard();                                              // Punction that prints the object's game board
    protected:
};

class Human : public Player {                                                   // Human class
    public:
        Human();
        
        void PrintBoard();
        void PlayBattleship(); //FIXME// modify for function call from Human class
    private:
        Board top_screen;                                                       // This board shows the player's view of their hits and misses on the enemy
        Board bottom_screen;                                                    // This board shows the player's view of their ships and the enemy's hits and misses
};

class Computer : public Player {                                                // Computer class
    public:
        Computer();
        
        void PrintBoard();
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
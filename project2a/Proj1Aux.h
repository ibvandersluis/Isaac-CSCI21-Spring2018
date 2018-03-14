#ifndef PROJ1AUX_H
#define PROJ1AUX_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Player {
    public:
    protected:
};

class Human : public Player {
    public:
        Human();
    private:
};

class Computer : public Player {
    public:
        Computer();
    private:
};

class Board {
    public:
        Board();
        Board(vector<char> board);
        
        void SetBoard(char ch);
        void SetBoard(unsigned int index, char ch);
        
        vector<char> GetBoard() const;
        char GetBoard(unsigned int index) const;
        
        void Print() const;
    private:
        vector<char> board_;
};

void PlayGame(Board &player, Board &game);

#endif
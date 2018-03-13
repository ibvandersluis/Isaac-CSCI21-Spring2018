#ifndef PROJ1AUX_H
#define PROJ1AUX_H

#include <iostream>
#include <vector>
#include <fstream>
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
        
        vector<char> GetBoard() const;
        
        void Print() const;
    private:
        vector<char> board_;
};

#endif
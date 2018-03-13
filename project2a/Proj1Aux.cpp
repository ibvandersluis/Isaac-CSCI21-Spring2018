#include "Proj1Aux.h"


////////// HUMAN MEMBER FUNCTIONS //////////

Human::Human() {
    
}

////////// COMPUTER MEMBER FUNCTIONS //////////

Computer::Computer() {
    
}

////////// BOARD MEMBER FUNCTIONS //////////

Board::Board() {
    
}

Board::Board(vector<char> board) {
    board_ = board;
}

void Board::SetBoard(char ch) {
    board_.push_back(ch);
    
    return;
}

vector<char> Board::GetBoard() const {
    return board_;
}

void Board::Print() const {
    char row = 'A';
    unsigned int factor = 0;
    unsigned int col;
    cout << endl << "  ";
    for (col = 0; col < 10; col++) {
        cout << col << " ";
    }
    for (unsigned int i = 0; i < 10; i++) {
        cout << endl << row << " ";
        for (unsigned int j = factor; j < factor + 10; j++) {
            cout << board_.at(j) << " ";
        }
        row++;
        factor += 10;
    }
    cout << endl << endl;
}
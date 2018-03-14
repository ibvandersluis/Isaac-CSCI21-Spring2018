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

void Board::SetBoard(unsigned int index, char ch) {
    board_.at(index) = ch;
    
    return;
}

vector<char> Board::GetBoard() const {
    return board_;
}

char Board::GetBoard(unsigned int index) const {
    return board_.at(index);
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

void PlayGame(Board &player, Board &game) {
    unsigned int hits = 0;
    unsigned int turn = 1;
    string square = "";
    stringstream SS;
    char result;
    char rowchar = 'K';
    char colchar = '0';
    vector<int> rows;
    vector<int> cols;
    
    while (hits < 17) {
        rowchar = 'K';
        cout << endl << "Turn: " << turn << endl;
        cout << "Hits: " << hits << endl;
        player.Print();
        while ((rowchar < 65 || rowchar > 74) || (colchar < 48 || colchar > 57)) {
            cout << "Enter the letter and number of the square you wish to attack (Ex: A1): ";
            cin >> square;
            
            SS << square;
            SS >> rowchar;
            SS >> colchar;
            
            if (rowchar >= 97 && rowchar <= 106) {
                rowchar -= 32;
            }
        }
        
        if (SS.rdbuf()->in_avail() == 0) {
            cout << "ERROR: Extra characters ignored." << endl;
        }
        
        SS.str("");
        
        int row = rowchar - 65;
        int col = colchar - 48;
        int pos = row * 10 + col;
        char square = game.GetBoard(pos);
        
        if (square == 'S' || square == 'o') {
                if (square == 'S') {
                result = 'H';
            } else {
                result = 'M';
            }
            
            game.SetBoard(pos, result);
            player.SetBoard(pos, result);
            
            if (result == 'H') {
                bool found = false;
                for (unsigned int i = 0; i < rows.size(); i++) {
                    if ((rows.at(i) == row && cols.at(i) == col)) {
                        found = true;
                    }
                }
                if (found == false) {
                    hits++;
                }
            }
        }
        
        cout << "Player's board:" << endl;
        player.Print();
        cout << "Game board:" << endl;
        game.Print();
        
        rows.push_back(row);
        cols.push_back(row);
        turn++;
    }
    
    cout << "Congratulations, you've won!" << endl;
    
    return;
}
#include "Proj1Aux.h"

int main() {
    Board       gameboard;
    string      filename;
    ifstream    inFS;
    ofstream    outFS;
    char        c;
    
    cout << "Welcome to Battleship!" << endl << endl;
    
    cout << "Enter file name to import game board: ";
    cin >> filename;
    
    inFS.open(filename.c_str());
    if (!inFS.is_open()) {                                                      //prints error if file won't open
        cout << "Could not open file " << filename << endl;
        return 1;
    }
    
    while (!inFS.eof()) {
        inFS >> c;
        gameboard.SetBoard(c);
    }
    
    gameboard.Print();
    
    
}
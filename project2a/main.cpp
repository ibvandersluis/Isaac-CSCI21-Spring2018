#include "Proj1Aux.h"

int main() {
    Board       gameboard;
    Board       playerboard;
    string      filename;
    ifstream    inFS;
    ofstream    outFS;
    char        c;
    
    for (unsigned int i = 0; i < 100; i++) {
        playerboard.SetBoard('o');
    }
    
    cout << "Welcome to Battleship!" << endl << endl;
    
    cout << "Enter file name to import game board: ";
    cin >> filename;
    
    inFS.open(filename.c_str());
    while (!inFS.is_open()) {                                                      //prints error if file won't open
        cout << "Could not open file " << filename << endl;
        cout << "Please enter a valid file name: ";
        cin >> filename;
        inFS.open(filename.c_str());
    }
    
    while (!inFS.eof()) {
        inFS >> c;
        gameboard.SetBoard(c);
    }
    
    inFS.close();
    
    PlayGame(playerboard, gameboard);
    
}
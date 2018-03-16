#include "Proj1Aux.h"

int main() {
    Board       gameboard;                                                      // Board object for storing the game board
    Board       playerboard;                                                    // Board object for storing the board the player sees
    
    cout << "Welcome to Battleship Solitaire!" << endl << endl;                 // Prints greeting and instructions to user
    cout << "This is a single player version of the naval warfare game Battleship." << endl;
    cout << "Import a pre-configured game board and try to win in the fewest turns possible!" << endl << endl;
    
    gameboard.Populate();                                                       // Imports board template and populates the game board object
    
    PlayBattleship(playerboard, gameboard);                                     // Runs the Battleship game function
    
    return 0;
}
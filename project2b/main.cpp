#include "Proj1Aux.h"

int main(int argc, char* argv[]) {                                              // Initializes the main function with two command line functions
    Human human;                                                                // Initializes Human object to represent the human player
    Computer computer;                                                          // Initializes Computer object to represent the computer player
    
    human.populateBottom(argv[1]);                                              // Populates human's bottom board with first command line arg
    computer.populateBottom(argv[2]);                                           // Populates computer's bottom board with second command line arg
    
    cout << "WELCOME TO BATTLESHIP!" << endl << endl;                           // Prints greeting and instructions to user
    cout << "This is a single player version of the naval warfare game Battleship." << endl;
    cout << "You will play against a computer. Try to sink all of their ships before they sink yours!" << endl << endl;
    
    string square = "";                                                         // For user input
    stringstream SS;                                                            // For separating input into characters
    char rowchar = 'K';                                                         // Character for tracking row
    char colchar;                                                               // Character for tracking column
    bool human_goes_first;                                                      // Boolean value to determine who goes first
    bool too_big = false;                                                       // Boolean is true when user input is too long
    srand(time(0));                                                             // Seeds random with current time
    
    if (argc < 3 || argc > 4) {                                                 // If there are too many or too few arguments
        cout << "Usage: ./execute playerboard computerboard (optional)firstmove" << endl;
                                                                                // Prints message to user advising how to implement the command line arguments
        return 1;
    }
    
    if (argv[3] == NULL) {                                                      // If the player to move first has not been specified,
        human_goes_first = rand() % 2;                                          // first player is random
    } else if(!strcmp(argv[3], "HUMAN")) {                                      // If HUMAN is specified,
        human_goes_first = true;                                                // Set to true
    } else if(!strcmp(argv[3], "COMPUTER")) {                                   // If COMPUTER is specified,
        human_goes_first = false;                                               // Set to false
    } else {                                                                    // Else, further specification on usage
        cout << "If used, 3rd command line argument must be either 'HUMAN' or 'COMPUTER'" << endl;
        
        return 1;
    }
    
    while ((human.getHits() < 17) && (computer.getHits() < 17)) {
        rowchar = 'K';                                                          // Initializes to out-of-range value
        too_big = false;                                                        // Initializes to false
        if (human_goes_first == true) {
            cout << "Your turn, human!" << endl;
            cout << "Hits: " << human.getHits() << endl;                        // Prints number of hits
            cout << endl << "Top board:" << endl;                               
            human.printTop();                                                   // Prints player's view of oppenent's board
            cout << endl << "Bottom board: " << endl;
            human.printBottom();                                                // Prints player's view of their own board
            while ((rowchar < 65 || rowchar > 74) || (colchar < 48 || colchar > 57)) {
                cout << "Enter the letter and number of the square you wish to attack (Ex: A1): ";
                getline(cin, square);                                           // Prompts user for valid move
                if (square.length() > 2) {                                      // Sets too_big to true if input exceeds 2 characters
                    too_big = true;
                }
                
                SS << square;                                                   // Puts into stringstream
                SS >> rowchar;                                                  // Gets row
                SS >> colchar;                                                  // Gets column
                
                if (rowchar >= 97 && rowchar <= 106) {                          // If user entered lower case letter, makes it upper case
                    rowchar -= 32;
                }
            }
            
            if (too_big == true) {                                              // Prints error if input too long
                cout << endl << "ERROR: Extra characters ignored." << endl;
            }
            
            SS.str("");                                                         // Clears stringstream
            
            int row = rowchar - 65;                                             // Turns row character into a number
            int col = colchar - 48;                                             // Turns column character into a number
            int pos = row * 10 + col;                                           // Determines index player is attacking in board_
            human.attack(pos, computer);
        }
        if (human.getHits() < 17) {
            human_goes_first = true;                                            // Previous if-statement will now execute on all subsequent loops
        
            computer.attack(human);
        }
    }
    
    if (human.getHits() == 17) {                                                // Checks the number of hits the human has
        cout << endl << "You won!" << endl;                                     // If they have 17 hits, states that they won
    } else {
        cout << endl << "You lost." << endl;                                    // Otherwise, states that they lost
    human.setHits(human.getHits() + 1);
    }
    
    cout << endl << "GOOD GAME" << endl;                                        // Computer is a good sport, so says good game either way
    
    cout << endl << "Your opponent's board: " << endl;                          // Shows the opponent's board
    
    computer.printBottom();
    
    return 0;
}
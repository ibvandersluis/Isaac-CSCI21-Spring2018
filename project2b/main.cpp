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
    
    if (argc < 2 || argc > 3) {
        cout << "Usage: ./exectue playerboard computerboard (optional)firstmove" << endl;
        
        return 1;
    }
    
    if (argv[3] == NULL) {
        human_goes_first = rand() % 2;
    } else if(argv[3] == "HUMAN") {
        human_goes_first = true;
    } else if(argv[3] == "COMPUTER") {
        human_goes_first = false;
    } else {
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
                cin >> square;                                                  // Prompts user for valid move
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
        human_goes_first = true;                                                // Previous if-statement will now execute on all subsequent loops
        
        computer.attack(human);
    }
    
    if (human.getHits() == 17) {
        cout << endl << "You won!" << endl;
    } else {
        cout << endl << "You lost." << endl;
    }
    
    cout << endl << "GOOD GAME" << endl;
    
    cout << endl << "Your opponent's board: " << endl;
    
    computer.printBottom();
    
    return 0;
}
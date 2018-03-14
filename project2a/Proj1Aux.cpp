#include "Proj1Aux.h"


////////// HUMAN MEMBER FUNCTIONS //////////

Human::Human() {
    
}

////////// COMPUTER MEMBER FUNCTIONS //////////

Computer::Computer() {
    
}

////////// BOARD MEMBER FUNCTIONS //////////

/*  Purpose :   Default constructor
 *  Input   :   None
 *  Output  :   None
 */
Board::Board() {
    for (unsigned int i = 0; i < 100; i++) {                                    // Creates a blank board
        SetBoard('o');
    }
}

/*  Purpose :   Overload constructor
 *  Input   :   1 character vector
 *  Output  :   None
 */
Board::Board(vector<char> board) {
    board_ = board;
}

/*  Purpose :   Pushes back a character onto objects board_ vector
 *  Input   :   1 character
 *  Output  :   None
 */
void Board::SetBoard(char ch) {
    board_.push_back(ch);
    
    return;
}

/*  Purpose :   Sets specified element in board_ vector to specified value
 *  Input   :   1 unsigned int, 1 character
 *  Output  :   None
 */
void Board::SetBoard(unsigned int index, char ch) {
    board_.at(index) = ch;
    
    return;
}

/*  Purpose :   Returns all values stored in board_ vector
 *  Input   :   None
 *  Output  :   1 char vector
 */
vector<char> Board::GetBoard() const {
    return board_;
}

/*  Purpose :   Returns the value stored in board_ vector at specified index
 *  Input   :   1 unsigned int
 *  Output  :   1 char
 */
char Board::GetBoard(unsigned int index) const {
    return board_.at(index);
}

/*  Purpose :   Prints contents of board_ in a formatted Battleship game board
 *  Input   :   None
 *  Output  :   No return, prints game board
 */
void Board::Print() const {
    char row = 'A';                                                             // Initializes row to A
    unsigned int factor = 0;                                                    // Initializes to 0 for printing aligned columns
    unsigned int col;                                                           // Tracks columns
    cout << endl << "  ";                                                       // Whitespace
    for (col = 0; col < 10; col++) {                                            // Prints header that labels each column
        cout << col << " ";
    }
    for (unsigned int i = 0; i < 10; i++) {                                     // For each row,
        cout << endl << row << " ";                                             // Prints row letter
        for (unsigned int j = factor; j < factor + 10; j++) {                   // Followed by the next 10 characters in board_
            cout << board_.at(j) << " ";
        }
        row++;                                                                  // Increments row
        factor += 10;                                                           // Increments factor
    }
    cout << endl << endl;                                                       // Whitespace
}

/*  Purpose :   Prompts user for file to populate board_ with, opens file and populates vector
 *  Input   :   None, gets file name from user
 *  Output  :   None
 */
void Board::Populate() {
    ifstream inFS;
    string filename;
    char c;
    unsigned int i = 0;
    
    cout << "Enter file name to import game board: ";                           // Prompts user for import file
    cin >> filename;
    
    inFS.open(filename.c_str());                                                // Opens file
    while (!inFS.is_open()) {                                                   // Prints error if file won't open
        cout << "Could not open file " << filename << endl;
        cout << "Please enter a valid file name: ";                             // Re-prompts user for file
        cin >> filename;
        inFS.open(filename.c_str());
    }
    
    while (!inFS.eof() && i < 100) {                                            // Populates board_ vector
        inFS >> c;
        SetBoard(i, c);
        i++;
    }
    
    inFS.close();                                                               // Closes file
}

/*  Purpose :   Plays Battleship game
 *  Input   :   2 pass-by-reference Board objects
 *  Output  :   No return, prints Battleship process until game is finished
 */
void PlayBattleship(Board &player, Board &game) {
    unsigned int hits = 0;                                                      // Tracks number of hits player has made
    unsigned int turn = 1;                                                      // Tracks number of turns
    string square = "";                                                         // For user input
    stringstream SS;                                                            // For separating input into characters
    char result;                                                                // Stores the result of the attack
    char rowchar;                                                               // Character for tracking row
    char colchar;                                                               // Character for tracking column
    vector<char> rows;                                                          // Parallell vectorss for tracking previous attacks
    vector<char> cols;
    bool too_big;                                                               // Boolean is true when user input is too long
    
    while (hits < 17) {
        rowchar = 'K';                                                          // Initializes to out-of-range value
        too_big = false;                                                        // Initializes to false
        cout << endl << "Turn: " << turn << endl;                               // Prints current turn
        cout << "Hits: " << hits << endl;                                       // Prints number of hits
        player.Print();                                                         // Prints player's view of board
        while ((rowchar < 65 || rowchar > 74) || (colchar < 48 || colchar > 57)) {
            cout << "Enter the letter and number of the square you wish to attack (Ex: A1): ";
            cin >> square;                                                      // Prompts user for valid move
            if (square.length() > 2) {                                          // Sets too_big to true if input exceeds 2 characters
                too_big = true;
            }
            
            SS << square;                                                       // Puts into stringstream
            SS >> rowchar;                                                      // Gets row
            SS >> colchar;                                                      // Gets column
            
            if (rowchar >= 97 && rowchar <= 106) {                              // If user entered lower case letter, makes it upper case
                rowchar -= 32;
            }
        }
        
        if (too_big == true) {                                                  // Prints error if input too long
            cout << endl << "ERROR: Extra characters ignored." << endl;
        }
        
        SS.str("");                                                             // Clears stringstream
        
        int row = rowchar - 65;                                                 // Turns row character into a number
        int col = colchar - 48;                                                 // Turns column character into a number
        int pos = row * 10 + col;                                               // Determines index player is attacking in board_
        char square = game.GetBoard(pos);                                       // Tracks character that represents the square being attacked
        
        if (square == 'S' || square == 'o') {                                   // If square hasn't been previously attacked,
                if (square == 'S') {                                            // Sets result to appropriate character
                result = 'H';
            } else {
                result = 'M';
            }
            
            game.SetBoard(pos, result);                                         // Sets attacked square to display the result of the attack
            player.SetBoard(pos, result);
            
            if (result == 'H') {                                                // If it's a hit,
                bool found = false;                                             // Initializes found to false
                for (unsigned int i = 0; i < rows.size(); i++) {                // Iterates through parallel vectors
                    if ((rows.at(i) == rowchar && cols.at(i) == colchar)) {     // If square has been attacked before,
                        found = true;                                           // found is true
                    }
                }
                if (found == false) {                                           // If found is false
                    hits++;                                                     // Increments hit counter
                }
            }
        }
        
        cout << endl << "Player's board:" << endl;                              // Prints player's board
        player.Print();
        cout << "Game board:" << endl;                                          // Prints game board
        game.Print();
        
        rows.push_back(rowchar);                                                // Adds row character to parallel vectors
        cols.push_back(colchar);                                                // Adds column character to parallel vectors
        turn++;                                                                 // Increments turn counter
    }
    
    cout << "Congratulations, you've won!" << endl << endl;                     // Prints message after all ships have been sunk
    
    return;
}
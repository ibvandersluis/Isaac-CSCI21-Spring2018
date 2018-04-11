#include "Proj1Aux.h"

////////// BOARD MEMBER FUNCTIONS //////////

/*  Purpose :   Default constructor
 *  Input   :   None
 *  Output  :   None
 */
Board::Board() {
    board_.resize(0);
    for (unsigned int i = 0; i < 100; i++) {                                    // Creates a blank board
        setBoard('o');
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
void Board::setBoard(char c) {
    board_.push_back(c);
    
    return;
}

/*  Purpose :   Sets specified element in board_ vector to specified value
 *  Input   :   1 unsigned int, 1 character
 *  Output  :   None
 */
void Board::setBoard(unsigned int index, char ch) {
    board_.at(index) = ch;
    
    return;
}

/*  Purpose :   Returns all values stored in board_ vector
 *  Input   :   None
 *  Output  :   1 char vector
 */
vector<char> Board::getBoard() const {
    return board_;
}

/*  Purpose :   Returns the value stored in board_ vector at specified index
 *  Input   :   1 unsigned int
 *  Output  :   1 char
 */
char Board::getBoard(unsigned int index) const {
    return board_.at(index);
}

/*  Purpose :   Prints contents of board_ in a formatted Battleship game board
 *  Input   :   None
 *  Output  :   No return, prints game board
 */
void Board::print() const {
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
void Board::populate(string filename) {
    ifstream inFS;
    char c;
    unsigned int i = 0;
    
    inFS.open(filename.c_str());                                                // Opens file
    while (!inFS.is_open()) {                                                   // Prints error if file won't open
        cout << "Could not open file " << filename << endl;
        cout << "Please enter a valid file name: ";                             // Re-prompts user for file
        cin >> filename;
        inFS.open(filename.c_str());
    }
    
    while (!inFS.eof() && i < 100) {                                            // Populates board_ vector
        inFS >> c;
        setBoard(i, c);
        i++;
    }
    
    inFS.close();                                                               // Closes file
}

////////// PLAYER MEMBER FUNCTIONS //////////

Player::Player() {
    hits_ = 0;
}

Player::~Player() {
    
}

void Player::printTop() {
    top_.print();
    
    return;
}

void Player::setTop(char c) {
    top_.setBoard(c);
    
    return;
}

void Player::setTop(unsigned int index, char c) {
    top_.setBoard(index, c);
    
    return;
}

void Player::printBottom() {
    bottom_.print();
    
    return;
}

void Player::setBottom(char c) {
    bottom_.setBoard(c);
    
    return;
}

void Player::setBottom(unsigned int index, char c) {
    bottom_.setBoard(index, c);
    
    return;
}

void Player::setHits(unsigned int hits) {
    hits_ = hits;
}

vector<char> Player::getTop() const {
    return top_.getBoard();
}

char Player::getTop(unsigned int index) const {
    return top_.getBoard(index);
}

vector<char> Player::getBottom() const {
    return bottom_.getBoard();
}

char Player::getBottom(unsigned int index) const {
    return bottom_.getBoard(index);
}

unsigned int Player::getHits() {
    return hits_;
}

void Player::populateBottom(string filename) {
    bottom_.populate(filename);
    
    return;
}

////////// HUMAN MEMBER FUNCTIONS //////////

Human::Human() {
    hits_ = 0;
}

void Human::attack(unsigned int index, Computer &target) {
    char square = target.getBottom(index);                                      // Stores the value stored in the square being attacked
    char result;                                                                // Stores the result of the attack
    
    if (getTop(index) == 'H') {                                                 // Chides user if square has been attacked before
        cout << endl << "You already attacked that square, genius." << endl << endl;
    } else {                                                                    // If square hasn't been previously attacked,
        if (square == 'S') {                                                    // Sets result to appropriate character
            result = 'H';
        } else {
            result = 'M';
        }
        
        target.setBottom(index, result);                                        // Sets attacked square to display the result of the attack
        setTop(index, result);
        
        if (result == 'H') {                                                    // If it's a hit,
            hits_++;                                                            // Increment human's hit counter
        }
        
        cout << endl;                                                           // Whitespace
        if (result == 'H') {
            cout << "It's a HIT!";                                              // Lets player know if it was a hit or a miss
        } else {
            cout << "It's a MISS!";
        }
        cout << endl << endl;                                                   // Whitespace
    }
    
    return;
}

////////// COMPUTER MEMBER FUNCTIONS //////////

Computer::Computer() {
    hits_ = 0;
}

void Computer::setNext(unsigned int index) {
    next_.push(index);
    
    return;
}

unsigned int Computer::getNext() {
    unsigned int val = next_.front();
    next_.pop();
    
    return val;
}

void Computer::attack(Human &target) {
    unsigned int index;                                                         // Stores number the square to be attacked
    char row;                                                                   // Stores the row that was attacked
    char col;                                                                   // Stores the column that was attacked
    char square;                                                                // Stores the value stored in the square being attacked
    char result;                                                                // Stores the result of the attack
    
    if (!next_.empty()) {
        index = getNext();
        while (((getTop(index) == 'H') || (getTop(index) == 'M')) && (!next_.empty())) {
            index = getNext();
        }
    }
    
    if (next_.empty()) {
        index = rand() % 100;
        while ((getTop(index) == 'H') || (getTop(index) == 'M')) {
            index = rand() % 100;
        }
    }
    
    row = index / 10 + 65;
    col = index % 10 + 48;
    square = target.getBottom(index);
    
    if (square == 'S') {                                                        // Sets result to appropriate character
        result = 'H';
    } else {
        result = 'M';
    }
    
    target.setBottom(index, result);                                            // Sets attacked square to display the result of the attack
    setTop(index, result);
    
    if (result == 'H') {                                                        // If it's a hit,
        if (index == 0) {
            setNext(index + 1);
            setNext(index + 10);
        } else if (index == 9) {
            setNext(index + 10);
            setNext(index - 1);
        } else if (index == 90) {
            setNext(index - 10);
            setNext(index + 1);
        } else if (index == 99) {
            setNext(index - 10);
            setNext(index - 1);
        } else if (index % 10 == 0) {
            setNext(index - 10);
            setNext(index + 1);
            setNext(index + 10);
        } else if (index % 10 == 9) {
            setNext(index - 10);
            setNext(index + 10);
            setNext(index - 1);
        } else if (index < 9) {
            setNext(index + 1);
            setNext(index + 10);
            setNext(index - 1);
        } else if (index > 90) {
            setNext(index - 10);
            setNext(index + 1);
            setNext(index - 1);
        } else {
            setNext(index - 10);
            setNext(index + 1);
            setNext(index + 10);
            setNext(index - 1);
        }
        hits_++;                                                                // Increment computer's hit counter
    }
    
    cout << "The computer attacks " << row << col << "." << endl;               // States which square was attacked
    if (result == 'H') {
        cout << "It's a HIT!";                                                  // Lets player know if it was a hit or a miss
    } else {
        cout << "It's a MISS!";
    }
    cout << endl << endl;                                                       // Whitespace
    
    return;
}


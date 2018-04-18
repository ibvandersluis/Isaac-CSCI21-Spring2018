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

/*  Purpose :   Default constructor
 *  Input   :   None
 *  Output  :   None
 */
Player::Player() {
    hits_ = 0;
}

/*  Purpose :   Default destructor
 *  Input   :   None
 *  Output  :   None
 */
Player::~Player() {
    
}

/*  Purpose :   Prints top_ to screen
 *  Input   :   None
 *  Output  :   None, displays top_ board in ordered rows and columns
 */
void Player::printTop() {
    top_.print();
    
    return;
}

/*  Purpose :   Pushes c onto top_ board
 *  Input   :   1 char
 *  Output  :   None
 */
void Player::setTop(char c) {
    top_.setBoard(c);
    
    return;
}

/*  Purpose :   Sets top_.at(index) to value c
 *  Input   :   1 unsigned int, 1 char
 *  Output  :   None
 */
void Player::setTop(unsigned int index, char c) {
    top_.setBoard(index, c);
    
    return;
}

/*  Purpose :   Prints bottom_ to screen
 *  Input   :   None
 *  Output  :   None, displays bottom_ board in ordered rows and columns
 */
void Player::printBottom() {
    bottom_.print();
    
    return;
}

/*  Purpose :   Pushes c onto bottom_ board
 *  Input   :   1 char
 *  Output  :   None
 */
void Player::setBottom(char c) {
    bottom_.setBoard(c);
    
    return;
}

/*  Purpose :   Sets bottom_.at(index) to value c
 *  Input   :   1 unsigned int, 1 char
 *  Output  :   None
 */
void Player::setBottom(unsigned int index, char c) {
    bottom_.setBoard(index, c);
    
    return;
}

/*  Purpose :   Sets hits_ to value hits
 *  Input   :   1 unsigned int
 *  Output  :   None
 */
void Player::setHits(unsigned int hits) {
    hits_ = hits;
}

/*  Purpose :   Retrieves the vector top_
 *  Input   :   None
 *  Output  :   1 char vector
 */
vector<char> Player::getTop() const {
    return top_.getBoard();
}

/*  Purpose :   Retrieves the value stored in top_.at(index)
 *  Input   :   1 unsigned int
 *  Output  :   1 char
 */
char Player::getTop(unsigned int index) const {
    return top_.getBoard(index);
}

/*  Purpose :   Retrieves the vector bottom_
 *  Input   :   None
 *  Output  :   1 char vector
 */
vector<char> Player::getBottom() const {
    return bottom_.getBoard();
}

/*  Purpose :   Retrieves the value stored in bottom_.at(index)
 *  Input   :   1 unsigned int
 *  Output  :   1 char
 */
char Player::getBottom(unsigned int index) const {
    return bottom_.getBoard(index);
}

/*  Purpose :   Retrieves the value stored in hits_
 *  Input   :   None
 *  Output  :   1 unsigned int
 */
unsigned int Player::getHits() {
    return hits_;
}

/*  Purpose :   Populates the Player's bottom board with the contents of a given
 *              file
 *  Input   :   1 string
 *  Output  :   None
 */
void Player::populateBottom(string filename) {
    bottom_.populate(filename);
    
    return;
}

////////// HUMAN MEMBER FUNCTIONS //////////

/*  Purpose :   Default constructor
 *  Input   :   None
 *  Output  :   None
 */
Human::Human() {
    hits_ = 0;
}

/*  Purpose :   Attacks a specified square on the Computer's board
 *  Input   :   1 unsigned int, 1 Computer object by reference
 *  Output  :   None, states which square was attacked and whether it was a hit
 *              or a miss
 */
void Human::attack(unsigned int index, Computer &target) {
    char square = target.getBottom(index);                                      // Stores the value stored in the square being attacked
    char row = index / 10 + 65;                                                 // Stores the row that was attacked
    char col = index % 10 + 48;                                                 // Stores the column that was attacked
    char result;                                                                // Stores the result of the attack
    
    if ((getTop(index) == 'H') || (getTop(index) == 'M')) {                     // Chides user if square has been attacked before
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
        
        cout << "You attacked " << row << col << "." << endl;                   // States which square was attacked
        
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

/*  Purpose :   Default constructor
 *  Input   :   None
 *  Output  :   None
 */
Computer::Computer() {
    hits_ = 0;
}

/*  Purpose :   Pushed index onto next_ queue
 *  Input   :   1 unsigned int
 *  Output  :   None
 */
void Computer::setNext(unsigned int index) {
    next_.push(index);
    
    return;
}

/*  Purpose :   Retrieves next value stored in next_
 *  Input   :   None
 *  Output  :   1 unsigned int
 */
unsigned int Computer::getNext() {                                              
    unsigned int val = next_.front();                                           // Stores value from next item in queue
    next_.pop();                                                                // Pop queue
    
    return val;                                                                 // Return value
}

/*  Purpose :   Attacks a square on the Human's board, based either on the next_
 *              queue or, if next_ is empty, a random square
 *  Input   :   1 Human object by reference
 *  Output  :   None, states which square was attacked and whether it was a hit
 *              or a miss
 */
void Computer::attack(Human &target) {
    unsigned int index;                                                         // Stores number the square to be attacked
    char row;                                                                   // Stores the row that was attacked
    char col;                                                                   // Stores the column that was attacked
    char square;                                                                // Stores the value stored in the square being attacked
    char result;                                                                // Stores the result of the attack
    
    if (!next_.empty()) {                                                       // If queue isn't empty,
        index = getNext();                                                      // Check to see if next index in queue has already been attacked
        while (((getTop(index) == 'H') || (getTop(index) == 'M')) && (!next_.empty())) {
            index = getNext();                                                  // If it has, get the next index
        }
    }
    
    if (next_.empty()) {                                                        // If queue is empty,
        index = rand() % 100;                                                   // Assign index to a random number 0..99
        while ((getTop(index) == 'H') || (getTop(index) == 'M')) {              // If index has already been attacked,
            index = rand() % 100;                                               // Assign new number
        }
    }
    
    row = index / 10 + 65;                                                      // Calculate row
    col = index % 10 + 48;                                                      // Calculate column
    square = target.getBottom(index);                                           // Retrieves the square from the human's board
    
    if (square == 'S') {                                                        // Sets result to appropriate character
        result = 'H';
    } else {
        result = 'M';
    }
    
    target.setBottom(index, result);                                            // Sets attacked square to display the result of the attack
    setTop(index, result);
    
    if (result == 'H') {                                                        // If it's a hit,
        if (index == 0) {                                                       // Adds appropriate index numbers to queue
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


#include "queue.h"
#include "stack.h"

/*  Project 2C - Tournament Stack and Queue
 *
 *  written by      : Isaac Vander Sluis
 *  completed on    : 5/2/18
 *
 *  This program runs a tournament using either a stack or queue, and prints the
 *  results.
 *  Credit to Chris Eheler for the idea of using a vector of pairs.
 *  Credit to the YouTube channel CSCI 1060U: Programming Workshop I and their
 *  video "Implementing a Stack Class in C++", for helping me understand how to
 *  build my own stack and queue.
 *  Implementation of these ideas is my own.
 */

int main(int argc, char* argv[]) {
    vector<pair <string, unsigned int> > playedgames;                           // Vector of pairs, with usernames and the number of games they played
    Stack<string> stack;                                                        // Declares list as a stack of strings
    Queue<string> queue;                                                        // Declares list as a queue of strings
    ifstream inFS;                                                              // Filestream variable for importing usernames
    string filename;                                                            // Stores name of file to open
    string username;                                                            // Stores current username
    string player1;                                                             // Stores the name of the first player
    string player2;                                                             // Stores the name of the second player
    string winner;                                                              // Stores the name of the match winner
    double total = 0;                                                           // Stroes the total number of games played
    unsigned int numplayers;                                                    // Stores the total number of players in the tournament
    double average;                                                             // Stores the average number of games played
    
    
    
    if (argc != 3) {                                                            // If 3 command line args are not supplied,
        cout << "Usage: ./execute usernamefile listmethod" << endl;             // Prints usage guideline to user
        return 1;
    } else if (argv[2] != string("STACK") && argv[2] != string("QUEUE")) {      // Else, if the third argument is misspelled,
        cout << "argv[2] must be either 'STACK' or 'QUEUE'" << endl;            // Prints usage guideline
        return 1;
    }
    
    filename = argv[1];
    
    inFS.open(filename.c_str());                                                // Opens file
    while (!inFS.is_open()) {                                                   // Prints error if file won't open
        cout << "Could not open file " << filename << endl;
        cout << "Please enter a valid file name: ";                             // Re-prompts user for file
        cin >> filename;
        inFS.open(filename.c_str());
    }
    
    if (argv[2] == string("STACK")) {                                           // If STACK is specified,use stack
        while (!inFS.eof()) {                                                   // While the end of the file hasn't been reached,
            inFS >> username;                                                   // Get username
            stack.push(username);                                               // Push username onto stack
            playedgames.push_back(make_pair(username, 0));                      // Push username as a pair onto vector
        }
        
        while (stack.size() > 1) {                                              // While at least 2 strings are in the stack,
            player1 = stack.pop();                                              // Pop first value and store in player1
            player2 = stack.pop();                                              // Pop second value and store in player2
            if (player1 > player2) {                                            // Determines winner based on ASCII values
                winner = player1;
            } else {
                winner = player2;
            }
            stack.push(winner);                                                 // Pushes the winner back onto the stack
            
            for (unsigned int i = 0; i < playedgames.size(); i++) {             // Increments games played for both players
                if (playedgames[i].first == player1 || playedgames[i].first == player2) {
                    playedgames[i].second++;
                }
            }
                                                                                // Prints result
            cout << player1 << " played " << player2 << ". " << winner << " won!" << endl << endl;
        }
    } else {                                                                    // Else, use queue
        while (!inFS.eof()) {                                                   // While the end of the file hasn't been reached,
            inFS >> username;                                                   // Get username
            queue.push(username);                                               // Push username onto queue
            playedgames.push_back(make_pair(username, 0));                      // Push username as a pair onto vector
        }
        
        while (queue.size() > 1) {                                              // While at least 2 strings are in the queue
            player1 = queue.pop();                                              // Pop first value and store in player1
            player2 = queue.pop();                                              // Pop second value and store in player2
            if (player1 > player2) {                                            // Determines winner based on ASCII value
                winner = player1;
            } else {
                winner = player2;
            }
            queue.push(winner);                                                 // Pushes the winner onto the back of the queue
            
            for (unsigned int i = 0; i < playedgames.size(); i++) {             // Increments games played for both players
                if (playedgames[i].first == player1 || playedgames[i].first == player2) {
                    playedgames[i].second++;
                }
            }
                                                                                // Prints result
            cout << player1 << " played " << player2 << ". " << winner << " won!" << endl << endl;
        }
    }
    
    for (unsigned int i = 0; i < playedgames.size(); i++) {                     // Counts total number of games each player played (which is double the number of games played)
        total += playedgames[i].second;
    }
    
    numplayers = playedgames.size();                                            // Sets numplayers to the size of the vector
    
    average = total / numplayers;                                               // Calculates average games played per player
    
                                                                                // Prints statistics on tournament
    cout << "-------------------------------------------------------------------------" << endl;
    cout << setw(25) << left << "Games played: " << total / 2 << endl << fixed << setprecision(2);
    cout << setw(25) << "Number of players: " << numplayers << endl;
    cout << "Each contestant played an average of " << average << " games." << endl;
    cout << "Thanks to all our competitors for participating:" << endl << endl;
    
    for (unsigned int i = 0; i < playedgames.size(); i++) {                     // Prints the name of each player and the number of games they played
        cout << setw(25) << playedgames[i].first << " -- " << playedgames[i].second;
        if (playedgames[i].second > 1) {
            cout << " games";
        } else {
            cout << " game";
        }
        cout << endl << endl;
    }
                                                                                // Prints the winner of the tournament
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
    cout << "                       " << winner << " IS THE CHAMPION!" << endl << endl;
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    
    return 0;
}
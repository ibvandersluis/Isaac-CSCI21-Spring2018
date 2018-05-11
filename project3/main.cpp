#include "tree.h"

/*  Project 3 - Text Prediction Tree
 *
 *  written by      : Isaac Vander Sluis
 *  completed on    : 5/10/18
 *
 *  This program inserts 1,000 words into a tree, sorted by weight. The user is
 *  then prompted for a prefix. The program prints all words with that prefix,
 *  in descending order of weight.
 *  Credit to Justin Roosenschoon for patiently helping me understand the
 *  confounding recursive functions.
 *  
 */

int main(int argc, char* argv[]) {
    Tree tree;                                                                  // Tree structur for holding words
    ifstream inFS;                                                              // ifstream for importing words
    string filename;                                                            // String for storing filename
    string the_void;                                                            // String for absorbing garbage words
    string word;                                                                // String for holding current word
    unsigned int weight;                                                        // Represents assigned weight of word
    
    if (argc != 2) {                                                            // If incorrect number of arguments given,
        cout << "Usage: ./execute wordfile.txt" << endl;                        // Print usage statement
        
        return 1;
    }
    
    filename = argv[1];                                                         // Assignes file name
    
    inFS.open(filename.c_str());                                                // Opens file
    while (!inFS.is_open()) {                                                   // Prints error if file won't open
        cout << "Could not open file " << filename << endl;
        cout << "Please enter a valid file name: ";                             // Re-prompts user for file
        cin >> filename;
        inFS.open(filename.c_str());
    }
    
    while (!inFS.eof()) {                                                       // While end of file isn't reached,
        inFS >> the_void;                                                       // Get values
        inFS >> word;
        inFS >> weight;
        
        tree.insert(word, weight);                                              // Inserts values into tree
    }
    
    inFS.close();                                                               // Closes file
    
    cout << "Enter a prefix to search for: ";                                   // Prompts user
    cin >> word;                                                                // Gets word
    
    cout << endl << "Words containing the prefix: '" << word << "':" << endl;   // Prints prefixes
    tree.prefixes(word, tree.root());
    
    
    return 0;
}
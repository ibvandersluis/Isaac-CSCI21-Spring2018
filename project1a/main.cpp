/*
 * Project 1A - Luhn's Algorithm
 *
 * Written by           Isaac Vander Sluis
 * Created on           2/1/18
 *
 * The program determines the validity of certain credit card numbers using
 * Luhn's algorithm and the appropriate prefix for that card. The program will
 * take input from a .txt file and read in a series of credit card numbers.
 * The program will output a text file summarizing the cards given, what type
 * they are, and whether they were validated.
 */
 
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ios>
#include <iomanip>
using namespace std;

/*  This function takes a credit card number, duplicates it as a string, and
    uses this information to determine which type of credit card it is. If it
    doesn't fit any of the if statements, returns unknown.
    Input: one integer representing the credit card number
    Output: one string stating the card type or unknown*/
string CardType(int number) {
    string str = static_cast<string>(number);
    if ((str.substr(0, 2) == "34" || str.substr(0, 2) == "37") && (str.size() == 15)) {
        return "AMERICAN EXPRESS";
    } else if ((str.substr(0, 4) == "6011" || ((number / 10000000000) >= 622126 && (number / 10000000000)) <= 622925) || ((number / 10000000000000) >= 644 && (number / 10000000000000) <= 649) || str.substr(0,2 == 65)) && (str.size() == "16")) {
        return "DISCOVER";
    } else if ((number / 100000000000000) >= 51 && (number / 100000000000000) <= 55)) && (str.size() == "16")) {
        return "MASTERCARD";
    } else if ((str.substr(0, 1) == "4" && (str.size() >= 13 && str.size() <= 16) {
        return "VISA";
    } else {
        return "UNKNOWN CARD TYPE";
    }
    
}

/*  This function takes a credit card number, represented as an integer array,
    and runs Luhn's algorithm on it. It returns True if it passes the algorithm,
    and False otherwise.
    Input: one array of type int
    Output: either 'True' or 'False' */
bool PassLuhn(string ccnum) {
    
}

int main() {
    ifstream inFS;
    ofstream outFS;
    //istringstream ccnumSS;
    string ccnum;
    string cctype;
    string filename;
    string validation;
    int numnum;
    
    cout << "Enter file name for import: ";
    cin >> filename;
    
    inFS.open(filename);
    if (!inFS.is_open()) {                              //prints error if file won't open
        cout << "Could not open file " << filename << endl;
        return 1;
    }
    
    outFS.open("validation.txt");
    // outFS << setw(20) << left << "CREDIT CARD NUMBER" << "|";
    // outFS << setw(15) << "TYPE" << "|";
    // outFS << setw(10) << "RESULT" << endl;
    // outFS << setfill('¯') << "                    |               |          " << endl;
    // outFS << setfill(' ');
    
    while (!inFS.eof()) {
        inFS >> ccnum;
        numnum = static_cast<int>(ccnum);
        // SS.clear();
        // SS.str(ccnum);
        outFS << setw(20) << ccnum << "|" << setw(15) << CardType(numnum) << "|" << setw(10) << "//FIXME" << endl;
    }
    
    outFS.close();
    inFS.close();
    
    return 0;
}
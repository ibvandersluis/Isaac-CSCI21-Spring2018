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
#include <vector>
using namespace std;
using std::fixed;
using std::setprecision;
using std::setfill;
using std::setw;

/*  This function takes a credit card number represented as a vector and
    uses this information to determine which type of credit card it is. If it
    doesn't fit any of the if statements, returns unknown.
    Input: one integer vector representing the credit card number
    Output: one string stating the card type or unknown*/
string CardType(vector<int> number) {
    if (number.at(0) == 3 && (number.at(1) == 4 || number.at(1) == 7) && (number.size() == 15)) {
        return "AMERICAN EXPRESS";
    } else if (number.at(0) = 6 && ((number.at(1) == 0 && number.at(2) == 1 && number.at(3) == 1) || (number.at(1) == 2 && number.at(2) == 2) || (number.at(1) == 4 && number.at(2) >= 4 && number.at(2) <= 9) || number.at(1) == 5) && (number.size() == 16)) {
        return "DISCOVER";
    } else if (number.at(0) == 5 && number.at(1) >= 1 && number.at(1) <= 5 && number.size() == 16) {
        return "MASTERCARD";
    } else if (number.at(0) == 4 && number.size() >= 13 && number.size() < 16) {
        return "VISA";
    } else {
        return "UNKNOWN CARD TYPE";
    }
    
}

/*  This function takes a credit card number, represented as an integer array,
    and runs Luhn's algorithm on it. It returns True if it passes the algorithm,
    and False otherwise.
    Input: a vector of type <int> representing the credit card number
    Output: either 'True' or 'False' */
bool PassLuhn(vector<int> number) {
    bool pass = false;                                                          //function will return false unless number passes Luhn's algorithm
    int stopindex;                                                              //determines index value where card prefix stops
    int sum;                                                                    //stores sum of numbers in account number
    int x;                                                                      //stores calculated check digit to check against actual check digit
    int i;                                                                      //initialized for loops
    
                                                                                //if-else tree determines where prefix ends
    if (CardType(number) == "VISA") {
        stopindex == 0;
    } else if (CardType(number) == "AMERICAN EXPRESS" || CardType(number) == "MASTERCARD") {
        stopindex = 1;
    } else if (CardType(number) == "DISCOVER") {
        stopindex = 2;
    }
    
    for (i = number.size() - 2; i > stopindex; i -= 2) {
        number.at(i) *= 2;                                                      //doubles every other number, starting with the first number left of the check digit and excluding the prefix
        if (number.at(i) > 9) {
            number.at(i) -= 9;                                                  //subtracts 9 if doubling results in number greater than 9
        }
    }
    
    sum = 0;                                                                    //for loop calculates what the check digit should be and stores it in x
    for (i = stopindex + 1; i < number.size() - 1; i++) {
        sum += number.at(i);
        sum *= 9;
        x = sum % 10;
    }
                                                                                //if calculated check digit and actual check digit are the same value, passes Luhn's algorithm
    if (x == number.at(number.size() - 1)) {
        pass = true;
    }
    
    return pass;
}

/*  This function returns turns a integer vector into a single number
    represented as a string.
    Input: one integer vector representing a credit card number
    Output: one string of numbers, also representing a credit card number*/
string WholeNum(vector<int> number) {
    stringstream whole;
    for (int i = 0; i < number.size() - 1; i++) {
        whole << number.at(i);
    }
    return whole.str();
}

int main() {
    ifstream        inFS;
    ofstream        outFS;
    stringstream    ccnumSS;
    string          ccnum;
    string          cctype;
    string          filename;
    string          validation;
    int             count = 0;
    char            digit;
    vector<int>     cardnum;
    
    cout << "Enter file name for import: ";                                     //prompts user for import file
    cin >> filename;
    
    inFS.open(filename);                                                        //opens the file specified by user
    if (!inFS.is_open()) {                                                      //prints error if file won't open
        cout << "Could not open file " << filename << endl;
        return 1;
    }
    
    outFS.open("validation.txt");                                               //opens output file and sets up organized table of results
    outFS << setw(20) << left << "CREDIT CARD NUMBER" << "|";
    outFS << setw(15) << "TYPE" << "|";
    outFS << setw(10) << "RESULT" << endl;
    outFS << setfill('¯') << "                    |               |          " << endl;
    outFS << setfill(' ');
    
    while (!inFS.eof()) {                                                       //stores all credit card numbers in a stringstream separated by spaces
        inFS >> ccnum;
        ccnumSS << ccnum << " ";
        count++;
    }
    
    for (int i = 0; i < count; i++) {                                           //for loop is repeated as many times as there are credit card numbers
        int size;                                                               //variable for clearing the cardnum vector later
        ccnumSS >> digit;                                                       //reads in one digit from the stringstream
        while (digit != ' ') {                                                  //so long as digit isn't a space,
            cardnum.push_back(digit - 48);                                      //pushes digit - 48 (for ascii difference) onto vector
            ccnumSS >> digit;                                                   //gets next digit
        }
        
        int size = cardnum.size();                                              //sets size to the size of the vector
        
        outFS << setw(20) << WholeNum(cardnum) << "|" << setw(15) << CardType(cardnum) << "|" << setw(10) << PassLuhn(cardnum) << endl;
        
        for (i = 0; i < size; i++) {                                            //clears all elements from the vector
            cardnum.pop_back();
        }
    }
    
    
    outFS.close();                                                              //closes files
    inFS.close();
    
    return 0;
}
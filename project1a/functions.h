/*
 *  Project 1A - Luhn's Algorithm
 *
 *  Written by           Isaac Vander Sluis
 *  Created on           2/1/18
 *
 *  The program determines the validity of certain credit card numbers using
 *  Luhn's algorithm and the appropriate prefix for that card. The program will
 *  take input from a .txt file and read in a series of credit card numbers.
 *  The program will output a text file summarizing the cards given, what type
 *  they are, and whether they were validated.
 */

#ifndef functions_h
#define functions_h
 
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
using std::basic_ifstream;

string CardType(vector<int> number);
/*  This function takes a credit card number represented as a vector and
    uses this information to determine which type of credit card it is. If it
    doesn't fit any of the if statements, returns unknown.
    Input: one integer vector representing the credit card number
    Output: one string stating the card type or unknown */
    
string PassLuhn(vector<int> number);
/*  This function takes a credit card number, represented as an integer array,
    and runs Luhn's algorithm on it. It returns True if it passes the algorithm,
    and False otherwise.
    Input: a vector of type <int> representing the credit card number
    Output: either 'True' or 'False' */
    
string WholeNum(vector<int> number);
/*  This function returns turns a integer vector into a single number
    represented as a string.
    Input: one integer vector representing a credit card number
    Output: one string of numbers, also representing a credit card number */
    
#endif
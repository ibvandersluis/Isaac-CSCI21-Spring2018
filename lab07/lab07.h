/*
 * Name        : lab07.h
 * Author      : Luke Sathrum
 * Description : Header File for Lab #7. DO NOT ALTER!
 */

#ifndef LAB07_H
#define LAB07_H

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cstring>
using std::cout;
using std::ifstream;
using std::endl;
using std::string;
using std::map;
using std::stringstream;



/*
 * Open and read the contents of a text file. Each line of the
 * file will contain a single integer of possible values 10, 20,
 * 30, 40, or 50. Perform the following operations on the input values:
 *   10 -- invoke the function OnTen
 *   20 -- invoke the function OnTwenty
 *   30 -- invoke the function OnThirty
 *   40 -- invoke the function OnForty
 *   50 -- invoke the function OnFifty
 *   any other value -- invoke the function OnError
 * DON'T FORGET TO CLOSE YOUR FILE BEFORE YOUR FUNCTION ENDS!!!
 * @param string filename - A string containing the name of the file to
 *                          be processed
 * @return bool - True if filename was successfully opened and processed,
 *                else false
 */
bool ProcessFile(string filename);
void ProcessArguments(int argc, char* argv[]);

// For testing (DO NOT ALTER)
extern map<int, int> counters;
extern char* global_argv[8];
extern int global_argc;
bool CheckArgs(int argc, char* const argv[]);
void OnTen();
void OnTwenty();
void OnThirty();
void OnForty();
void OnFifty();
void OnError();



#endif
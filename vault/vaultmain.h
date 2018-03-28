//Created By: Isaac Vander Sluis
//Created On: 12/7/17

/*

~~~~~~~~PASSVAULT~~~~~~~~
This program...

*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "vaultclass.h"

//////~~PROGRAM FUNCTIONS~~//////
string MakeLower(string str);
void VaultOut();
void Save();
void Import();


//////~~GLOBAL VARIABLES~~//////
Vault vault1;                   //declares vault object. Make new each time?
ifstream input;                 //declares variable for input from a save file
ofstream output;                //declares variable for output to populate a file with user's data
ofstream save;                  //declares variable for output to save file
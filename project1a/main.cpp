#include "functions.h"

int main() {
    ifstream        inFS;                                                       //input filestream variable for importing CC numbers
    ofstream        outFS;                                                      //output filestream variable for exporting results
    stringstream    ccnumSS;                                                    //stringstream variable for storing imported CC numbers
    string          ccnum;                                                      //string for importing CC numbers to stringstream
    string          filename;                                                   //string for storing name of file for import
    string          validation;                                                 //string for storing whether CC number was validated
    int             count = 0;                                                  //int variable for counting number of CC numbers
    char            digit;                                                      //char variable for separating CC numbers into digits
    vector<int>     cardnum;                                                    //int vector for storing whole CC numbers separated into digits
    
    cout << "Enter file name for import: ";                                     //prompts user for import file
    cin >> filename;
    
    inFS.open(filename.c_str());                                                //opens the file specified by user
    if (!inFS.is_open()) {                                                      //prints error if file won't open
        cout << "Could not open file " << filename << endl;
        return 1;
    }
    
    outFS.open("validation.txt");                                               //opens output file and sets up organized table of results
    outFS << setw(20) << left << "CREDIT CARD NUMBER" << "|";
    outFS << setw(20) << "TYPE" << "|";
    outFS << setw(20) << "RESULT" << endl;
    outFS << setfill('-') << right << setw(21) << "|" << setw(21) << "|" << setw(21) << " " << endl;
    outFS << setfill(' ') << left;
    
    while (!inFS.eof()) {                                                       //stores all credit card numbers in a stringstream separated by spaces
        getline(inFS, ccnum);
        ccnumSS << ccnum << " ";
        count++;
    }
    
    for (int i = 0; i < count; i++) {                                           //for loop is repeated as many times as there are credit card numbers
        int size;                                                               //variable for clearing the cardnum vector later
        if (isspace(ccnumSS.peek())) {                                          //if next char in stringstream is space, ignore it
            ccnumSS.ignore(1);
        }
        
        while (!isspace(ccnumSS.peek())){                                       //so long as digit isn't a space,
            ccnumSS >> digit;               
            //reads in one digit from the stringstream
            cardnum.push_back(digit - 48);                                      //pushes digit - 48 (for ascii difference) onto vector
        }
        
        size = cardnum.size();                                                  //sets size to the size of the vector
        
                                                                                //prints card number, type, and Luhn's result to output file
        outFS << setw(20) << WholeNum(cardnum) << "|" << setw(20) << CardType(cardnum) << "|" << setw(21) << PassLuhn(cardnum) << endl;
        
        cardnum.erase(cardnum.begin(), cardnum.end());                          //erases all elements of the vector cardnum
    }
    
    
    outFS.close();                                                              //closes files 
    inFS.close();
    
    return 0;
}
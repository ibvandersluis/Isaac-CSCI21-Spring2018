#include "creditcard.h"

int main() {
    ifstream                inFS;                                               //ifstream var for opening input file and reading data from it
    ofstream                outFS;                                              //ofstream var for opening output file and sending results to it
    string                  filename;                                           //string var for storing import file name
    string                  cardnum;                                            //string var for storing card number
    string                  firstname;                                          //string var for storing card holder's first name
    string                  lastname;                                           //string var for storing card holder's last name
    string                  cardtype;                                           //string var for storing card's type (Gold/Platinum/Corporate)
    double                  balance;                                            //double var for storing card's current balance
    double                  creditlim;                                          //double var for storing card's credit limit
    double                  overdraft;                                          //double var for storing overdraft limit
    stringstream            SS;                                                 //stringstream for breaking down a cardnumber into digits for Luhn's
    vector<GoldCard>        goldcards;                                          //vector for storing GoldCard objects
    vector<PlatinumCard>    platinumcards;                                      //vector for storing PlatinumCard objects
    vector<CorporateCard>   corporatecards;                                     //vector for storing CorporateCard objects
    
    cout << "Enter file name to import credit card info: ";                     //prompt user for first file to import
    cin >> filename;                                                            //get filename
    
    inFS.open(filename.c_str());                                                //opens specified file
    if (!inFS.is_open()) {                                                      //prints error if file won't open
        cout << "Could not open file " << filename << endl;
        return 1;
    }
    
    while (!inFS.eof()) {
        inFS >> cardnum;
        inFS >> firstname;
        inFS >> lastname;
        inFS >> cardtype;
        inFS >> balance;
    }
    
    return 0;
}
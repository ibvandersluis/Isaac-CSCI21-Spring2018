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
    int                     goldcount = 0;                                      //int for counting number of objects to store in goldcards vector
    int                     platcount = 0;                                      //int for counting number of objects to store in platinumcards vector
    int                     corpcount = 0;                                      //int for counting number of objects to store in corporatecards vector
    string                  the_void;                                           //char variable for sucking up filler and ejecting it into space
    
    cout << "Enter file name to import credit card info: ";                     //prompt user for first file to import
    cin >> filename;                                                            //get filename
    
    inFS.open(filename.c_str());                                                //opens specified file
    if (!inFS.is_open()) {                                                      //prints error if file won't open
        cout << "Could not open file " << filename << endl;
        return 1;
    }
    
    while (!inFS.eof()) {                                                       //iterates through file and counts number of gold, platinum, and corporate cards
        inFS >> cardnum;
        inFS >> firstname;
        inFS >> lastname;
        inFS >> cardtype;
        inFS >> the_void;
        inFS >> balance;
        
        if (cardtype == "Gold" || cardtype == "gold") {
            goldcount++;
            goldcards.resize(goldcount, GoldCard card(cardnum, firstname, lastname, balance));
        } else if (cardtype == "Platinum" || cardtype == "platinum") {
            platcount++;
            platinumcards.resize(platcount, PlatinumCard card(cardnum, firstname, lastname, balance));
        } else if (cardtype == "Corporate" || cardtype == "corporate") {
            corpcount++;
            corporatecards.resize(corpcount, CorporateCard card(cardnum, firstname, lastname, balance));
        }
    }
    
    inFS.close();
    
    //////////////FINAL LINES -- PUSH TO END///////////////
    inFS.close();
    outFS.close();
    
    return 0;
}
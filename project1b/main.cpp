#include "creditcard.h"

int main() {
    ifstream                inFS;                                               //ifstream var for opening input file and reading data from it
    ofstream                outFS;                                              //ofstream var for opening output file and sending results to it
    string                  filename;                                           //string var for storing import file name
    string                  cardnum;                                            //string var for storing card number
    string                  firstname;                                          //string var for storing card holder's first name
    string                  lastname;                                           //string var for storing card holder's last name
    string                  cardtype;                                           //string var for storing card's type (Gold/Platinum/Corporate)
    string                  transaction;                                        //string var for storing transaction line
    string                  reason;                                             //string var for storing reason a card is declined
    double                  balance;                                            //double var for storing card's current balance
    double                  creditlim;                                          //double var for storing card's credit limit
    double                  overdraft;                                          //double var for storing overdraft limit
    double                  rebate;                                             //double var for storing rebate percentage
    double                  amount;                                             //double var for storing transaction amount
    double                  total = 0.00;                                       //double var for storing cardholder's monthly total
    stringstream            SS;                                                 //stringstream for breaking down a cardnumber into digits for Luhn's
    vector<GoldCard>        goldcards;                                          //vector for storing GoldCard objects
    vector<PlatinumCard>    platinumcards;                                      //vector for storing PlatinumCard objects
    vector<CorporateCard>   corporatecards;                                     //vector for storing CorporateCard objects
    vector<Transaction>     transactionlist;                                    //vector for storing Transaction objects
    int                     goldcount = 0;                                      //int for counting number of objects to store in goldcards vector
    int                     platcount = 0;                                      //int for counting number of objects to store in platinumcards vector
    int                     corpcount = 0;                                      //int for counting number of objects to store in corporatecards vector
    int                     trancount = 0;                                      //int for counting number of transactions being read in
    string                  the_void;                                           //char variable for sucking up filler and ejecting it into space
    string                  date;                                               //string var for storing transaction date
    string                  vendor;                                             //string var for storing transaction vendor
    bool                    found = false;                                      //boolean for whether or not a card has been found in the system
    bool                    no_decline = false;                                 //boolean that is false unless no transactions were declined
    
    cout << "Enter file name to import credit card info: ";                     //prompt user for first file to import
    cin >> filename;                                                            //get filename
    
    inFS.open(filename.c_str());                                                //opens specified file
    if (!inFS.is_open()) {                                                      //prints error if file won't open
        cout << "Could not open file " << filename << endl;
        return 1;
    }
    
    while (!inFS.eof()) {                                                       //iterates through file and gets account info to put in object
        inFS >> cardnum;
        inFS >> firstname;
        inFS >> lastname;
        inFS >> cardtype;
        inFS >> the_void;
        inFS >> balance;
        
        if (cardtype == "Gold" || cardtype == "gold") {                         //determines which vector to use based on cardtype
            goldcount++;                                                        //then resizes vector and adds an object with the given info to it
            goldcards.resize(goldcount, GoldCard(cardnum, firstname, lastname, balance));
        } else if (cardtype == "Platinum" || cardtype == "platinum") {
            platcount++;
            platinumcards.resize(platcount, PlatinumCard(cardnum, firstname, lastname, balance));
        } else if (cardtype == "Corporate" || cardtype == "corporate") {
            corpcount++;
            corporatecards.resize(corpcount, CorporateCard(cardnum, firstname, lastname, balance));
        }
    }
    
    inFS.close();                                                               //closes inFS
    
    cout << "Enter file name to import transactions: ";                         //prompt user for first file to import
    cin >> filename;                                                            //get filename
    
    inFS.open(filename.c_str());                                                //opens specified file
    if (!inFS.is_open()) {                                                      //prints error if file won't open
        cout << "Could not open file " << filename << endl;
        return 1;
    }
    
    while (!inFS.eof()) {                                                       //gets each transaction line and shoves it ruedly into a stringstream variable with spaces in between
        getline(inFS, transaction);
        SS << transaction << " ";
        trancount++;
    }
    
    inFS.close();                                                               //closes inFS
    
    transaction = SS.str();                                                     //assigns transaction to the string stored in stringstream
    SS.str("");                                                                 //clears SS
    replace(transaction.begin(), transaction.end(), ':', ' ');                  //replaces every colon with a space in transaction
    transaction.pop_back();                                                     //removes last character of string (a space)
    SS << transaction;                                                          //shoves transaction rudely back into a stringstream variable
    
    for (int j = 0; j < trancount; j++) {
        found = false;                                                          //resets found to talse
        SS >> cardnum;
        SS >> date;
        SS >> transaction;
        SS >> vendor;
        SS >> amount;
        
        while (found == false) {                                                //iterates through each vector searching for account info until it is found
            for (int i = 0; i < goldcards.size(); i++) {
                if (goldcards.at(i).GetCardnum() == cardnum) {
                    found = true;
                    firstname = goldcards.at(i).GetFirstname();
                    lastname = goldcards.at(i).GetLastname();
                    cardtype = goldcards.at(i).GetCardtype();
                    balance = goldcards.at(i).GetBalance();
                    creditlim = goldcards.at(i).GetCreditlim();
                    overdraft = goldcards.at(i).GetOverdraft();
                    rebate = goldcards.at(i).GetRebate();
                }
            }
            for (int i = 0; i < platinumcards.size(); i++) {
                if (platinumcards.at(i).GetCardnum() == cardnum) {
                    found = true;
                    firstname = platinumcards.at(i).GetFirstname();
                    lastname = platinumcards.at(i).GetLastname();
                    cardtype = platinumcards.at(i).GetCardtype();
                    balance = platinumcards.at(i).GetBalance();
                    creditlim = platinumcards.at(i).GetCreditlim();
                    overdraft = platinumcards.at(i).GetOverdraft();
                    rebate = platinumcards.at(i).GetRebate();
                }
            }
            for (int i = 0; i < corporatecards.size(); i++) {
                if (corporatecards.at(i).GetCardnum() == cardnum) {
                    found = true;
                    firstname = corporatecards.at(i).GetFirstname();
                    lastname = corporatecards.at(i).GetLastname();
                    cardtype = corporatecards.at(i).GetCardtype();
                    balance = corporatecards.at(i).GetBalance();
                    creditlim = corporatecards.at(i).GetCreditlim();
                    overdraft = corporatecards.at(i).GetOverdraft();
                    rebate = corporatecards.at(i).GetRebate();
                }
            }
        }
        transactionlist.push_back(Transaction(cardnum, firstname, lastname, cardtype, balance, creditlim, overdraft, rebate, date, transaction, vendor, amount));
    }
    
    outFS.open("report.txt");
    
    outFS << "*****************************************************************" << endl;
    outFS << "                      DECLINED TRANSACTIONS" << endl;
    outFS << "*****************************************************************" << endl;
    
    for (int i = 0; i < transactionlist.size(); i++) {
        if (transactionlist.at(i).PassLuhn() == false) {
            transactionlist.at(i).SetEval(true);
            reason = "FAILED LUHN'S";
            outFS << "TRANSACTION #: " << transactionlist.at(i).GetTransaction() << "   REASON: " << reason << endl;
        } else if (transactionlist.at(i).GetBalance() + transactionlist.at(i).GetAmount() >= transactionlist.at(i).GetCreditlim() + transactionlist.at(i).GetOverdraft()) {
            transactionlist.at(i).SetEval(true);
            reason = "FUNDS UNAVAILABLE";
            outFS << "TRANSACTION #: " << transactionlist.at(i).GetTransaction() << "   REASON: " << reason << endl;
        }
    }
    
    for (int i = 0; (i < transactionlist.size() && no_decline == false); i++) {
        if (transactionlist.at(i).GetEval == true) {
            no_decline == true;
        }
    }
    
    if (no_decline == true) {
        outFS << "NO TRANSACTIONS WERE DECLINED" << endl;
    }
    
    outFS << endl << endl;
    outFS << "*****************************************************************" << endl;
    outFS << "                      APPROVED TRANSACTIONS" << endl;
    outFS << "*****************************************************************" << endl;
    
    for (int i = 0; i < transactionlist.size(); i++) {
        if (transactionlist.at(i).GetEval() == false) {
            total = 0.00;
            cardnum = transactionlist.at(i).GetCardnum();
            outFS << "-----CARD #: " << cardnum << "-----" << endl;
            outFS << "CARDHOLDER: " << transactionlist.at(i).GetLastname() << ", " << transactionlist.at(i).GetFirstname();
            outFS << "TRANSACTIONS: " << endl;
            for (int i = 0; i < transactionlist.size(); i++) {
                if (cardnum == transactionlist.at(i).GetCardnum() && transactionlist.at(i).GetEval() == false) {
                    transactionlist.at(i).SetEval(true);
                    outFS << "    Transaction: " << transactionlist.at(i).GetTransaction() << ", Vendor: " << transactionlist.at(i).GetVendor() << ", Amount: " << transactionlist.at(i).GetAmount << endl;
                    total += transactionlist.at(i).GetAmount;
                }
            }
            outFS << "TOTAL SPENT: $" << total << endl;
            outFS << "CURRENT BALANCE: $" << transactionlist.at(i).GetBalance() + total << endl;
            outFS << "REBATE FOR THIS MONTH: $" << total * transactionlist.at(i).GetRebate() << endl;
            if ((transactionlist.at(i).GetBalance() + total) > transactionlist.at(i).GetCreditlim()) {
                outFS << "      !!! WARNING !!!" << endl
                outFS << "YOUR ACCOUNT IS OVERDRAFTED" << endl;
            }
        }
    }
    
    outFS.close();
    
    return 0;
}

/* 

TEST CODE -- USED AND COMMENTED OUT
cout << endl << "######## GOLDCARDS VECTOR ########" << endl;
cout << "SIZE: " << goldcards.size() << endl;
cout << "ELEMENTS:" << endl;

for (int i = 0; i < goldcards.size(); i++) {
    cout << "--------ELEMENT " << i + 1 << "--------" << endl;
    cout << "Card #: " << goldcards.at(i).GetCardnum() << endl;
    cout << "First Name: " << goldcards.at(i).GetFirstname() << endl;
    cout << "Last Name: " << goldcards.at(i).GetLastname() << endl;
    cout << "Card Type: " << goldcards.at(i).GetCardtype() << endl;
    cout << "Current Balance: " << goldcards.at(i).GetBalance() << endl;
    cout << "Credit Limit: " << goldcards.at(i).GetCreditlim() << endl;
    cout << "Overdraft Amount: " << goldcards.at(i).GetOverdraft() << endl;
    cout << "Rebate: " << goldcards.at(i).GetRebate() * 100 << "%" << endl;
}

cout << endl << "######## PLATINUMCARDS VECTOR ########" << endl;
cout << "SIZE: " << platinumcards.size() << endl;
cout << "ELEMENTS:" << endl;

for (int i = 0; i < platinumcards.size(); i++) {
    cout << "--------ELEMENT " << i + 1 << "--------" << endl;
    cout << "Card #: " << platinumcards.at(i).GetCardnum() << endl;
    cout << "First Name: " << platinumcards.at(i).GetFirstname() << endl;
    cout << "Last Name: " << platinumcards.at(i).GetLastname() << endl;
    cout << "Card Type: " << platinumcards.at(i).GetCardtype() << endl;
    cout << "Current Balance: " << platinumcards.at(i).GetBalance() << endl;
    cout << "Credit Limit: " << platinumcards.at(i).GetCreditlim() << endl;
    cout << "Overdraft Amount: " << platinumcards.at(i).GetOverdraft() << endl;
    cout << "Rebate: " << platinumcards.at(i).GetRebate() * 100 << "%" << endl;
}

cout << endl << "######## CORPORATECARDS VECTOR ########" << endl;
cout << "SIZE: " << corporatecards.size() << endl;
cout << "ELEMENTS:" << endl;

for (int i = 0; i < corporatecards.size(); i++) {
    cout << "--------ELEMENT " << i + 1 << "--------" << endl;
    cout << "Card #: " << corporatecards.at(i).GetCardnum() << endl;
    cout << "First Name: " << corporatecards.at(i).GetFirstname() << endl;
    cout << "Last Name: " << corporatecards.at(i).GetLastname() << endl;
    cout << "Card Type: " << corporatecards.at(i).GetCardtype() << endl;
    cout << "Current Balance: " << corporatecards.at(i).GetBalance() << endl;
    cout << "Credit Limit: " << corporatecards.at(i).GetCreditlim() << endl;
    cout << "Overdraft Amount: " << corporatecards.at(i).GetOverdraft() << endl;
    cout << "Rebate: " << corporatecards.at(i).GetRebate() * 100 << "%" << endl;
}

for (int i = 0; i < transactionlist.size(); i++) {
        cout << "--------ELEMENT " << i + 1 << "--------" << endl;
        cout << "Card #: " << transactionlist.at(i).GetCardnum() << endl;
        cout << "First Name: " << transactionlist.at(i).GetFirstname() << endl;
        cout << "Last Name: " << transactionlist.at(i).GetLastname() << endl;
        cout << "Card Type: " << transactionlist.at(i).GetCardtype() << endl;
        cout << "Current Balance: " << transactionlist.at(i).GetBalance() << endl;
        cout << "Credit Limit: " << transactionlist.at(i).GetCreditlim() << endl;
        cout << "Overdraft Amount: " << transactionlist.at(i).GetOverdraft() << endl;
        cout << "Rebate: " << transactionlist.at(i).GetRebate() * 100 << "%" << endl;
        cout << "Date: " << transactionlist.at(i).GetDate() << endl;
        cout << "Transaction #: " << transactionlist.at(i).GetTransaction() << endl;
        cout << "Vendor: " << transactionlist.at(i).GetVendor() << endl;
        cout << "Amount: " << transactionlist.at(i).GetAmount() << endl;
    }
    
*/
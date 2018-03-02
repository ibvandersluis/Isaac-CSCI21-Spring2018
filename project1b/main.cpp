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
    bool                    no_decline = true;                                  //boolean that is false unless no transactions were declined
    
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
    
    outFS.open("report.txt");                                                   //opens file to output report data
    
                                                                                //declined transactions header
    outFS << "*****************************************************************" << endl;
    outFS << "*                     DECLINED TRANSACTIONS                     *" << endl;
    outFS << "*****************************************************************" << endl;
    
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
            for (unsigned int i = 0; i < goldcards.size(); i++) {
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
            for (unsigned int i = 0; i < platinumcards.size(); i++) {
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
            for (unsigned int i = 0; i < corporatecards.size(); i++) {
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
            if (found == false) {
                outFS << endl << "CARD #" << cardnum << " DECLINED" << endl;    //lists card number under declined transactions
                outFS << "                          REASON: NOT IN SYSTEM" << endl;
                found = true;
            }
        }                                                                       //appends Transaction object populated with appropriate data to transactionlist vector
        transactionlist.push_back(Transaction(cardnum, firstname, lastname, cardtype, balance, creditlim, overdraft, rebate, date, transaction, vendor, amount));
    }
    
    for (unsigned int i = 0; i < transactionlist.size(); i++) {                          //iterates through transactions
        
        if (transactionlist.at(i).PassLuhn() == false) {                        //if cardnum_ fails Luhn's,
            transactionlist.at(i).SetEval(true);
            reason = "FAILED LUHN'S";                                           //card is declined for stated reason
            outFS << endl << "TRANSACTION #" << transactionlist.at(i).GetTransaction() << ", DATE: " << transactionlist.at(i).GetDate() << ", VENDOR: " << transactionlist.at(i).GetVendor() << ", AMOUNTt: $" << transactionlist.at(i).GetAmount() << endl;
            outFS << "                          REASON: " << reason << endl;
        } else if (transactionlist.at(i).GetBalance() + transactionlist.at(i).GetAmount() >= transactionlist.at(i).GetCreditlim() + transactionlist.at(i).GetOverdraft()) {
            transactionlist.at(i).SetEval(true);                                //if amount exceeds overdraft allowance,
            reason = "FUNDS UNAVAILABLE";                                       //card is declined for stated reason
            outFS << endl << "TRANSACTION #" << transactionlist.at(i).GetTransaction() << ", DATE: " << transactionlist.at(i).GetDate() << ", VENDOR: " << transactionlist.at(i).GetVendor() << ", AMOUNTt: $" << transactionlist.at(i).GetAmount() << endl;
            outFS << "                          REASON: " << reason << endl;
        }
    }
    
    for (unsigned int i = 0; (i < transactionlist.size() && no_decline == true); i++) {  //iterates through transaction
        if (transactionlist.at(i).GetEval() == true) {                          //if any transaction have been evaluated
            no_decline = false;                                                 //sets no_decline to false
        }
    }
    
    if (no_decline == true) {                                                   //if no transactions were declined,
        outFS << "NO TRANSACTIONS WERE DECLINED" << endl;                       //prints statement
    }
    
    outFS << endl << endl;                                                      //approved transactions header
    outFS << "*****************************************************************" << endl;
    outFS << "*                     APPROVED TRANSACTIONS                     *" << endl;
    outFS << "*****************************************************************" << endl;
    outFS << fixed << setprecision(2);                                          //limits decimal to two digits
    
    for (unsigned int i = 0; i < transactionlist.size(); i++) {                          //iterates through transactions
        if (transactionlist.at(i).GetEval() == false) {                         //only checks unevaluated transactions
            total = 0.00;                                                       //resets total to 0.00
            cardnum = transactionlist.at(i).GetCardnum();                       //assigns cardnum to object's cardnum_ member variable
            outFS << endl << "-----CARD #: " << cardnum << "-----" << endl;             //prints information
            outFS << "CARDHOLDER: " << transactionlist.at(i).GetLastname() << ", " << transactionlist.at(i).GetFirstname() << endl;
            outFS << "TRANSACTIONS: " << endl;
            for (unsigned int i = 0; i < transactionlist.size(); i++) {                  //prints each approved transaction associated with the cardnumber
                if (cardnum == transactionlist.at(i).GetCardnum() && transactionlist.at(i).GetEval() == false) {
                    transactionlist.at(i).SetEval(true);                        //marks each transaction as evaluated
                    outFS << "    Transaction #" << transactionlist.at(i).GetTransaction() << ", Date: " << transactionlist.at(i).GetDate() << ", Vendor: " << transactionlist.at(i).GetVendor() << ", Amount: $" << transactionlist.at(i).GetAmount() << endl;
                    total += transactionlist.at(i).GetAmount();
                }
            }
            outFS << "TOTAL SPENT: $" << total << endl;
            outFS << "CURRENT BALANCE: $" << transactionlist.at(i).GetBalance() + total << endl;
            outFS << "REBATE FOR THIS MONTH: $" << total * transactionlist.at(i).GetRebate() << endl;
            if ((transactionlist.at(i).GetBalance() + total) > transactionlist.at(i).GetCreditlim()) {
                outFS << "      !!! WARNING !!!" << endl;                       //prints warning if account has been overdrafted
                outFS << "YOUR ACCOUNT IS OVERDRAFTED" << endl;
            }
        }
    }
    
    outFS.close();
    
    return 0;
}

/* 

SAMPLE OUTPUT (from report.txt)
*****************************************************************
*                     DECLINED TRANSACTIONS                     *
*****************************************************************

CARD #340000000000009 DECLINED
                          REASON: NOT IN SYSTEM

CARD #4222222422222 DECLINED
                          REASON: NOT IN SYSTEM

TRANSACTION #58774546462, DATE: 10/31/2017, VENDOR: Costumes-R-Us, AMOUNTt: $19.99
                          REASON: FUNDS UNAVAILABLE

TRANSACTION #842554648, DATE: 09/08/2017, VENDOR: Build.com, AMOUNTt: $28.72
                          REASON: FAILED LUHN'S

TRANSACTION #420420420420, DATE: 04/20/2017, VENDOR: DopestGrass, AMOUNTt: $420.42
                          REASON: FUNDS UNAVAILABLE

TRANSACTION #846351545, DATE: 2/26/2018, VENDOR: WinCo, AMOUNTt: $17.38
                          REASON: FAILED LUHN'S

TRANSACTION #6247863791, DATE: 07/04/2017, VENDOR: Fireworks.com, AMOUNTt: $256.84
                          REASON: FUNDS UNAVAILABLE


*****************************************************************
*                     APPROVED TRANSACTIONS                     *
*****************************************************************

-----CARD #: 378282246310005-----
CARDHOLDER: Degrasse-Tyson, Neil
TRANSACTIONS: 
    Transaction #52486122, Date: 03/14/2017, Vendor: Target, Amount: $13.45
TOTAL SPENT: $13.45
CURRENT BALANCE: $2513.45
REBATE FOR THIS MONTH: $0.13

-----CARD #: 378734493671000-----
CARDHOLDER: Lynch, Scott
TRANSACTIONS: 
    Transaction #3177924, Date: 01/03/2018, Vendor: WalMart, Amount: $23.97
    Transaction #327546812, Date: 07/24/2017, Vendor: Expedia.com, Amount: $1354.85
TOTAL SPENT: $1378.82
CURRENT BALANCE: $4378.82
REBATE FOR THIS MONTH: $27.58

-----CARD #: 6011111111111117-----
CARDHOLDER: B'Ardugo, Leigh
TRANSACTIONS: 
    Transaction #9751369974, Date: 06/05/2017, Vendor: REI, Amount: $259.47
    Transaction #5462846879, Date: 11/13/2017, Vendor: GetRichQuick, Amount: $99.99
TOTAL SPENT: $359.46
CURRENT BALANCE: $4859.46
REBATE FOR THIS MONTH: $7.19

-----CARD #: 340000000000009-----
CARDHOLDER: B'Ardugo, Leigh
TRANSACTIONS: 
    Transaction #4258545512, Date: 11/16/2017, Vendor: Codecademy.com, Amount: $19.99
TOTAL SPENT: $19.99
CURRENT BALANCE: $4519.99
REBATE FOR THIS MONTH: $0.40

-----CARD #: 4111111111111111-----
CARDHOLDER: Cline, Ernest
TRANSACTIONS: 
    Transaction #82468413, Date: 02/13/2018, Vendor: Flowers4Her.com, Amount: $14.25
    Transaction #6182444792, Date: 08/15/2017, Vendor: WalMart, Amount: $45.36
TOTAL SPENT: $59.61
CURRENT BALANCE: $4059.61
REBATE FOR THIS MONTH: $1.19

-----CARD #: 5105105105105100-----
CARDHOLDER: Musk, Elon
TRANSACTIONS: 
    Transaction #1234567890, Date: 01/23/2018, Vendor: TotallyLegitNotAScam, Amount: $1549.75
TOTAL SPENT: $1549.75
CURRENT BALANCE: $10549.75
REBATE FOR THIS MONTH: $77.49
      !!! WARNING !!!
YOUR ACCOUNT IS OVERDRAFTED

-----CARD #: 4012888888881881-----
CARDHOLDER: Noah, Trevor
TRANSACTIONS: 
    Transaction #1826482, Date: 09/20/2017, Vendor: Patreon, Amount: $75.00
    Transaction #8438167796, Date: 05/04/2017, Vendor: GoFundMe, Amount: $50.00
TOTAL SPENT: $125.00
CURRENT BALANCE: $3625.00
REBATE FOR THIS MONTH: $2.50

-----CARD #: 4222222222222-----
CARDHOLDER: Martin, George
TRANSACTIONS: 
    Transaction #462284938, Date: 10/07/2017, Vendor: iTunes, Amount: $11.99
TOTAL SPENT: $11.99
CURRENT BALANCE: $2811.99
REBATE FOR THIS MONTH: $0.12

-----CARD #: 6011000990139424-----
CARDHOLDER: Darwin, Charles
TRANSACTIONS: 
    Transaction #846214894, Date: 08/01/2017, Vendor: TacoBell, Amount: $14.85
    Transaction #634477415, Date: 11/24/2017, Vendor: TurkeyTime, Amount: $84.62
TOTAL SPENT: $99.47
CURRENT BALANCE: $11099.47
REBATE FOR THIS MONTH: $4.97
      !!! WARNING !!!
YOUR ACCOUNT IS OVERDRAFTED

-----CARD #: 5555555555554444-----
CARDHOLDER: Hawking, Stephen
TRANSACTIONS: 
    Transaction #47125236, Date: 12/23/2017, Vendor: NorthPole, Amount: $9.56
TOTAL SPENT: $9.56
CURRENT BALANCE: $8509.56
REBATE FOR THIS MONTH: $0.48

////////////////////

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
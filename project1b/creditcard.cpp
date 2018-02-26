#include "creditcard.h"

//////////// CREDIT CARD CLASS ////////////

/*  Purpose :   Default constructor
 *  Input   :   None
 *  Output  :   None
 */
CreditCard::CreditCard() {
    cardnum_ = "0000000000000000";
    firstname_ = "firstname";
    lastname_ = "lastname";
    cardtype_ = "cardtype";
    balance_ = -1.0;
    creditlim_ = 0.0;
    overdraft_ = 0.0;
    rebate_ = 0.0;
    
    return;
}

/*  Purpose :   Sets cardnum_ to specified value
 *  Input   :   String parameter
 *  Output  :   None
 */
void CreditCard::SetCardnum(string number) {
    cardnum_ = number;
    
    return;
}

/*  Purpose :   Sets firstname_ to specified value
 *  Input   :   String parameter
 *  Output  :   None
 */
void CreditCard::SetFirstname(string name) {
    firstname_ = name;
    
    return;
}

/*  Purpose :   Sets lastname_ to specified value
 *  Input   :   String parameter
 *  Output  :   None
 */
void CreditCard::SetLastname(string name) {
    lastname_ = name;
    
    return;
}

/*  Purpose :   Sets cardtype_ to specified value
 *  Input   :   String parameter
 *  Output  :   None
 */
void CreditCard::SetCardtype(string type) {
    cardtype_ = type;
    
    return;
}

/*  Purpose :   Sets balance_ to specified value
 *  Input   :   Double parameter
 *  Output  :   None
 */
void CreditCard::SetBalance(double bal) {
    balance_ = bal;
    
    return;
}

/*  Purpose :   Sets creditlim_ to specified value
 *  Input   :   Double parameter
 *  Output  :   None
 */
void CreditCard::SetCreditlim(double lim) {
    creditlim_ = lim;
    
    return;
}

/*  Purpose :   Sets overdraft_ to specified value
 *  Input   :   Double parameter
 *  Output  :   None
 */
void CreditCard::SetOverdraft(double ovr) {
    overdraft_ = ovr;
    
    return;
}

/*  Purpose :   Sets rebate_ to specified value
 *  Input   :   Double parameter
 *  Output  :   None
 */
void CreditCard::SetRebate(double rebate) {
    rebate_ = rebate;
    
    return;
}

/*  Purpose :   Returns value stored in cardnum_
 *  Input   :   None
 *  Output  :   String value
 */
string CreditCard::GetCardnum() const {
    return cardnum_;
}

/*  Purpose :   Returns value stored in firstname_
 *  Input   :   None
 *  Output  :   String value
 */
string CreditCard::GetFirstname() const {
    return firstname_;
}

/*  Purpose :   Returns value stored in lastname_
 *  Input   :   None
 *  Output  :   String value
 */
string CreditCard::GetLastname() const {
    return lastname_;
}

/*  Purpose :   Returns value stored in cardtype_
 *  Input   :   None
 *  Output  :   String value
 */
string CreditCard::GetCardtype() const {
    return cardtype_;
}

/*  Purpose :   Returns value stored in balance_
 *  Input   :   None
 *  Output  :   Double value
 */
double CreditCard::GetBalance() const {
    return balance_;
}

/*  Purpose :   Returns value stored in creditlim_
 *  Input   :   None
 *  Output  :   Double value
 */
double CreditCard::GetCreditlim() const {
    return creditlim_;
}

/*  Purpose :   Returns value stored in overdraft_
 *  Input   :   None
 *  Output  :   Double value
 */
double CreditCard::GetOverdraft() const {
    return overdraft_;
}

/*  Purpose :   Returns value stored in rebate_
 *  Input   :   None
 *  Output  :   Double value
 */
double CreditCard::GetRebate() const {
    return rebate_;
}

/*  Purpose :   Determines if cardnum_ passes Luhn's Algorithm
 *  Input   :   None, all information available through member variables
 *  Output  :   Boolean value
 */
bool CreditCard::PassLuhn() const {
    vector<int> number;
    char digit;
    stringstream ccnumSS;
    bool pass = false;                                                          //function will return false unless number passes Luhn's algorithm
    int sum = 0;                                                                //stores sum of numbers in account number
    int x;                                                                      //stores calculated check digit to check against actual check digit
    int i;                                                                      //initialized for loops
    
    ccnumSS << " " << cardnum_;
    
    while (!isspace(ccnumSS.peek())){                                           //so long as digit isn't a space,
        ccnumSS >> digit;                                                       //reads in one digit from the stringstream
        number.push_back(digit - 48);                                           //pushes digit - 48 (for ascii difference) onto vector
    }
    
    for (i = number.size() - 2; i >= 0; i -= 2) {
        number.at(i) *= 2;                                                      //doubles every other number, starting with the first number left of the check digit and excluding the prefix
        if (number.at(i) > 9) {
            number.at(i) -= 9;                                                  //subtracts 9 if doubling results in number greater than 9
        }
    }
    
    for (i = 0; i < number.size() - 1; i++) {                                   //for loop calculates what the check digit should be and stores it in x
        sum += number.at(i);
    }
    
    sum *= 9;                                                                   //multiply sum by 9
    
    x = sum % 10;                                                               //if calculated check digit and actual check digit are the same value, passes Luhn's algorithm
    if (x == number.at(number.size() - 1)) {
        pass = true;
    }
    
    return pass;
}

//////////// GOLD CARD CLASS ////////////

/*  Purpose :   Default constructor
 *  Input   :   None
 *  Output  :   None
 */
GoldCard::GoldCard() {
    cardnum_ = "0000000000000000";
    firstname_ = "firstname";
    lastname_ = "lastname";
    cardtype_ = "Gold";
    balance_ = -1.0;
    creditlim_ = 3000.00;
    overdraft_ = 0.0;
    rebate_ = 0.01;
    
    return;
}

/*  Purpose :   Secondary constructor
 *  Input   :   3 string values, 1 double value
 *  Output  :   None
 */
GoldCard::GoldCard(string cardnum, string fname, string lname, double bal) {
    cardnum_ = cardnum;
    firstname_ = fname;
    lastname_ = lname;
    cardtype_ = "Gold";
    balance_ = bal;
    creditlim_ = 3000.00;
    overdraft_ = 0.0;
    rebate_ = 0.01;
    
    return;
}

//////////// PLATINUM CARD CLASS ////////////

/*  Purpose :   Default constructor
 *  Input   :   None
 *  Output  :   None
 */
PlatinumCard::PlatinumCard() {
    cardnum_ = "0000000000000000";
    firstname_ = "firstname";
    lastname_ = "lastname";
    cardtype_ = "Platinum";
    balance_ = -1.0;
    creditlim_ = 5000.00;
    overdraft_ = 1000.00;
    rebate_ = 0.02;
    
    return;
}

/*  Purpose :   Secondary constructor
 *  Input   :   3 string values, 1 double value
 *  Output  :   None
 */
PlatinumCard::PlatinumCard(string cardnum, string fname, string lname, double bal) {
    cardnum_ = cardnum;
    firstname_ = fname;
    lastname_ = lname;
    cardtype_ = "Platinum";
    balance_ = bal;
    creditlim_ = 5000.00;
    overdraft_ = 1000.00;
    rebate_ = 0.02;
    
    return;
}

//////////// CORPORATE CARD CLASS ////////////

/*  Purpose :   Default constructor
 *  Input   :   None
 *  Output  :   None
 */
CorporateCard::CorporateCard() {
    cardnum_ = "0000000000000000";
    firstname_ = "firstname";
    lastname_ = "lastname";
    cardtype_ = "Corporate";
    balance_ = -1.0;
    creditlim_ = 10000.00;
    overdraft_ = 5000.00;
    rebate_ = 0.05;
    
    return;
}

/*  Purpose :   Secondary constructor
 *  Input   :   3 string values, 1 double value
 *  Output  :   None
 */
CorporateCard::CorporateCard(string cardnum, string fname, string lname, double bal) {
    cardnum_ = cardnum;
    firstname_ = fname;
    lastname_ = lname;
    cardtype_ = "Corporate";
    balance_ = bal;
    creditlim_ = 10000.00;
    overdraft_ = 5000.00;
    rebate_ = 0.05;
    
    return;
}

//////////// TRANSACTION CLASS ////////////

/*  Purpose :   Default constructor
 *  Input   :   None
 *  Output  :   None
 */
Transaction::Transaction() {
    cardnum_ = "0000000000000000";
    firstname_ = "firstname";
    lastname_ = "lastname";
    cardtype_ = "cardtype";
    balance_ = -1.0;
    creditlim_ = 0.00;
    overdraft_ = 0.00;
    rebate_ = 0.00;
    date_ = "nodate";
    transaction_ = "notransaction";
    vendor_ = "novendor";
    amount_ = 0.00;
    evaluated_ = false;
    
    return;
}

/*  Purpose :   Secondary constructor
 *  Input   :   7 string values, 5 double values
 *  Output  :   None
 */
Transaction::Transaction(string cardnum, string fname, string lname, string type, double bal, double lim, double ovd, double rebate, string date, string trans, string vend, double amt) {
    cardnum_ = cardnum;
    firstname_ = fname;
    lastname_ = lname;
    cardtype_ = type;
    balance_ = bal;
    creditlim_ = lim;
    overdraft_ = ovd;
    rebate_ = rebate;
    date_ = date;
    transaction_ = trans;
    vendor_ = vend;
    amount_ = amt;
    evaluated_ = false;
    
    return;
}

/*  Purpose :   Sets date_ to specified value
 *  Input   :   String value
 *  Output  :   None
 */
void Transaction::SetDate(string date) {
    date_ = date;
    
    return;
}

/*  Purpose :   Sets transaction_ to specified value
 *  Input   :   String value
 *  Output  :   None
 */
void Transaction::SetTransaction(string num) {
    transaction_ = num;
    
    return;
}

/*  Purpose :   Sets vendor_ to specified value
 *  Input   :   String value
 *  Output  :   None
 */
void Transaction::SetVendor(string vendor) {
    vendor_ = vendor;
    
    return;
}

/*  Purpose :   Sets amount_ to specified value
 *  Input   :   Double value
 *  Output  :   None
 */
void Transaction::SetAmount(double amount) {
    amount_ = amount;
    
    return;
}

/*  Purpose :   Sets evaluated_ to specified value
 *  Input   :   Boolean value
 *  Output  :   None
 */
void Transaction::SetEval(bool tf) {
    evaluated_ = tf;
    
    return;
}

/*  Purpose :   Returns value stored in date_
 *  Input   :   None
 *  Output  :   String value
 */
string Transaction::GetDate() const {
    return date_;
}

/*  Purpose :   Returns value stored in transaction_
 *  Input   :   None
 *  Output  :   String value
 */
string Transaction::GetTransaction() const {
    return transaction_;
}

/*  Purpose :   Returns value stored in vendor_
 *  Input   :   None
 *  Output  :   String value
 */
string Transaction::GetVendor() const {
    return vendor_;
}

/*  Purpose :   Returns value stored in amount_
 *  Input   :   None
 *  Output  :   Double value
 */
double Transaction::GetAmount() const {
    return amount_;
}

/*  Purpose :   Returns value stored in evaluated_
 *  Input   :   None
 *  Output  :   Boolean value
 */
bool Transaction::GetEval() const {
    return evaluated_;
}
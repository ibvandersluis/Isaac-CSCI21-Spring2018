#include "functions.h"

//////////// CREDIT CARD CLASS ////////////

CreditCard::CreditCard() {
    cardnum_ = "0000000000000000";
    firstname_ = "firstname";
    lastname_ = "lastname";
    cardtype_ = "cardtype";
    balance_ = -1.0;
    creditlim_ = 0.0;
    overdraft_ = 0.0;
    
    return;
}

void CreditCard::SetCardnum(string number) {
    cardnum_ = number;
    
    return;
}

void CreditCard::SetFirstname(string name) {
    firstname_ = name;
    
    return;
}

void CreditCard::SetLastname(string name) {
    lastname_ = name;
    
    return;
}

void CreditCard::SetCardtype(string type) {
    cardtype_ = type;
    
    return;
}

void CreditCard::SetBalance(double bal) {
    balance_ = bal;
    
    return;
}

void CreditCard::SetCreditlim(double lim) {
    creditlim_ = lim;
    
    return;
}

void CreditCard::SetOverdraft(double ovr) {
    overdraft_ = ovr;
    
    return;
}

void CreditCard::SetRebate(double rebate) {
    rebate_ = rebate;
    
    return;
}

string CreditCard::GetCardnum() const {
    return cardnum_;
}

string CreditCard::GetFirstname() const {
    return firstname_;
}

string CreditCard::GetLastname() const {
    return lastname_;
}

string CreditCard::GetCardtype() const {
    return cardtype_;
}

double CreditCard::GetBalance() const {
    return balance_;
}

double CreditCard::GetCreditlim() const {
    return creditlim_;
}

double CreditCard::GetOverdraft() const {
    return overdraft_;
}

double CreditCard::GetRebate() const {
    return rebate_;
}

string CreditCard::PassLuhn(vector<int> number) const {
    bool pass = false;                                                          //function will return false unless number passes Luhn's algorithm
    int sum = 0;                                                                //stores sum of numbers in account number
    int x;                                                                      //stores calculated check digit to check against actual check digit
    int i;                                                                      //initialized for loops
    
    
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
    
    if (pass == true) {                                                         //returns "Accepted" if Luhn's passes and "Declined" otherwise
        return "PASS";
    } else {
        return "FAIL";
    }
}

//////////// GOLD CARD CLASS ////////////

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
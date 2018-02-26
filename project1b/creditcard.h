/*
 *  Project 1B - Credit Card
 *
 *  Written by           Isaac Vander Sluis
 *  Created on           2/15/18
 *
 *  This program stores credit cards as objects, each containing information
 *  the credit card number, the first and last name of the card holder, the card
 *  type, and current balance. The program will iterate through a file of this
 *  data and store each card as an object in an array. The program will then
 *  iterate through a list of transactions and determine which should be denied.
 *  Finally the program outputs a file with declined transactions and the reason
 *  they were declined, along with accepted transactions, a cost breakdown,
 *  whether the card is in overdraw or not, and the rebate value.
 *
 *  Gold Card:
 *   
 *      -   Credit line $3,000
 *      -   Once limit is reached, the card will be blocked
 *      -   Each month, a rebate of 1% of the total monthly purchase is awarded to the account
 *
 *  Platinum Card:
 *   
 *      -   Credit line is $5,000
 *      -   An overdraft of $1,000 is allowed. A warning message is issued through the account summary
 *      -   Each month, a rebate of 2% of the total monthly purchase is awarded to the account
 *
 *  Corporate Card:
 * 
 *      -   Credit line of $10,000
 *      -   An overdraft of $5, 000 is allowed. A warning message is issued through the account summary
 *      -   Each month, a rebate of 5% of the total monthly purchase is awarded to the account
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
#include <algorithm>
using namespace std;
using std::fixed;
using std::setprecision;
using std::setfill;
using std::setw;

class CreditCard {
    public:
        CreditCard();                                                           //constructor
        
        void    SetCardnum(string number);                                      //mutator
        void    SetFirstname(string name);                                      //mutator
        void    SetLastname(string name);                                       //mutator
        void    SetCardtype(string type);                                       //mutator
        void    SetBalance(double bal);                                         //mutator
        void    SetCreditlim(double lim);                                       //mutator
        void    SetOverdraft(double ovr);                                       //mutator
        void    SetRebate(double rebate);                                       //mutator
        
        string  GetCardnum() const;                                             //accessor
        string  GetFirstname() const;                                           //accessor
        string  GetLastname() const;                                            //accessor
        string  GetCardtype() const;                                            //accessor
        double  GetBalance() const;                                             //accessor
        double  GetCreditlim() const;                                           //accessor
        double  GetOverdraft() const;                                           //accessor
        double  GetRebate() const;
        
        string  PassLuhn() const;                                               //determines if card passes Luhn's algorithm
    protected:
        string  cardnum_;                                                       //stores credit card's number
        string  firstname_;                                                     //stores card holder's first name
        string  lastname_;                                                      //stores card holder's last name
        string  cardtype_;                                                      //stores card type
        double  balance_;                                                       //stores balance
        double  creditlim_;                                                     //stores credit limit
        double  overdraft_;                                                     //stores amount of overdraft permitted to card holder
        double  rebate_;                                                        //stores the percent rebate given to the card holder each month
};

class GoldCard : public CreditCard {
    public:
        GoldCard();                                                             //constructor
        GoldCard(string cardnum, string fname, string lname, double bal);       //secondary constructor
    private:
};

class PlatinumCard : public CreditCard {
    public:
        PlatinumCard();                                                         //constructor
        PlatinumCard(string cardnum, string fname, string lname, double bal);   //secondary constructor
    private:
};

class CorporateCard : public CreditCard {
    public:
        CorporateCard();                                                        //constructor
        CorporateCard(string cardnum, string fname, string lname, double bal);  //secondary constructor
    private:
};

class Transaction : public CreditCard {
    public:
        Transaction();                                                          //constructor and secondary constructor
        Transaction(string cardnum, string fname, string lname, string type, double bal, double lim, double ovd, double rebate, string date, string trans, string vend, double amt);                                                          //secondary constructor
        
        void    SetDate(string date);                                           //mutator
        void    SetTransaction(string num);                                     //mutator
        void    SetVendor(string vendor);                                       //mutator
        void    SetAmount(double amount);                                       //mutator
        void    SetEval(bool tf);                                               //mutator
        
        string  GetDate() const;                                                //accessor
        string  GetTransaction() const;                                         //accessor
        string  GetVendor() const;                                              //accessor
        double  GetAmount() const;                                              //accessor
        bool    GetEval() const;                                                //accessor
    private:
        string  date_;                                                          //stores transaction date
        string  transaction_;                                                   //stores transaction number
        string  vendor_;                                                        //stores transaction vendor
        double  amount_;                                                        //stores transaction amount
        bool    evaluated_;                                                     //stores bool value, true if transaction have been evaluated, false otherwise
};
    
#endif
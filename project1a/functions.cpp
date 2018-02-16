#include "functions.h"

string CardType(vector<int> number) {
    string str = WholeNum(number);                                              //turns the vector into a string using the WholeNum() function
    if ((str.substr(0, 2) == "34" || str.substr(0, 2) == "37") && str.size() == 15) {
        return "AMERICAN EXPRESS";                                              //determines which prefix fits the card number
    } else if ((str.substr(0, 4) == "6011" || (str.substr(0, 6) >= "622126" && str.substr(0, 6) <= "622925") || (str.substr(0, 3) >= "644" && str.substr(0, 3) <= "649") || str.substr(0, 2) == "65") && str.size() == 16) {
        return "DISCOVER";
    } else if ((str.substr(0, 2) >= "51" && str.substr(0, 2) <= "55") && number.size() == 16) {
        return "MASTERCARD";
    } else if (str.at(0) == '4' && (str.size() >= 13 && str.size() <= 16)) {
        return "VISA";
    } else {
        return "UNKNOWN CARD TYPE";                                             //returns unknown if prefix not recognized
    }
    
}

string PassLuhn(vector<int> number) {
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

string WholeNum(vector<int> number) {
    stringstream whole;                                                         //initializes stringstream for digits to be added to
    for (int i = 0; i < number.size(); i++) {
        whole << number.at(i);
    }
    return whole.str();                                                         //returns string of digits as one string
}
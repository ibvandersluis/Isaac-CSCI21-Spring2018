#include "money.h"

// The Constructor, Accessors and Mutators have been defined for you
Money::Money(int dollars, int cents)
      : dollars_(dollars),
        cents_(cents) {
}

int Money::dollars() const {
    return dollars_;
}

int Money::cents() const {
    return cents_;
}

void Money::set_dollars(int dollars) {
    dollars_ = dollars;
}

void Money::set_cents(int cents) {
    cents_ = cents;
}

// This function definition provided as an example and is FULLY COMPLETE
const Money operator +(const Money& amount1, const Money& amount2) {
    // Get all the cents of object 1
    int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
    // Get all the cents of object 2
    int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
    // Add all the cents together
    int sum_all_cents = all_cents1 + all_cents2;
    // Handle the fact that money can be negative
    int abs_all_cents = abs(sum_all_cents);
    int final_dollars = abs_all_cents / 100;
    int final_cents = abs_all_cents % 100;
    // If the result of the operation was negative, negate final dollars and cents
    if (sum_all_cents < 0) {
        final_dollars = -final_dollars;
        final_cents = -final_cents;
    }
    return Money(final_dollars, final_cents);
}

const Money operator -(const Money& amount1, const Money& amount2) {
    // Get all cents of obj 1
    int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
    // Get all cents of obj 2
    int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
    // Take difference between obj 1 and obj 2
    int diff_all_cents = all_cents1 - all_cents2;
    // Allow for negative moneys
    int abs_all_cents = abs(diff_all_cents);
    int final_dollars = abs_all_cents / 100;
    int final_cents = abs_all_cents % 100;
    // Make values negative if result is negative
    if (diff_all_cents < 0) {
        final_dollars = -final_dollars;
        final_cents = -final_cents;
    }
    return Money(final_dollars, final_cents);
}

bool operator ==(const Money &amount1, const Money &amount2) {
    // Returns false by default. Function must be compelled to return true
    bool is_equal = false;
    // Get all cents of obj 1
    int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
    // Get all cents of ojb 2
    int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
    // If total cents of obj 1 == total cents of obj 2, will return true
    if (all_cents1 == all_cents2) {
        is_equal = true;
    }
    return is_equal;
}

const Money operator -(const Money &amount) {
    // Get negated value of cents_ member variable
    int cents = -amount.cents_;
    // Get negated value of dollars_ member variable
    int dollars = -amount.dollars_;
    return Money(dollars, cents);
}

ostream& operator <<(ostream &out, const Money &amount) {
    // Empty string to store negative sign if amount is negative
    string neg = "";
    // If either member variable is negative, set string to "-"
    if ((amount.dollars_ < 0) || (amount.cents_ < 0)) {
        neg = "-";
    }
    // Format output
    out << "$" << neg << abs(amount.dollars_) << "." << setw(2) << setfill('0') << abs(amount.cents_);
    
    return out;
}
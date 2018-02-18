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

friend const Money operator -(const Money& amount1, const Money& amount2) {
    // Get all cents of obj 1
    int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
    // Get all cents of obj 2
    int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
    // Take difference between obj 1 and obj 2
    int diff_all_cents = all_cents1 - all_cents2;
    // Allow for negative moneys
    int abs_all_cents = abs(diff_all_cents);
    int final dollars = abs_all_cents / 100;
    int final cents = abs_all_cents % 100;
    // Make values negative if result is negative
    if (diff_all_cents < 0) {
        final_dollars = -final_dollars;
        final_cents = -final_cents;
    }
    return Money(final_dollars, final_cents);
}

friend bool operator ==(const Money &amount1, const Money &amount2) {
    bool is_equal = false;
    int all_cents1 = amount1.cents_ + amount1.dollars_ * 100;
    int all_cents2 = amount2.cents_ + amount2.dollars_ * 100;
    if all_cents1 == all_cents2) {
        is_equal = true;
    }
    return is_equal;
}

friend const Money operator -(const Money &amount) {
    int cents = -amount.cents_;
    int dollars = -amount.dollars_;
    return Money(dollars, cents);
}

friend ostream& operator <<(ostream &out, const Money &amount) {
    
}
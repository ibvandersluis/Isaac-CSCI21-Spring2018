#include "food_item.h"

FoodItem::FoodItem() {
    name_ = "fooditem";
    value_ = 0;
    calories_ = 0;
    unit_of_measure_ = "nounits";
    units_ = 0;
    
    return;
}

FoodItem::FoodItem(string name, unsigned int val, unsigned int cal, string unit, double units) {
    name_ = name;
    value_ = val;
    calories_ = cal;
    unit_of_measure_ = unit;
    units_ = units;
    
    return;
}

FoodItem::~FoodItem() {}

void FoodItem::set_calories(unsigned int cal) {
    calories_ = cal;
    
    return;
}

void FoodItem::set_unit_of_measure(string unit) {
    unit_of_measure_ = unit;
    
    return;
}

void FoodItem::set_units(double units) {
    units_ = units;
    
    return;
}

unsigned int FoodItem::calories() const {
    return calories_;
}

string FoodItem::unit_of_measure() const {
    return unit_of_measure_;
}

double FoodItem::units() const {
    return units_;
}

string FoodItem::ToString() const {
    stringstream SS;
    SS << fixed << setprecision(2);
    SS << name_ << ", $" << value_ << ", " << units_ << " " << unit_of_measure_ << ", " << calories_ << " calories";
    
    return SS.str();
}
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

void FoodItem::SetCalories(unsigned int cal) {
    calories_ = cal;
    
    return;
}

void FoodItem::SetUnit(string unit) {
    unit_of_measure_ = unit;
    
    return;
}

void FoodItem::SetUnits(double units) {
    units_ = units;
    
    return;
}

unsigned int FoodItem::GetCalories() const {
    return calories_;
}

string FoodItem::GetUnit() const {
    return unit_of_measure_;
}

double FoodItem::GetUnits() const {
    return units_;
}

string FoodItem::ToString() const {
    stringstream SS;
    SS << name_ << ", $" << value_ << ", " << units_ << unit_of_measure_ << ", " << calories_;
    
    return SS.str();
}
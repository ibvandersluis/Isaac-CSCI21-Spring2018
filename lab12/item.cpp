#include "item.h"

Item::Item() {
    name_ = "item";
    value_ = 0;
    
    return;
}

Item::Item(string name, unsigned int val) {
    name_ = name;
    value_ = val;
    
    return;
}

void Item::name(string name) {
    name_ = name;
    
    return;
}

void Item::value(unsigned int val) {
    value_ = val;
    
    return;
}

string Item::GetName() const {
    return name_;
}

unsigned int Item::GetValue() const {
    return value_;
}

string ToString() const {
    stringstream SS;
    SS << name_ << ", $" << value_;
    
    return SS.str();
}
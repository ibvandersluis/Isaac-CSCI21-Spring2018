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

Item::~Item() {}

void Item::set_name(string name) {
    name_ = name;
    
    return;
}

void Item::set_value(unsigned int val) {
    value_ = val;
    
    return;
}

string Item::name() const {
    return name_;
}

unsigned int Item::value() const {
    return value_;
}

string Item::ToString() const {
    stringstream SS;
    SS << name_ << ", $" << value_;
    
    return SS.str();
}
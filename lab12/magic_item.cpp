#include "magic_item.h"

MagicItem::MagicItem() {
    name_ = "magicitem";
    value_ = 0;
    description_ = "no description";
    mana_required_ = 0;
    
    return;
}

MagicItem::MagicItem(string name, unsigned int val, string entry, unsigned int mana) {
    name_ = name;
    value_ = val;
    description_ = entry;
    mana_required_ = mana;
    
    return;
}

MagicItem::~MagicItem() {}

void MagicItem::set_description(string entry) {
    description_ = entry;
    
    return;
}

void MagicItem::set_mana_required(unsigned int mana) {
    mana_required_ = mana;
    
    return;
}

string MagicItem::description() const {
    return description_;
}

unsigned int MagicItem::mana_required() const {
    return mana_required_;
}

string MagicItem::ToString() const {
    stringstream SS;
    SS << name_ << ", $" << value_ << ", " << description_ << ", requires " << mana_required_ << " mana";
    
    return SS.str();
}
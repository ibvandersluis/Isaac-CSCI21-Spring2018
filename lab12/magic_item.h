#ifndef magic_item_h
#define magic_item_h

#include "item.h"

class MagicItem : public Item {
    public:
        MagicItem();                                                            // Constructor
        MagicItem(string name, unsigned int val, string entry, unsigned int mana);
        virtual ~MagicItem();                                                   // Secondary constructor and destructor
        
        void set_description(string entry);                                     // Mutator
        void set_mana_required(unsigned int mana);                              // Mutator
        
        string description() const;                                             // Accessor
        unsigned int mana_required() const;                                     // Accessor
        
        string ToString() const;                                                // Returns name_, value_, description_, and mana_required_ in a string
    private:
        string description_;                                                    // Holds a description of the magic item
        unsigned int mana_required_;                                            // holds the amount of mana required to use the magic item
};

#endif
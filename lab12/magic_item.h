#ifndef food_item_h
#define food_item_h

#include "item.h"

class MagicItem : public Item {
    public:
        MagicItem(string name, unsigned int val, string entry, unsigned int mana);
        virtual ~MagicItem();                                                   // Constructor and destructor
        
        void SetDescription(string entry);                                      // Mutator
        void SetMana(unsigned int mana);                                        // Mutator
        
        string GetDescription() const;                                          // Accessor
        unsigned int GetMana() const;                                           // Accessor
        
        string ToString() const;                                                // Returns name_, value_, description_, and mana_required_ in a string
    private:
        string description_;                                                    // Holds a description of the magic item
        unsigned int mana_required_;                                            // holds the amount of mana required to use the magic item
};

#endif
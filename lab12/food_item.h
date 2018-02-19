#ifndef food_item_h
#define food_item_h

#include "item.h"

class FoodItem : public Item {
    public:
        FoodItem();                                                             // Default constructor
        FoodItem(string name, unsigned int val, unsigned int cal, string unit, double units);
        virtual ~FoodItem();                                                    // Constructor and destructor
        
        void set_calories(unsigned int cal);                                    // Mutator
        void set_unit_of_measure(string unit);                                  // Mutator
        void set_units(double units);                                           // Mutator
        
        unsigned int calories() const;                                          // Accessor
        string unit_of_measure() const;                                         // Accessor
        double units() const;                                                   // Accessor
        
        string ToString() const;                                                // Returns name_, value_, calories_, unit_of_measure_, and units_ in a string
    private:
        unsigned int calories_;                                                 // Holds a calorie count
        string unit_of_measure_;                                                // Holds the unit of measure (i.e. ounces)
        double units_;                                                          // Holds a count of how many units we have
};

#endif
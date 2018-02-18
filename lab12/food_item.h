#ifndef food_item_h
#define food_item_h

#include "item.h"

class FoodItem : public Item {
    public:
        FoodItem(string name, unsigned int val, unsigned int cal, string unit, double units);
        virtual ~FoodItem();                                                    // Constructor and destructor
        
        void SetCalories(unsigned int cal);                                     // Mutator
        void SetUnit(string unit);                                              // Mutator
        void SetUnits(double units);                                            // Mutator
        
        unsigned int GetCalories() const;                                       // Accessor
        string GetUnit() const;                                                 // Accessor
        double GetUnits() const;                                                // Accessor
        
        string ToString() const;                                                // Returns name_, value_, calories_, unit_of_measure_, and units_ in a string
    private:
        unsigned int calories_;                                                 // Holds a calorie count
        string unit_of_measure_;                                                // Holds the unit of measure (i.e. ounces)
        double units_;                                                          // Holds a count of how many units we have
};

#endif
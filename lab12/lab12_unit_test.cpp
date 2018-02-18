/*
 * Name        : lab_10_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #26 Functionality
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "item.h"
#include "food_item.h"
#include "magic_item.h"
// To Test for Correct Header Guards
#include "item.h"
#include "food_item.h"
#include "magic_item.h"

TEST_CASE("Item Class") {
  SECTION("Default Constructor") {
    Item item;
    CHECK(item.name() == "item");
    CHECK(item.value() == 0);
    CHECK(item.ToString() == "item, $0");
  }

  SECTION("Overloaded Constructor") {
    Item item("game", 25);
    CHECK(item.name() == "game");
    CHECK(item.value() == 25);
    CHECK(item.ToString() == "game, $25");
  }

  SECTION("Accessors / Mutators") {
    Item item;
    item.set_name("car");
    item.set_value(35000);
    CHECK(item.name() == "car");
    CHECK(item.value() == 35000);
    CHECK(item.ToString() == "car, $35000");
  }
}

TEST_CASE("FoodItem Class") {
  SECTION("Default Constructor") {
    FoodItem item;
    CHECK(item.name() == "fooditem");
    CHECK(item.value() == 0);
    CHECK(item.calories() == 0);
    CHECK(item.unit_of_measure() == "nounits");
    CHECK(item.units() == 0);
    CHECK(item.ToString() == "fooditem, $0, 0.00 nounits, 0 calories");
  }

  SECTION("Overloaded Constructor(\"coffee\", 1, 10, \"ounces\", 10.25)") {
    FoodItem item("coffee", 1, 10, "ounces", 10.25);
    CHECK(item.name() == "coffee");
    CHECK(item.value() == 1);
    CHECK(item.calories() == 10);
    CHECK(item.unit_of_measure() == "ounces");
    CHECK(item.units() == 10.25);
    CHECK(item.ToString() == "coffee, $1, 10.25 ounces, 10 calories");
  }

  SECTION("Accessors / Mutators") {
    FoodItem item;
    item.set_name("cupcake");
    item.set_value(5);
    item.set_calories(200);
    item.set_unit_of_measure("cake(s)");
    item.set_units(1.5);
    CHECK(item.name() == "cupcake");
    CHECK(item.value() == 5);
    CHECK(item.calories() == 200);
    CHECK(item.unit_of_measure() == "cake(s)");
    CHECK(item.units() == 1.5);
    CHECK(item.ToString() == "cupcake, $5, 1.50 cake(s), 200 calories");
  }
}

TEST_CASE("MagicItem Class") {
  SECTION("Default Constructor") {
    MagicItem item;
    CHECK(item.name() == "magicitem");
    CHECK(item.value() == 0);
    CHECK(item.description() == "no description");
    CHECK(item.mana_required() == 0);
    CHECK(item.ToString() == "magicitem, $0, no description, requires 0 mana");
  }

  SECTION("Overloaded Constructor(\"staff\", 999, \"carved wood\", 125)") {
    MagicItem item("staff", 999, "carved wood", 125);
    CHECK(item.name() == "staff");
    CHECK(item.value() == 999);
    CHECK(item.description() == "carved wood");
    CHECK(item.mana_required() == 125);
    CHECK(item.ToString() == "staff, $999, carved wood, requires 125 mana");
  }

  SECTION("Accessors / Mutators") {
    MagicItem item;
    item.set_name("wand");
    item.set_value(1000);
    item.set_description("jewel-encrusted");
    item.set_mana_required(50);
    CHECK(item.name() == "wand");
    CHECK(item.value() == 1000);
    CHECK(item.description() == "jewel-encrusted");
    CHECK(item.mana_required() == 50);
    CHECK(item.ToString() == "wand, $1000, jewel-encrusted, requires 50 mana");
  }
}
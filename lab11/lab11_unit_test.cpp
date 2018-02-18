/*
 * Name        : lab_11_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #11 Functionality
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <sstream>
#include <streambuf>
using std::cout;
using std::endl;

#include "money.h"
// To test for correct Header Guards
#include "money.h"

TEST_CASE("Overloaded + Operator") {
  Money amount1(123, 45), amount2(10, 9);
  SECTION("Money(123, 45) + Money(10, 9), i.e $123.45 + $10.09") {
    Money sum = amount1 + amount2;
    CHECK(sum.dollars() == 133);
    CHECK(sum.cents() == 54);
  }

  SECTION("Money(-8, -75) + Money(0, 50), i.e $-8.75 + $0.50") {
    amount1.set_dollars(-8);
    amount1.set_cents(-75);
    amount2.set_dollars(0);
    amount2.set_cents(50);
    Money sum = amount1 + amount2;
    CHECK(sum.dollars() == -8);
    CHECK(sum.cents() == -25);
  }
}

TEST_CASE("Overloaded Binary - Operator") {
  Money amount1(123, 45), amount2(10, 9);

  SECTION("Money(123, 45) - Money(10, 9), i.e $123.45 - $10.09") {
    Money diff = amount1 - amount2;
    CHECK(diff.dollars() == 113);
    CHECK(diff.cents() == 36);
  }

  SECTION("Money(10, 9) - Money(123, 45), i.e $10.09 - $123.45") {
    Money diff = amount2 - amount1;
    CHECK(diff.dollars() == -113);
    CHECK(diff.cents() == -36);
  }

  SECTION("Money(-8, -75) - Money(0, 50), i.e $-8.75 - $0.50") {
    amount1.set_dollars(-8);
    amount1.set_cents(-75);
    amount2.set_dollars(0);
    amount2.set_cents(50);
    Money diff = amount1 - amount2;
    CHECK(diff.dollars() == -9);
    CHECK(diff.cents() == -25);
  }

  SECTION("Money(0, 50) - Money(-8, -75), i.e $0.50 - $-8.75") {
    amount1.set_dollars(-8);
    amount1.set_cents(-75);
    amount2.set_dollars(0);
    amount2.set_cents(50);
    Money diff = amount2 - amount1;
    CHECK(diff.dollars() == 9);
    CHECK(diff.cents() == 25);
  }
}

TEST_CASE("Overloaded Unary - Operator") {
  SECTION("-Money(123, 45), i.e -$123.45") {
    Money amount(123, 45);
    amount = -amount;
    CHECK(amount.dollars() == -123);
    CHECK(amount.cents() == -45);
  }

  SECTION("-Money(9, 25), i.e -$-9.25") {
    Money amount(-9, -25);
    amount = -amount;
    CHECK(amount.dollars() == 9);
    CHECK(amount.cents() == 25);
  }
}

TEST_CASE("Overloaded == Operator") {
  SECTION("Money(10, 55) == Money(10, 55), i.e $10.55 == $10.55") {
    Money amount1(10, 55), amount2(10, 55);
    CHECK(amount1 == amount2);
  }

  SECTION("Money(-10, -55) == Money(-10, -55), i.e $-10.55 == $-10.55") {
    Money amount1(-10, -55), amount2(-10, -55);
    CHECK(amount1 == amount2);
  }

  SECTION("Money(10, 55) == Money(-10, -55), i.e $10.55 == $-10.55") {
    Money amount1(10, 55), amount2(-10, -55);
    CHECK((amount1 == amount2) == false);
  }
}

TEST_CASE("Overloaded << Operator") {
  SECTION("cout << Money(0, 10), i.e $0.10") {
    Money money(0, 10);
    std::streambuf* old_cout = cout.rdbuf();
    std::ostringstream capture_cout;
    cout.rdbuf(capture_cout.rdbuf());
    cout << money;
    cout.rdbuf(old_cout);
    CHECK(capture_cout.str() == "$0.10");
  }

  SECTION("cout << Money(0, -10), i.e $-0.10") {
    Money money(0, -10);
    std::streambuf* old_cout = cout.rdbuf();
    std::ostringstream capture_cout;
    cout.rdbuf(capture_cout.rdbuf());
    cout << money;
    cout.rdbuf(old_cout);
    CHECK(capture_cout.str() == "$-0.10");
  }

  SECTION("cout << Money(100, 2), i.e $100.02") {
    Money money(100, 2);
    std::streambuf* old_cout = cout.rdbuf();
    std::ostringstream capture_cout;
    cout.rdbuf(capture_cout.rdbuf());
    cout << money;
    cout.rdbuf(old_cout);
    CHECK(capture_cout.str() == "$100.02");
  }

  SECTION("cout << Money(-100, -2), i.e $-100.02") {
    Money money(-100, -2);
    std::streambuf* old_cout = cout.rdbuf();
    std::ostringstream capture_cout;
    cout.rdbuf(capture_cout.rdbuf());
    cout << money;
    cout.rdbuf(old_cout);
    CHECK(capture_cout.str() == "$-100.02");
  }
}
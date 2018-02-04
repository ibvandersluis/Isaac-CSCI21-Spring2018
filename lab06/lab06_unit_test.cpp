/*
 * Name        : lab06_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #6 Functionality
 * Sources     : 
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "lab06.h"

TEST_CASE("Prepare Array For Display Function") {
  int values[] = { 3, 5, 7, 9, 11 };
  int size = 5;

  SECTION("PrepareForDisplay({3, 5, 7, 9, 11}, 5)") {
    CHECK(PrepareForDisplay(values, size) == "3,5,7,9,11");
  }

  SECTION("PrepareForDisplay({3, 5, 7, 9, 11}, 5, ' ')") {
    CHECK(PrepareForDisplay(values, size, ' ') == "3 5 7 9 11");
  }

  SECTION("PrepareForDisplay({3, 5, 7, 9, 11}, 5, ':')") {
    CHECK(PrepareForDisplay(values, size, ':') == "3:5:7:9:11");
  }
}

TEST_CASE("Array Has Specified Value Function") {
  int values[] = { 3, 5, 7, 9, 11 };
  int size = 5;

  SECTION("HasValue({3, 5, 7, 9, 11}, 5, 0)") {
    CHECK(HasValue(values, size, 0) == false);
  }

  SECTION("HasValue({3, 5, 7, 9, 11}, 5, 3)") {
    CHECK(HasValue(values, size, 3) == true);
  }

  SECTION("HasValue({3, 5, 7, 9, 11}, 5, 11)") {
    CHECK(HasValue(values, size, 11) == true);
  }
}

TEST_CASE("Value at Sepcified Index in Array Function") {
  int values[] = { 3, 5, 7, 9, 11 };
  int size = 5;
  bool error = true;

  SECTION("ValueAt({3, 5, 7, 9, 11}, 5, 0, error)") {
    CHECK(ValueAt(values, size, 0, error) == 3);
    CHECK(error == false);
  }

  SECTION("ValueAt({3, 5, 7, 9, 11}, 5, 5, error)") {
    CHECK(ValueAt(values, size, 5, error) == 0);
    CHECK(error == true);
  }

  SECTION("ValueAt({3, 5, 7, 9, 11}, 5, 4, error)") {
    CHECK(ValueAt(values, size, 4, error) == 11);
    CHECK(error == false);
  }
}

TEST_CASE("Sum Array Function") {
  int values[] = {3, 5, 7, 9, 11};
  int size = 5;

  SECTION("Sum({3, 5, 7, 9, 11}, 5)") {
    CHECK(Sum(values, size) == 35);
  }

  SECTION("Sum({3}, 1)") {
    CHECK(Sum(values, 1) == 3);
  }

  SECTION("Sum({}, 0)") {
    CHECK(Sum(values, 0) == 0);
  }
}

TEST_CASE("Swap Value in Array Function") {
  int values[] = { 3, 5, 7, 9, 11 };
  int size = 5;
  bool success = false;

  SECTION("SwapValues({3, 5, 7, 9, 11}, 5, 0, 4)") {
    CHECK(SwapValues(values, size, 0, 4) == true);
    CHECK(values[0] == 11);
    CHECK(values[1] == 5);
    CHECK(values[2] == 7);
    CHECK(values[3] == 9);
    CHECK(values[4] == 3);
  }

  SECTION("SwapValues({3, 5, 7, 9, 11}, 5, 1, 3)") {
    CHECK(SwapValues(values, size, 1, 3) == true);
    CHECK(values[0] == 3);
    CHECK(values[1] == 9);
    CHECK(values[2] == 7);
    CHECK(values[3] == 5);
    CHECK(values[4] == 11);
  }

  SECTION("SwapValues({3, 5, 7, 9, 11}, 5, 2, 2)") {
    CHECK(SwapValues(values, size, 2, 2) == true);
    CHECK(values[0] == 3);
    CHECK(values[1] == 5);
    CHECK(values[2] == 7);
    CHECK(values[3] == 9);
    CHECK(values[4] == 11);
  }

  SECTION("SwapValues({3, 5, 7, 9, 11}, 5, -2, 2)") {
    CHECK(SwapValues(values, size, -2, 2) == false);
    CHECK(values[0] == 3);
    CHECK(values[1] == 5);
    CHECK(values[2] == 7);
    CHECK(values[3] == 9);
    CHECK(values[4] == 11);
  }

  SECTION("SwapValues({3, 5, 7, 9, 11}, 5, 2, 10)") {
    CHECK(SwapValues(values, size, 2, 5) == false);
    CHECK(values[0] == 3);
    CHECK(values[1] == 5);
    CHECK(values[2] == 7);
    CHECK(values[3] == 9);
    CHECK(values[4] == 11);
  }
}

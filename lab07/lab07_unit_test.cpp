/*
 * Name        : lab_7_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #7 Functionality
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "lab07.h"

map<int, int> counters;

void OnTen() {
  counters[10]++;
}

void OnTwenty() {
  counters[20]++;
}

void OnThirty() {
  counters[30]++;
}

void OnForty() {
  counters[40]++;
}

void OnFifty() {
  counters[50]++;
}

void OnError() {
  counters[99]++;
}

TEST_CASE("Processing File \"lab_7_input.txt\"") {
  counters[10] = 0, counters[20] = 0, counters[30] = 0, counters[40] = 0,
  counters[50] = 0, counters[99] = 0;
  ProcessFile("lab_7_input.txt");

  SECTION("Counting 10s") {
    CHECK(counters[10] == 15);
  }

  SECTION("Counting 20s") {
    CHECK(counters[20] == 14);
  }

  SECTION("Counting 30s") {
    CHECK(counters[30] == 13);
  }

  SECTION("Counting 40s") {
    CHECK(counters[40] == 12);
  }

  SECTION("Counting 50s") {
    CHECK(counters[50] == 11);
  }

  SECTION("Counting Errors") {
    CHECK(counters[99] == 35);
  }
}

TEST_CASE("Processing File \"non-existent-file.txt\"") {
  SECTION("Processing non-existent file") {
    CHECK(ProcessFile("non-existent-file.txt") == false);
  }
}

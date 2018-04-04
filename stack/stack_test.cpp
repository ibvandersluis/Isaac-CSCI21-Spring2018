/*
 * Name        : stack_test.cpp
 * Author      : Isaac Vander Sluis
 * Description : Unit test to test stack functionality
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <iostream>
using namespace std;

#include "stack.h"
// To test for correct Header Guards
#include "stack.h"

TEST_CASE("START") {
  Stack stack1;
  SECTION("Empty Constructed Stack") {
    CHECK(stack1.GetHead() == NULL);
  }
  
    stack1.Push("James");

  SECTION("Print Function") {
    CHECK(stack1.Print() == "James");
  }
  
  SECTION("Stack Size, Check #1") {
    CHECK(stack1.Size() == 1);
  }
  
  SECTION("Pop Head") {
    CHECK(stack1.Pop() == "James");
  }
  
  SECTION("Stack Size, Check #2") {
    CHECK(stack1.Size() == 0);
  }
  
  SECTION("Empty Stack") {
    CHECK(stack1.GetHead() == NULL);
  }
}

TEST_CASE("MIDDLE") {
  Stack stack2;
  
  stack2.Push("Ragnar");
  stack2.Push("Lagertha");
  stack2.Push("Bjorn");
  stack2.Push("Floki");
  stack2.Push("Torvi");

  SECTION("Print Function") {
    CHECK(stack2.Print() == "Torvi, Floki, Bjorn, Lagertha, Ragnar");
  }

  SECTION("Stack Size, Check #1") {
    CHECK(stack2.Size() == 5);
  }
  
  SECTION("Pop #1") {
    CHECK(stack2.Pop() == "Torvi");
    Check(stack2.Size() == 4);
  }
  
  SECTION("Pop #2") {
    CHECK(stack2.Pop() == "Floki");
    Check(stack2.Size() == 3);
  }
  
  SECTION("Pop #3") {
    CHECK(stack2.Pop() == "Bjorn");
    Check(stack2.Size() == 2);
  }
  
  SECTION("Pop #4") {
    CHECK(stack2.Pop() == "Lagertha");
    Check(stack2.Size() == 1);
  }
  
  SECTION("Pop #5") {
    CHECK(stack2.Pop() == "Ragnar");
    Check(stack2.Size() == 0);
  }
}

TEST_CASE("END") {
    Stack stack3;
    
    stack3.Push("Tyrion");
    stack3.Push("John");
    stack3.Push("Jaime");
    stack3.Push("Sansa");
    stack3.Push("Arya");
    
    stack3.Pop();
    stack3.Pop();
    stack3.Pop();
    stack3.Pop();
    stack3.Pop();
    
    SECTION("Empty Stack") {
        CHECK(stack3.GetHead() == NULL);
        CHECK(stack3.Size() == 0);
    }
    
    SECTION("Print Empty Stack") {
        CHECK(stack3.Print() == "ERROR");
    }
    
    SECTION("Pop Empty Stack") {
        CHECK(stack3.Pop() == "ERROR");
    }
}

  
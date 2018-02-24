/*
 * Name        : lab_21_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #21 Functionality
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "template.cpp"

TEST_CASE("PrepareForDisplay()") {
  SECTION("Integers. Array: { 3, 5, 7, 9, 11 }") {
    int int_values[] = { 3, 5, 7, 9, 11 };
    CHECK(PrepareForDisplay(int_values, 5) == "3,5,7,9,11");
    CHECK(PrepareForDisplay(int_values, 5, ' ') == "3 5 7 9 11");
    CHECK(PrepareForDisplay(int_values, 5, ':') == "3:5:7:9:11");
  }

  SECTION("Doubles. Array: { 3.1, 5.2, 7.3, 9.4, 11.5 }") {
    double double_values[] = { 3.1, 5.2, 7.3, 9.4, 11.5 };
    CHECK(PrepareForDisplay(double_values, 5) == "3.10,5.20,7.30,9.40,11.50");
    CHECK(PrepareForDisplay(double_values, 5, ' ')
          == "3.10 5.20 7.30 9.40 11.50");
    CHECK(PrepareForDisplay(double_values, 5, ':')
          == "3.10:5.20:7.30:9.40:11.50");
  }

  SECTION("Strings. Array: { \"A\", \"B\", \"C\", \"D\", \"E\" }") {
    string string_values[] = { "A", "B", "C", "D", "E" };
    CHECK(PrepareForDisplay(string_values, 5) == "A,B,C,D,E");
    CHECK(PrepareForDisplay(string_values, 5, ' ') == "A B C D E");
    CHECK(PrepareForDisplay(string_values, 5, ':') == "A:B:C:D:E");
  }
}

TEST_CASE("HasValue()") {
  SECTION("Integers. Array: { 3, 5, 7, 9, 11 }") {
    int int_values[] = { 3, 5, 7, 9, 11 };
    CHECK(HasValue(int_values, 5, 0) == false);
    CHECK(HasValue(int_values, 5, 3) == true);
    CHECK(HasValue(int_values, 5, 11) == true);
  }

  SECTION("Doubles. Array: { 3.1, 5.2, 7.3, 9.4, 11.5 }") {
    double double_values[] = { 3.1, 5.2, 7.3, 9.4, 11.5 };
    CHECK(HasValue(double_values, 5, 0.0) == false);
    CHECK(HasValue(double_values, 5, 3.10) == true);
    CHECK(HasValue(double_values, 5, 11.50) == true);
  }

  SECTION("Strings. Array: { \"A\", \"B\", \"C\", \"D\", \"E\" }") {
    string string_values[] = { "A", "B", "C", "D", "E" };
    CHECK(HasValue(string_values, 5, string(1, 'a')) == false);
    CHECK(HasValue(string_values, 5, string(1, 'B')) == true);
    CHECK(HasValue(string_values, 5, string(1, 'E')) == true);
  }
}

TEST_CASE("ValueAt()") {
  bool error = true;
  SECTION("Integers. Array: { 3, 5, 7, 9, 11 }") {
    int int_values[] = { 3, 5, 7, 9, 11 };
    CHECK(ValueAt(int_values, 5, 0, error) == 3);
    CHECK(error == false);

    error = false;
    CHECK(ValueAt(int_values, 5, 5, error) == 0);
    CHECK(error == true);

    CHECK(ValueAt(int_values, 5, 4, error) == 11);
    CHECK(error == false);
  }

  SECTION("Doubles. Array: { 3.1, 5.2, 7.3, 9.4, 11.5 }") {
    double double_values[] = { 3.1, 5.2, 7.3, 9.4, 11.5 };
    CHECK(ValueAt(double_values, 5, 0, error) == 3.1);
    CHECK(error == false);

    error = false;
    CHECK(ValueAt(double_values, 5, 5, error) == 0);
    CHECK(error == true);

    CHECK(ValueAt(double_values, 5, 4, error) == 11.5);
    CHECK(error == false);
  }

  SECTION("Strings. Array: { \"A\", \"B\", \"C\", \"D\", \"E\" }") {
    string string_values[] = { "A", "B", "C", "D", "E" };
    CHECK(ValueAt(string_values, 5, 0, error) == "A");
    CHECK(error == false);

    error = false;
    CHECK(ValueAt(string_values, 5, 5, error) == "");
    CHECK(error == true);

    CHECK(ValueAt(string_values, 5, 4, error) == "E");
    CHECK(error == false);
  }
}

TEST_CASE("Sum()") {
  SECTION("Integers. Array: { 3, 5, 7, 9, 11 }") {
    int int_values[] = { 3, 5, 7, 9, 11 };
    CHECK(Sum(int_values, 5) == 35);
    CHECK(Sum(int_values, 1) == 3);
    CHECK(Sum(int_values, 0) == 0);
  }

  SECTION("Doubles. Array: { 3.1, 5.2, 7.3, 9.4, 11.5 }") {
    double double_values[] = { 3.1, 5.2, 7.3, 9.4, 11.5 };
    CHECK(Sum(double_values, 5) == 36.5);
    CHECK(Sum(double_values, 1) == 3.10);
    CHECK(Sum(double_values, 0) == 0.0);
  }

  SECTION("Strings. Array: { \"A\", \"B\", \"C\", \"D\", \"E\" }") {
    string string_values[] = { "A", "B", "C", "D", "E" };
    CHECK(Sum(string_values, 5) == "ABCDE");
    CHECK(Sum(string_values, 1) == "A");
    CHECK(Sum(string_values, 0) == "");
  }
}

TEST_CASE("SwapValues()") {
  bool success = false;
  SECTION("Integers. Array: { 3, 5, 7, 9, 11 }") {
    int int_values[] = { 3, 5, 7, 9, 11 };
    success = SwapValues(int_values, 5, 0, 4);
    CHECK(int_values[0] == 11);
    CHECK(int_values[1] == 5);
    CHECK(int_values[2] == 7);
    CHECK(int_values[3] == 9);
    CHECK(int_values[4] == 3);
    CHECK(success == true);

    success = false;
    success = SwapValues(int_values, 5, 1, 3);
    CHECK(int_values[0] == 11);
    CHECK(int_values[1] == 9);
    CHECK(int_values[2] == 7);
    CHECK(int_values[3] == 5);
    CHECK(int_values[4] == 3);
    CHECK(success == true);

    success = false;
    success = SwapValues(int_values, 5, 2, 2);
    CHECK(int_values[0] == 11);
    CHECK(int_values[1] == 9);
    CHECK(int_values[2] == 7);
    CHECK(int_values[3] == 5);
    CHECK(int_values[4] == 3);
    CHECK(success == true);

    success = SwapValues(int_values, 5, -2, 2);
    CHECK(int_values[0] == 11);
    CHECK(int_values[1] == 9);
    CHECK(int_values[2] == 7);
    CHECK(int_values[3] == 5);
    CHECK(int_values[4] == 3);
    CHECK(success == false);

    success = SwapValues(int_values, 5, 2, 10);
    CHECK(int_values[0] == 11);
    CHECK(int_values[1] == 9);
    CHECK(int_values[2] == 7);
    CHECK(int_values[3] == 5);
    CHECK(int_values[4] == 3);
    CHECK(success == false);
  }

  SECTION("Doubles. Array: { 3.1, 5.2, 7.3, 9.4, 11.5 }") {
    double double_values[] = { 3.1, 5.2, 7.3, 9.4, 11.5 };
    success = SwapValues(double_values, 5, 0, 4);
    CHECK(double_values[0] == 11.5);
    CHECK(double_values[1] == 5.2);
    CHECK(double_values[2] == 7.3);
    CHECK(double_values[3] == 9.4);
    CHECK(double_values[4] == 3.1);
    CHECK(success == true);

    success = false;
    success = SwapValues(double_values, 5, 1, 3);
    CHECK(double_values[0] == 11.5);
    CHECK(double_values[1] == 9.4);
    CHECK(double_values[2] == 7.3);
    CHECK(double_values[3] == 5.2);
    CHECK(double_values[4] == 3.1);
    CHECK(success == true);

    success = false;
    success = SwapValues(double_values, 5, 2, 2);
    CHECK(double_values[0] == 11.5);
    CHECK(double_values[1] == 9.4);
    CHECK(double_values[2] == 7.3);
    CHECK(double_values[3] == 5.2);
    CHECK(double_values[4] == 3.1);
    CHECK(success == true);

    success = SwapValues(double_values, 5, -2, 2);
    CHECK(double_values[0] == 11.5);
    CHECK(double_values[1] == 9.4);
    CHECK(double_values[2] == 7.3);
    CHECK(double_values[3] == 5.2);
    CHECK(double_values[4] == 3.1);
    CHECK(success == false);

    success = SwapValues(double_values, 5, 2, 10);
    CHECK(double_values[0] == 11.5);
    CHECK(double_values[1] == 9.4);
    CHECK(double_values[2] == 7.3);
    CHECK(double_values[3] == 5.2);
    CHECK(double_values[4] == 3.1);
    CHECK(success == false);
  }

  SECTION("Strings. Array: { \"A\", \"B\", \"C\", \"D\", \"E\" }") {
    string string_values[] = { "A", "B", "C", "D", "E" };
    success = SwapValues(string_values, 5, 0, 4);
    CHECK(string_values[0] == "E");
    CHECK(string_values[1] == "B");
    CHECK(string_values[2] == "C");
    CHECK(string_values[3] == "D");
    CHECK(string_values[4] == "A");
    CHECK(success == true);

    success = false;
    success = SwapValues(string_values, 5, 1, 3);
    CHECK(string_values[0] == "E");
    CHECK(string_values[1] == "D");
    CHECK(string_values[2] == "C");
    CHECK(string_values[3] == "B");
    CHECK(string_values[4] == "A");
    CHECK(success == true);

    success = false;
    success = SwapValues(string_values, 5, 2, 2);
    CHECK(string_values[0] == "E");
    CHECK(string_values[1] == "D");
    CHECK(string_values[2] == "C");
    CHECK(string_values[3] == "B");
    CHECK(string_values[4] == "A");
    CHECK(success == true);

    success = SwapValues(string_values, 5, -2, 2);
    CHECK(string_values[0] == "E");
    CHECK(string_values[1] == "D");
    CHECK(string_values[2] == "C");
    CHECK(string_values[3] == "B");
    CHECK(string_values[4] == "A");
    CHECK(success == false);

    success = SwapValues(string_values, 5, 2, 10);
    CHECK(string_values[0] == "E");
    CHECK(string_values[1] == "D");
    CHECK(string_values[2] == "C");
    CHECK(string_values[3] == "B");
    CHECK(string_values[4] == "A");
    CHECK(success == false);
  }
}
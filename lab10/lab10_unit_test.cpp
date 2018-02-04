/*
 * Name        : lab_10_unit_test.cpp
 * Author      : Luke Sathrum
 * Description : Unit test to test Lab #10 Functionality
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "lab10.h"
// Double Include to Check for Header Guards
#include "lab10.h"

TEST_CASE("Temperature Using Default Constuctor") {
  Temperature temp;

  SECTION("GetTempAsKelvin()") {
    CHECK(temp.GetTempAsKelvin() == 0);
  }

  temp.SetTempFromKelvin(50);
  SECTION("SetTempFromKelvin(50) / GetTempAsCelsius()") {
    CHECK(temp.GetTempAsKelvin() == 50);
  }

  temp.SetTempFromCelsius(5);
  SECTION("SetTempFromCelsius(5) / GetTempAsFarenheit()") {
    CHECK(temp.GetTempAsFahrenheit() >= 40.99);
    CHECK(temp.GetTempAsFahrenheit() <= 41.01);
  }

  temp.SetTempFromFahrenheit(5);
  SECTION("SetTempFromFahrenheit(5) / GetTempAsKelvin()") {
    CHECK(temp.GetTempAsKelvin() >= 258.149);
    CHECK(temp.GetTempAsKelvin() <= 258.151);
  }

  SECTION("ToString()") {
    CHECK(temp.ToString() == "258.15 Kelvin");
  }
}

TEST_CASE("Temperature Using Overloaded Constuctor w/ 1 Parameter: Temperature(50)") {
  Temperature temp(50);

  SECTION("GetTempAsFahrenheit()") {
    CHECK(temp.GetTempAsFahrenheit() >= -369.68);
    CHECK(temp.GetTempAsFahrenheit() <= -369.66);
  }

  SECTION("ToString('C')") {
    CHECK(temp.ToString('C') == "-223.15 Celsius");
  }
}

TEST_CASE("Temperature Using Overloaded Constuctor w/ 2 Parameters: Temperature(5, 'F')") {
  Temperature temp(5, 'F');

  SECTION("GetTempAsKelvin()") {
    CHECK(temp.GetTempAsKelvin() >= 258.14);
    CHECK(temp.GetTempAsFahrenheit() <= 258.16);
  }
}

TEST_CASE("Temperature Using Overloaded Constuctor w/ 2 Parameters: Temperature(5, 'f')") {
  Temperature temp(5, 'f');

  SECTION("GetTempAsKelvin()") {
    CHECK(temp.GetTempAsKelvin() >= 258.14);
    CHECK(temp.GetTempAsKelvin() <= 258.16);
  }
}

TEST_CASE("Temperature Using Overloaded Constuctor w/ 2 Parameters: Temperature(5, 'C')") {
  Temperature temp(5, 'C');

  SECTION("GetTempAsKelvin()") {
    CHECK(temp.GetTempAsKelvin() >= 278.14);
    CHECK(temp.GetTempAsKelvin() <= 278.16);
  }
}

TEST_CASE("Temperature Using Overloaded Constuctor w/ 2 Parameters: Temperature(5, 'c')") {
  Temperature temp(5, 'c');

  SECTION("GetTempAsKelvin()") {
    CHECK(temp.GetTempAsKelvin() >= 278.14);
    CHECK(temp.GetTempAsKelvin() <= 278.16);
  }
}

TEST_CASE("Temperature Using Overloaded Constuctor w/ 2 Parameters: Temperature(5, 'K')") {
  Temperature temp(5, 'K');

  SECTION("GetTempAsKelvin()") {
    CHECK(temp.GetTempAsKelvin() >= 4.99999);
    CHECK(temp.GetTempAsKelvin() <= 5.00001);
  }
}

TEST_CASE("Temperature Using Overloaded Constuctor w/ 2 Parameters: Temperature(5, '5')") {
  Temperature temp(5, '5');

  SECTION("GetTempAsKelvin()") {
    CHECK(temp.GetTempAsKelvin() >= 4.99999);
    CHECK(temp.GetTempAsKelvin() <= 5.00001);
  }

  SECTION("ToString('c')") {
    CHECK(temp.ToString('c') == "-268.15 Celsius");
  }

  SECTION("ToString('K')") {
    CHECK(temp.ToString('K') == "5.00 Kelvin");
  }

  SECTION("ToString('k')") {
    CHECK(temp.ToString('k') == "5.00 Kelvin");
  }

  SECTION("ToString('F')") {
    CHECK(temp.ToString('F') == "-450.67 Fahrenheit");
  }

  SECTION("ToString('f')") {
    CHECK(temp.ToString('f') == "-450.67 Fahrenheit");
  }

  SECTION("ToString('1')") {
    CHECK(temp.ToString('1') == "Invalid Unit");
  }
}
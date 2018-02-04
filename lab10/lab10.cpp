#include "lab10.h"

Temperature::Temperature() {
    kelvin_ = 0;
}

Temperature::Temperature(double kelvin) {
    kelvin_ = kelvin;
}

Temperature::Temperature(double temp, char unit) {
    if (unit == 'f' || unit == 'F') {
        kelvin_ = (5.0 * (temp - 32) / 9) + 273.15;
    } else if (unit == 'c' || unit == 'C') {
        kelvin_ = temp + 273.15;
    } else {
        kelvin_ = temp;
    }
}

void Temperature::SetTempFromKelvin(double kelvin) {
    kelvin_ = kelvin;
}

void Temperature::SetTempFromCelsius(double celsius) {
    kelvin_ = celsius + 273.15;
}

void Temperature::SetTempFromFahrenheit(double fahrenheit) {
    kelvin_ = (5.0 * (fahrenheit - 32) / 9) + 273.15;
}

double Temperature::GetTempAsKelvin() const {
    return kelvin_;
}

double Temperature::GetTempAsCelsius() const {
    return kelvin_ - 273.15;
}

double Temperature::GetTempAsFahrenheit() const {
    return (((kelvin_ - 273.15) * 9.0) / 5) + 32;
}

string Temperature::ToString(char unit) const {
    string reading;
    stringstream SS;
    SS << fixed << setprecision(2);
    if (unit == 'k' || unit == 'K') {
        SS << GetTempAsKelvin() << " Kelvin";
    } else if (unit == 'c' || unit == 'C') {
        SS << GetTempAsCelsius() << " Celsius";
    } else if (unit == 'f' || unit == 'F') {
        SS << GetTempAsFahrenheit() << " Fahrenheit";
    } else {
        SS << "Invalid Unit";
    }
    reading = SS.str();
    return reading;
}
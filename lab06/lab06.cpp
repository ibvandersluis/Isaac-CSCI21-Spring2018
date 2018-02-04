/*
 * Name        : lab06.cpp
 * Author      : Isaac Vander Sluis
 * Description : Working with Arrays
 * Soure       : Chris Eheler
 */

#include "lab06.h"

string PrepareForDisplay(int values[], int size, char separator) {
    string result;
    stringstream SS;
    for (int i = 0; i < size; i++) {
        if (i < size - 1) {
            SS << values[i] << separator;
        } else {
            SS << values[i];
        }
    }
    result = SS.str();
    return result;
}

bool HasValue(int values[], int size, int value) {
    int i;
    bool found = false;
    for (i = 0; (i < size && !found); i++) {
        if (values[i] == value) {
            found = true;
        }
    }
    return found;
}

int ValueAt(int values[], int size, int index, bool &error) {
    int val;
    if (index > size - 1) {
        error = true;
        return 0;
    } else {
        error = false;
        val = values[index];
    }
    return val;
}

int Sum(int values[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += values[i];
    }
    return sum;
}

bool SwapValues(int values[], int size, int index1, int index2) {
    bool swapped;
    int temp;
    if (size <= index1 || size <= index2 || index1 < 0 || index2 < 0) {
        swapped = false;
    } else {
        temp = values[index1];
        values[index1] = values[index2];
        values[index2] = temp;
        swapped = true;
    }
    return swapped;
}
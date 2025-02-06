#pragma once 
#include <iostream>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>

#define INPUT_LINE(in,str) getline(in>>std::ws,str);\
cerr << str << endl;

template <typename T>
T GetCorrectNumber(T minValue, T maxValue) {
    T value;
    while (!(std::cin >> value) || value < minValue || value > maxValue) {
        std::cout << "Invalid input. Please try again: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    return value;
}

template <typename T>
T GetCorrectBool() {
    bool value;
    while (!(std::cin >> value) || (value != 0 && value != 1)) {
        std::cout << "Invalid input. Please enter 0 or 1: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    return value;
}
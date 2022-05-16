// Copyright (c) 2022 Alex De Meo All rights reserved
//
// Created By: Alex De Meo
// Date: 04s//22
// Description:
#include <cmath>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stod;
using std::stoi;
using std::stof;

// this function rounds the inputted decimal number to the specified decimal
// place. Takes the parameter num by reference
void RoundDecimal(double &num, int place) {
    // does a different calculation depending on if the number is negative
    if (num >= 0) {
        num = num * pow(10, place);
        num += 0.5;
        num = static_cast<int>(num);
        num = num / pow(10, place);
    } else {
        num = num * pow(10, place);
        num -= 0.5;
        num = static_cast<int>(num);
        num = num / pow(10, place);
    }
}

int main() {
    // getting user input
    string uNum, uPlace;
    cout << "Enter a decimal number: ";
    cin >> uNum;

    cout << "How many decimal places do you need: ";
    cin >> uPlace;

    try {
        float placeFlt = stof(uPlace);
        double dNum = stod(uNum);
        // checking to make sure place is a whole number
        if (placeFlt == static_cast<int>(placeFlt) && placeFlt >= 0) {
            // calling funtion
            RoundDecimal(dNum, placeFlt);

            cout << endl << "Your rounded number is..." << endl << endl << dNum;
        } else {
            cout << "Place can't be a decimal or negative";
        }
    } catch (...) {
        cout << "Numbers were inputted incorrectly";
    }
}

//  ===========================================================================
//  File    :   main.cpp
//  What    :   Calculate Kaprekars Constant
//  Who     :   David Means <W1T3H4T@gmail.com>
//  ===========================================================================

#include <iostream>
#include "Kaprekars.h"


int main() {
    int inputNumber;
    std::cout << "Enter a 4-digit number: ";
    std::cin >> inputNumber;

    KaprekarsCalc k(inputNumber);

    if (k.isValidInput()) {
        int kaprekarConstant = k.calculate();
        std::cout << "Kaprekar's Constant for " << inputNumber << " is: " << kaprekarConstant << std::endl;
    }

    return 0;
}

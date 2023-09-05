//  ===========================================================================
//  File    :   Kaprekars.cpp
//  Function:   Describe Kaprekar's Constant Calculator
//  Who     :   David Means <W1T3H4T@gmail.com>
//  ===========================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "Kaprekars.h"

KaprekarsCalc::KaprekarsCalc(int number) : number(number) {
    checkValidInput();
}

bool KaprekarsCalc::isValidInput() const { 
    return validInput;
}

bool KaprekarsCalc::checkValidInput() { 

    if (number < 1000 || number > 9999) {
        std::cerr << "Invalid input. Please provide a 4-digit number" << std::endl
		          << "with at least two distinct digits." << std::endl;
        validInput = false;
    } 
    else { 
        validInput = hasAtLeastTwoDistinctDigits();
    }
    return validInput;
}

int KaprekarsCalc::calculate() const {
	if (!validInput) {
		return -1; // Return an invalid result if the input is not valid.
	}

	int kaprekarConstant = -1;
	int num = number;

	while (kaprekarConstant != 6174) {
   		std::vector<int> digits;
         
        // Extract digits from the number and store them in the vector.
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }

        // Ensure there are 4 digits.
        while (digits.size() < 4) {
            digits.push_back(0);
        }

        // Sort the digits in descending and ascending order.
        std::sort(digits.begin(), digits.end(), std::greater<int>());
        int max_num = 0, min_num = 0;

        for (int digit : digits) {
            max_num = max_num * 10 + digit;
        }

        std::sort(digits.begin(), digits.end());
        for (int digit : digits) {
            min_num = min_num * 10 + digit;
        }

        // Calculate the Kaprekar's constant.
        kaprekarConstant = max_num - min_num;

        // Display intermediary values.
        std::cout << max_num << " - " << min_num << " = " << kaprekarConstant << std::endl;

        num = kaprekarConstant; // Continue with the new number.
    }

    return kaprekarConstant;
}

bool KaprekarsCalc::hasAtLeastTwoDistinctDigits() const {
    std::set<int> uniqueDigits;
	int num = number;

    while (num > 0) {
        int digit = num % 10;
        uniqueDigits.insert(digit);
        num /= 10;
    }
    return uniqueDigits.size() >= 2; // Ensure at least two distinct digits.
}


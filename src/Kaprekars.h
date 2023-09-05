//  ===========================================================================
//  File    :   Kaprekars.h
//  Function:   Describe Kaprekar's Constant Calculator
//  Who     :   David Means <W1T3H4T@gmail.com>
//  ===========================================================================


class KaprekarsCalc {
public:
    KaprekarsCalc(int number);
    ~KaprekarsCalc() { };

    bool isValidInput() const;
    int calculate() const;

private:
	bool checkValidInput();
    bool validateNumber() const;
	bool hasAtLeastTwoDistinctDigits() const;

    int number;
    bool validInput;
};

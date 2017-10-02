#ifndef CALCULATOR_RAWVALUE_HPP
#define CALCULATOR_RAWVALUE_HPP
#include <iostream>

using namespace std;

namespace Operators{
    static const string openBracket = "(";
    static const string closeBracket = ")";
    static const string add = "+";
    static const string sub = "-";
    static const string mult = "*";
    static const string div = "/";
    static const string pow = "^";
    static const string root = "root";
    static const string space = " ";
}

class RawValue
{
public:
    RawValue(const string value, const bool number)
    {
        this->value = value;
        this->number = number;
    }

    RawValue(double value)
    {
        number = true;
        this->value = to_string(value);
    }

    bool isNumber() const
    {
        return number;
    }

    bool isOperator() const
    {
        return !number;
    }

    bool isOpeningBracket() const
    {
        return value == Operators::openBracket;
    }

    bool isClosingBracket() const
    {
        return value == Operators::closeBracket;
    }

    bool isMultiplication() const
    {
        return value == Operators::mult;
    }

    bool isDivision() const
    {
        return value == Operators::div;
    }

    bool isAddition() const
    {
        return value == Operators::add;
    }

    bool isSubstitution() const
    {
        return value == Operators::sub;
    }

    bool isRoot() const
    {
        return value == Operators::root;
    }

    bool isPow() const
    {
        return value == Operators::pow;
    }

    string getValue() const
    {
        return value;
    }

private:
    bool number;
    string value;
};
#endif //CALCULATOR_RAWVALUE_HPP

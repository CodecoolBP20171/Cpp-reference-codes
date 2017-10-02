#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H
#include <iostream>
#include <list>
#include <vector>
#include "RawValue.hpp"

using namespace std;

class Calculator
{
public:
    double evaluate(const string& formula);

private:
    string formula;
    list<RawValue> values;
    int bracketCounter; // for error handling when a bracket is missing

    bool isNumber(char c);
    int parseFormula();
    void printErrorFoundDuringParsing(int pos);
    double calculate();
    void solveBrackets();
    bool knownOperand(const string& op);
    bool storeValue(const string& val, const bool isNumber);
    bool valueValid(const string& val, const bool isNumber);
    bool countBrackets(const string& val, const bool isNumber);
    bool evaluateOperations(list<RawValue>::iterator start,
                            list<RawValue>::iterator end);
    bool solveAllExpressions(vector<string> operands,
                             list<RawValue>::iterator start,
                             list<RawValue>::iterator end);
    bool operandIsThere(const vector<string>& opList, const string& op);
    bool solveOneExpression(list<RawValue>::iterator operand);
    bool convertToNumber(const RawValue& value, double& num);
    double solveOperation(const double num1, const RawValue& operand, const double num2);
    double getResult();
    void printValues(list<RawValue>::iterator start,
                     list<RawValue>::iterator end); // print to standard output, for debug purposes
};

#endif //CALCULATOR_CALCULATOR_H

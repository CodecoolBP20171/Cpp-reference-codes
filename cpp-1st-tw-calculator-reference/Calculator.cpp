#include "Calculator.h"
#include <cmath>

double Calculator::evaluate(const string& formula)
{
    this->formula = formula;

    int error = parseFormula();
    if(0 != error){
        printErrorFoundDuringParsing(error);
        return 0;
    }
    return calculate();
}

int Calculator::parseFormula()
{
    string value;
    int lengthOfStr = formula.length();
    bool processingANumber = false;
    bracketCounter = 0;

    for(int i = 0; i < lengthOfStr; ++i){
        if(knownOperand(value)){
            if(!storeValue(value, processingANumber)){
                return i - value.length();
            }
            value.clear();
        }

        if(isNumber(formula[i])){
            processingANumber = true;
        }else if(processingANumber){
            if(!storeValue(value, processingANumber)){
                return i - value.length();
            }
            value.clear();
            processingANumber = false;
        }

        value += formula[i];
    }
    // store the last value in the vector
    if(!value.empty()){
        if(!storeValue(value, processingANumber)){
            return lengthOfStr - 1;
        }
    }
    // error handling - missing closing bracket
    if(0 != bracketCounter){
        cout << "Missing closing bracket." << endl;
        return lengthOfStr;
    }
    return 0;
}

void Calculator::printErrorFoundDuringParsing(int pos)
{
    cout << formula << endl;
    string empty(pos, ' '); // make a string out of enough spaces
    cout << empty << "|" << endl;
}

double Calculator::calculate()
{
    // insert extra brackets because solveBrackets() needs brackets
    values.insert(values.begin(), RawValue(Operators::openBracket, false));
    values.insert(values.end(), RawValue(Operators::closeBracket, false));

    solveBrackets();
    return getResult();
}

void Calculator::solveBrackets()
{
    bool bracketFound;
    do {
        bracketFound = false;
        auto start = values.end();
        auto it = values.begin();

        while(it != values.end()){
            if(it->isOpeningBracket()){
                start = it;
            }else if( it->isClosingBracket() &&
                      start != values.end() )
            {
                if(!evaluateOperations(start, it)){
                    return;
                }
                // evaluated operations deleted, delete the brackets
                values.erase(start);
                values.erase(it);
                bracketFound = true;
                break;
            }
            ++it;
        }
    }while(bracketFound);
}

bool Calculator::isNumber(char c)
{
    if( '0' <= c &&
        '9' >= c ||
        '.' == c )
    {
        return true;
    }
    return false;
}

bool Calculator::knownOperand(const string& op)
{
    if( op == Operators::openBracket || op == Operators::closeBracket ||
        op == Operators::add || op == Operators::sub ||
        op == Operators::mult || op == Operators::div ||
        op == Operators::pow || op == Operators::root ||
        op == Operators::space ) // space is here to just be able to ignore it
    {
        return true;
    }
    return false;
}

bool Calculator::storeValue(const string& val, const bool isNumber)
{
    if( !val.empty() &&
         val != Operators::space ) // ignore space characters
    {
        if( !valueValid(val, isNumber) ||
            !countBrackets(val, isNumber) )
        {
            return false;
        }
        values.push_back(RawValue(val, isNumber));
    }
    return true;
}

bool Calculator::valueValid(const string& val, const bool isNumber)
{
    if(isNumber){
        try{
            stod(val);
        }catch(invalid_argument e){
            cout << "Invalid argument" << endl;
            return false;
        }catch(out_of_range e){
            cout << "out of range" << endl;
            return false;
        }
    }else{
        if(!knownOperand(val)){
            cout << "invalid operand" << endl;
            return false;
        }
    }
    return true;
}

bool Calculator::countBrackets(const string& val, const bool isNumber)
{
    if(!isNumber){
        if(val == Operators::openBracket) ++bracketCounter;
        if(val == Operators::closeBracket) --bracketCounter;
    }

    if(0 > bracketCounter){
        cout << "Missing starting bracket." << endl;
        return false;
    }
    return true;
}

bool Calculator::evaluateOperations(list<RawValue>::iterator start,
                                    list<RawValue>::iterator end)
{
    vector<string> operands = {Operators::root, Operators::pow};
    if(!solveAllExpressions(operands, start, end)){
        return false;
    }

    operands = {Operators::mult, Operators::div};
    if(!solveAllExpressions(operands, start, end)){
        return false;
    }

    operands = {Operators::add, Operators::sub};
    if(!solveAllExpressions(operands, start, end)){
        return false;
    }
    return true;
}

bool Calculator::solveAllExpressions(vector<string> operands,
                                     list<RawValue>::iterator start,
                                     list<RawValue>::iterator end)
{
    auto it = start;
    while( it != end &&
           it != values.end() )
    {
        if(operandIsThere(operands, it->getValue())){
            if(!solveOneExpression(it)){
                return false;
            }
            it = start;
            continue;
        }
        ++it;
    }
    return true;
}

bool Calculator::operandIsThere(const vector<string>& opList, const string& op)
{
    int numOfOps = opList.size() - 1;
    while(0 <= numOfOps){
        if(op == opList[numOfOps]){
            return true;
        }
        --numOfOps;
    }
    return false;

}

bool Calculator::solveOneExpression(list<RawValue>::iterator operand)
{
    if( operand == values.begin() ||
        operand == values.end() )
    {
        cout << "Invalid formula!" << endl;
        return false;
    }

    double result = 0;
    double num1;
    if(!convertToNumber(*prev(operand), num1)){
        return false;
    }

    double num2;
    if(!convertToNumber(*next(operand), num2)){
        return false;
    }

    result = solveOperation(num1, *operand, num2);
    // delete values what we just used and insert the outcome into the formula
    auto num = next(next(operand));
    values.erase(prev(operand), num);
    values.insert(num, RawValue(result));
    return true;
}

double Calculator::solveOperation(const double num1, const RawValue& operand, const double num2)
{
    double result = 0;
    if(operand.isAddition()) result = num1 + num2;
    else if(operand.isSubstitution()) result = num1 - num2;
    else if(operand.isMultiplication()) result = num1 * num2;
    else if(operand.isDivision()) result = num1 / num2;
    else if(operand.isRoot()) result = pow(num2, 1.0/num1);
    else if(operand.isPow()) result = pow(num1, num2);
    return result;
}

bool Calculator::convertToNumber(const RawValue& value, double& num)
{
    if(!value.isNumber()){
        cout << "Invalid formula!" << endl;
        return false;
    }
    num = stod(value.getValue());
    return true;
}

double Calculator::getResult()
{
    double result = 0;
    if(1 == values.size()){
        result = stod(values.begin()->getValue());
    }else{
        cout << "Can't finish evaluation. Invalid formula? Remaining data:" << endl;
        printValues(values.begin(), values.end());
    }
    return result;
}

void Calculator::printValues(list<RawValue>::iterator start,
                             list<RawValue>::iterator end)
{
    cout << "\t";
         list<RawValue>::iterator it = start;
    while(it != end &&
          it != values.end())
    {
        cout << "  " << it->getValue();
        ++it;
    }
    cout << endl;
}
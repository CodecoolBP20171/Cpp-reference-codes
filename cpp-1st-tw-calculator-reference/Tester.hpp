#ifndef CALCULATOR_TESTER_HPP
#define CALCULATOR_TESTER_HPP
#include "Calculator.h"

class Tester {
public:
    void run()
    {
        failedTests = 0;
        // Level 0
        TestAddition();
        TestSubtraction();
        TestMultiplication();
        TestDivision();
        TestFormulaWithSpaces();
        // Level 1
        TestRoot();
        TestPow();
        TestFractional();
        TestComplicatedFormula_noBrackets();
        TestComplicatedFormula_root();
        TestComplicatedFormula_rootAndPower();
        TestErroneousFormula_rootTypoNoBrackets();
        // Boss fight
        TestComplicatedFormula_brackets();
        TestComplicatedFormula_bracketsBeforeRoot();
        TestComplicatedFormula_bracketsAfterRoot();
        TestErroneousFormula_missingOpeningBracket();
        TestErroneousFormula_missingClosingBracket();
        TestErroneousFormula_missing_param();
        evaluateTestOutcomes();
    }

private:
    int failedTests;

    void TestAddition()
    {
        Calculator c;
        double result = c.evaluate("10+2");
        checkResult(12, result);
    }

    void TestSubtraction()
    {
        Calculator c;
        double result = c.evaluate("10-2");
        checkResult(8, result);
    }

    void TestMultiplication()
    {
        Calculator c;
        double result = c.evaluate("3*2");
        checkResult(6, result);
    }

    void TestDivision()
    {
        Calculator c;
        double result = c.evaluate("10/3");
        checkResult(3.3, result, 0.05);
    }
    void TestFormulaWithSpaces()
    {
        Calculator c;
        double result = c.evaluate(" 10 / 3*2 +   8 ");
        checkResult(14.7, result, 0.05);
    }

    void TestPow()
    {
        Calculator c;
        double result = c.evaluate("10^3");
        checkResult(1000, result);
    }

    void TestRoot()
    {
        Calculator c;
        double result = c.evaluate("2root25");
        checkResult(5, result);
    }

    void TestFractional()
    {
        Calculator c;
        double result = c.evaluate("2.3+2.7");
        checkResult(5, result);
    }

    void TestComplicatedFormula_noBrackets()
    {
        Calculator c;
        double result = c.evaluate("12+20*3-50/2+3");
        checkResult(50, result);
    }

    void TestComplicatedFormula_root()
    {
        Calculator c;
        double result = c.evaluate("12+2*2root25+3");
        checkResult(25, result);
    }

    void TestComplicatedFormula_rootAndPower()
    {
        Calculator c;
        double result = c.evaluate("12+2*2root25+10^4+6-3");
        checkResult(10025, result);
    }

    void TestErroneousFormula_rootTypoNoBrackets()
    {
        Calculator c;
        // calculator prints an error msg and returns with 0
        double result = c.evaluate("12+2*2rwot25+10^4+6-3");
        checkResult(0, result);
    }

    void TestComplicatedFormula_brackets()
    {
        Calculator c;
        double result = c.evaluate("2root(22+(33-2root25+14)*2+(5-2))");
        checkResult(10.4403d, result, 0.01d);
    }

    void TestComplicatedFormula_bracketsBeforeRoot()
    {
        Calculator c;
        double result = c.evaluate("((2+2)*2-6)root25+10^4+6-3");
        checkResult(10008, result);
    }

    void TestComplicatedFormula_bracketsAfterRoot()
    {
        Calculator c;
        double result = c.evaluate("2root((10-5)*4/(2+80))");
        checkResult(0.493, result, 0.01);
    }

    void TestErroneousFormula_missingOpeningBracket()
    {
        Calculator c;
        double result = c.evaluate("(2+2)*2-6)root25+10^4+6-3");
        checkResult(0, result);
    }

    void TestErroneousFormula_missingClosingBracket()
    {
        Calculator c;
        double result = c.evaluate("((2+2)*2-6root25+10^4+6-3");
        checkResult(0, result);
    }

    void TestErroneousFormula_missing_param()
    {
        Calculator c;
        double result = c.evaluate("12+2*root25+10^4+6-3");
        checkResult(0, result);
    }

    void checkResult(const double expected, const double actual, const double threshold = 0.0d)
    {
        if( actual >= expected - threshold &&
            actual <= expected + threshold )
        {
            cout << "Test ran OK." << endl;
        }else{
            cout << "Invalid result! Expected: " << expected << " actual: " << actual << endl;
            ++failedTests;
        }
    }

    void evaluateTestOutcomes()
    {
        if(0 != failedTests){
            cout << failedTests << " tests failed." << endl;
        }else{
            cout << "All tests passed!" << endl;
        }
    }
};


#endif //CALCULATOR_TESTER_HPP

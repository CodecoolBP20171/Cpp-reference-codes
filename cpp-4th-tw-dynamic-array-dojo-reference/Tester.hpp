//
// Created by László Molnár on 2017-11-7.
//

#ifndef CPP_DYNAMIC_ARRAY_DOJO_TESTER_HPP
#define CPP_DYNAMIC_ARRAY_DOJO_TESTER_HPP
#ifndef CALCULATOR_TESTER_HPP
#define CALCULATOR_TESTER_HPP

#include <iostream>
#include "DynamicArray.h"
#include "InvalidArrayIndex.hpp"

class Tester {
public:
    void run()
    {
        failedTests = 0;
        TestArrayCreation();
        TestArrayResize();
        TestArrayGet();
        TestArraySet();
        TestArrayGetException();
        TestArraySetException();
        TestArrayGetWithBraces();
        TestArraySetWithBraces();
        TestArrayClear();
        TestArrayClearEmptyArray();
        // [] doesn't check boundaries so setting/getting with invalid [index] is undefined
        // behaviour -> don't know how to test it..
        evaluateTestOutcomes();
    }

private:
    int failedTests;


    void TestArrayCreation()
    {
        DynamicArray array;
        for(int i = 0; i < 10; ++i){
            array.push_back(i);
        }
    }

    void TestArrayResize()
    {
        DynamicArray array;
        for(int i = 0; i < 500; ++i){
            array.push_back(i);
        }
    }

    void TestArrayGet()
    {
        DynamicArray array;
        for(int i = 0; i < 500; ++i){
            array.push_back(i);
        }
        checkResult(11, array.get(11));
    }

    void TestArraySet()
    {
        DynamicArray array;
        for(int i = 0; i < 500; ++i){
            array.push_back(i);
        }
        array.set(11, 20);
        checkResult(20, array.get(11));
    }
    void TestArrayGetException()
    {
        DynamicArray array;
        for(int i = 0; i < 50; ++i){
            array.push_back(i);
        }
        try{
            array.get(52);
        }catch(InvalidArrayIndex e){
        }
    }

    void TestArraySetException()
    {
        DynamicArray array;
        for(int i = 0; i < 50; ++i){
            array.push_back(i);
        }
        try{
            array.set(52, 10);
        }catch(InvalidArrayIndex e){
        }
    }

    void TestArrayGetWithBraces()
    {
        DynamicArray array;
        for(int i = 0; i < 50; ++i){
            array.push_back(i);
        }
        checkResult(33, array[33]);
    }

    void TestArraySetWithBraces()
    {
        DynamicArray array;
        for(int i = 0; i < 10; ++i){
            array.push_back(0);
        }

        for(int i = 0; i < array.size(); ++i){
            array[i] = i;
        }
        checkResult(array.size() - 1, array[array.size() - 1]);
    }

    void TestArrayClear() {
        DynamicArray array;
        for (int i = 0; i < array.size(); ++i) {
            array.push_back(i);
        }
        array.clear();
        checkResult(0, array.size());
    }
    void TestArrayClearEmptyArray()
    {
        DynamicArray array;
        array.clear();
        // should not throw
        checkResult(0, array.size());
    }


    void checkResult(const double expected, const double actual, const double threshold = 0.0d)
    {
        if( actual >= expected - threshold &&
            actual <= expected + threshold )
        {
            std::cout << "Test ran OK." << std::endl;
        }else{
            std::cout << "Invalid result! Expected: " << expected << " actual: " << actual << std::endl;
            ++failedTests;
        }
    }

    void evaluateTestOutcomes()
    {
        if(0 != failedTests){
            std::cout << failedTests << " tests failed." << std::endl;
        }else{
            std::cout << "All tests passed!" << std::endl;
        }
    }
};


#endif //CALCULATOR_TESTER_HPP

#endif //CPP_DYNAMIC_ARRAY_DOJO_TESTER_HPP

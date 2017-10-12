#pragma once
#include <new>
#include <iostream>
#include "StackExceptions.hpp"

using namespace std;

class Stack
{
public:
    Stack(const unsigned size);
    virtual ~Stack();
    void push(const int data);
    int pop();
    size_t size() const { return endPointer - stack; }
    int peek() const;

private:
    int* stack;
    int* stackPointer;
    int* endPointer;
};

inline
Stack::Stack(const unsigned size)
{
    stack = nullptr;
    try {
        stack = new int[size];
        stackPointer = stack;
        endPointer = stackPointer + size;
    }
    catch (bad_alloc&) {
        stackPointer = nullptr;
        endPointer = nullptr;
    }
}

inline
Stack::~Stack()
{
    delete[] stack;
}

inline
void Stack::push(const int data)
{
    if (stackPointer < endPointer) {
        *stackPointer = data;
        ++stackPointer;
        return;
    }
    throw StackOverflowException();
}

inline
int Stack::pop()
{
    if (stackPointer > stack) {
        return *--stackPointer;
    }
    throw StackUnderflowException();
}

inline
int Stack::peek() const
{
    if (stackPointer > stack) {
        return *(stackPointer - 1);
    }
    throw StackEmptyException();
}

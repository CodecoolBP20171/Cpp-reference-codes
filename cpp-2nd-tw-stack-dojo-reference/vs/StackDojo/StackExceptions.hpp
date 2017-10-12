#pragma once
#include <exception>

class StackOverflowException : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "Stack is full! It would overflow I let you do this!";
    }
};

class StackUnderflowException : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "Stack is empty! It would underflow I let you do this!";
    }
};

class StackEmptyException : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "Stack is empty!";
    }
};


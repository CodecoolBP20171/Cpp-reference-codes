#pragma once
#include <exception>

class IllegalArgumentException : public std::exception
{
public:
  virtual const char* what() const noexcept
  {
    return "Element not in the tree!";
  }
};

class ArgumentException : public std::exception
{
public:
  virtual const char* what() const noexcept
  {
    return "Element already in the tree!";
  }
};

//
// Created by László Molnár on 2017-11-7.
//

#ifndef CPP_DYNAMIC_ARRAY_DOJO_INVALIDARRAYINDEX_HPP
#define CPP_DYNAMIC_ARRAY_DOJO_INVALIDARRAYINDEX_HPP
#include <exception>

class InvalidArrayIndex : public std::exception
{
public:
    virtual const char* what() const noexcept
    {
        return "Invalid array index!";
    }
};

#endif //CPP_DYNAMIC_ARRAY_DOJO_INVALIDARRAYINDEX_HPP

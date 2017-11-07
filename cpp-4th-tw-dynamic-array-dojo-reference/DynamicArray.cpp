//
// Created by László Molnár on 2017-11-7.
//
#include <iostream>
#include <utility>
#include "DynamicArray.h"
#include "InvalidArrayIndex.hpp"

void DynamicArray::push_back(const int value)
{
    array[counter++] = value;
    if(counter >= capacity){
        resize();
    }
}

int DynamicArray::get(const unsigned index) const
{
    if(index < counter) return array[index];
    throw InvalidArrayIndex();
}

void DynamicArray::set(const unsigned index, const int value)
{
    if(index < counter){
        array[index] = value;
        return;
    }
    throw InvalidArrayIndex();
}

void DynamicArray::resize()
{
    int newCapacity = capacity * 1.5;
    std::unique_ptr<int[]> newArray(new int[newCapacity]);

    for(unsigned i = 0; i < capacity; ++i){
        newArray[i] = array[i];
    }

    capacity = newCapacity;
    array = std::move(newArray);
}
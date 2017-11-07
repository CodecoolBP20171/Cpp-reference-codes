//
// Created by László Molnár on 2017-11-7.
//

#ifndef CPP_DYNAMIC_ARRAY_DOJO_DYNAMICARRAY_H
#define CPP_DYNAMIC_ARRAY_DOJO_DYNAMICARRAY_H
#include <memory>

class DynamicArray {
public:
    DynamicArray() : capacity(10), counter(0), array(new int[capacity]) {}
    void push_back(const int value);
    int get(const unsigned index) const;
    void set(const unsigned index, const int value);
    int operator[](unsigned index) const { return array[index]; } // no boundary checking like in std::vector
    int& operator[](unsigned index) { return array[index]; } // this one is for the ability of setting new value
    int size() const { return counter; } // needed to test [] better
    void clear() { array.reset(new int[capacity]); counter = 0;}

private:
    int capacity;
    int counter;
    std::unique_ptr<int[]> array;

    void resize();
};


#endif //CPP_DYNAMIC_ARRAY_DOJO_DYNAMICARRAY_H

//
// Created by László Molnár on 2017-10-3.
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_AREA_HPP
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_AREA_HPP
#include <string>

using namespace std;

class Area
{
public:
    Area(const string& description) : description(description) {}
    string getDescription()const {return description;}

private:
    string description;
};
#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_AREA_HPP

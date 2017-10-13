
#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_ITEM_HPP
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_ITEM_HPP
#include <string>

using namespace std;

class Item
{
public:
    Item(const string& name, const string& description) : name(name), description(description){}
    string getName() const {return name;}

private:
    string name;
    string description;

};
#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_ITEM_HPP

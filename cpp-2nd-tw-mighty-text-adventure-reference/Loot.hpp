//
// Created by László Molnár on 2017-10-4.
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_LOOT_HPP
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_LOOT_HPP

#include "Item.hpp"

class Loot
{
public:
    Loot(const Item* item, const int quantity) : item(item), quantity(quantity) {}
    string getLootInfo() const;

private:
    const Item* item;
    int quantity;
};

inline
string Loot::getLootInfo() const
{
    string info;
    info = to_string(quantity) + "\t"; //TODO: newer tab solution?
    info += item->getName();
    return info;
}
#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_LOOT_HPP

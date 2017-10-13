//
// Created by László Molnár on 2017-10-2.
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_ROOM_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_ROOM_H

#include <string>
#include <vector>
#include "Area.hpp"
#include "Commands.hpp"
#include "Loot.hpp"

using namespace std;

class Room
{
public:
    Room(const Area* area);
    void addConnection(Room* room, const Direction direction);
    void addLoot(const Loot& loot){this->loot.push_back(loot);}
    Room* getRoom(const Direction direction) const;
    string getDescription() const {return area->getDescription();}
    string getLootInfo() const;
    bool isLootHere() const {return !loot.empty();}
    void removeLoot(const string& name, const int quantity){/*TODO: implement*/}

private:
    const Area* area;
    Room* connections[4];
    vector<Loot> loot;
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_ROOM_H

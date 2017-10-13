//
// Created by László Molnár on 2017-10-2.
//

#include "Room.h"

Room::Room(const Area* area)
{
    this->area = area;
    for(Room*& e : connections){
        e = nullptr;
    }
}

void Room::addConnection(Room* room, const Direction direction)
{
    if(direction < Direction::INVALID_DIR){
        connections[direction] = room;
    }
}

Room* Room::getRoom(const Direction direction) const
{
    if(Direction::INVALID_DIR > direction){
        return connections[direction];
    }
    return nullptr;
}

string Room::getLootInfo() const
{
    string info;
    for(const Loot& e : loot){
        info += "  " + e.getLootInfo() + "\n";
    }
    return info;
}
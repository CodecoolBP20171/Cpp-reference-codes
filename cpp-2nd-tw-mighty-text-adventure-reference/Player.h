//
// Created by László Molnár on 2017-10-3.
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_PLAYER_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_PLAYER_H
#include "Room.h"

//using namespace std;

class Player {
public:
    void setStartingRoom(Room* room){currentRoom = room;}
    string getRoomDescription();
    string getLootInRoomInfo();
    string getAvailableDirections();
    bool move(const Direction direction);
    bool isLootInTheRoom(){return currentRoom->isLootHere();}
    bool isFinished();

private:
    Room* currentRoom;

};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_PLAYER_H

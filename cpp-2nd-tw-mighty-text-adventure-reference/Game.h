//
// Created by László Molnár on 2017-10-3.
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_GAME_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_GAME_H
#include "Room.h"
#include "Player.h"
#include "Item.hpp"

class Game {
public:
    void init();
    void run();

private:
    vector<Area> areas; // areas has only non-changeable information
    vector<Item> items; // item templates has only non-changeable information
    vector<Room> rooms; // rooms are connected to each other, containing changeable info
    Player player;

    void loadAreas();
    void loadRooms();
    void loadItems();
    void buildRoomConnections();
    void addLootToRooms();
    bool step();
    void printDescription();
    void printValidCommands();
    void printItemsOnGround();
    string getInputFromUser();
    void handleInput(const string& input);
    Direction inputToDirection(const string& input);
    Action inputToAction(const string& input);
    void printEnding();
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_GAME_H

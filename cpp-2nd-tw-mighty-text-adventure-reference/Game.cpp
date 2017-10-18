//
// Created by László Molnár on 2017-10-3.
//
#include <iostream>
#include <algorithm>
#include "Game.h"
#include "Loot.hpp"

void Game::init()
{
    loadAreas();
    loadRooms();
    loadItems();
    buildRoomConnections();
    addLootToRooms();
    player.setStartingRoom(&rooms[0]);
}

void Game::loadAreas()
{
    areas.emplace_back("start room");
    areas.emplace_back("room 1");
    areas.emplace_back("room 2");
    areas.emplace_back("room 3");
    areas.emplace_back("room 4");
    areas.emplace_back("room 5");
    areas.emplace_back("room 6");
}

void Game::loadRooms()
{
    rooms.emplace_back(&areas[0]);
    rooms.emplace_back(&areas[1]);
    rooms.emplace_back(&areas[2]);
    rooms.emplace_back(&areas[3]);
    rooms.emplace_back(&areas[4]);
    rooms.emplace_back(&areas[5]);
    rooms.emplace_back(&areas[6]);
}

void Game::loadItems()
{
    items.emplace_back("Rock", "Just a rock but it ROCKS!");
    items.emplace_back("Rusty Key", "It should open a rusty door probably.");
    items.emplace_back("Torch", "Come on baby light my fire!");
    items.emplace_back("Cheek bone", "Some body may miss this..");
}

void Game::buildRoomConnections()
{
/*
  6
  |
3-4-5
|   |
1-0-2
 */
    rooms[0].addConnection(&rooms[1], Direction::WEST);
    rooms[0].addConnection(&rooms[2], Direction::EAST);

    rooms[1].addConnection(&rooms[0], Direction::EAST);
    rooms[1].addConnection(&rooms[3], Direction::NORTH);

    rooms[2].addConnection(&rooms[0], Direction::WEST);
    rooms[2].addConnection(&rooms[5], Direction::NORTH);

    rooms[3].addConnection(&rooms[1], Direction::SOUTH);
    rooms[3].addConnection(&rooms[4], Direction::EAST);

    rooms[4].addConnection(&rooms[5], Direction::EAST);
    rooms[4].addConnection(&rooms[6], Direction::NORTH);

    rooms[5].addConnection(&rooms[4], Direction::WEST);
    rooms[5].addConnection(&rooms[2], Direction::SOUTH);
}

void Game::addLootToRooms()
{
    rooms[0].addLoot(Loot(&items[3], 2));
    rooms[2].addLoot(Loot(&items[0], 2));
    rooms[2].addLoot(Loot(&items[1], 1));
    rooms[5].addLoot(Loot(&items[2], 1));
    rooms[5].addLoot(Loot(&items[3], 1));
}

void Game::run()
{
    while(!step()){}
}

bool Game::step()
{
    printDescription();
    string input = getInputFromUser();
    handleInput(input);

    if(!player.isFinished()){
        return false;
    }
    printEnding();
    return true;
}

void Game::printDescription()
{
    cout << player.getRoomDescription() << endl;
    if(player.isLootInTheRoom()){
        cout << "There are items in the room." << endl;
    }
    cout << "You can go to " << player.getAvailableDirections() << "." << endl;
    cout << "> ";
}

void Game::printValidCommands()
{
    for(const auto& commandInfo : Commands){
        cout << commandInfo.first << ":\t";
        for(int i = 0; i < commandInfo.second.size(); ++i){
            cout << commandInfo.second[i];
            if(i != commandInfo.second.size() - 1) cout << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

string Game::getInputFromUser()
{
    string input;
    getline(cin, input);
    // every command starts with a Capital letter followed by lowercase letters
    transform(input.begin(), input.begin() + 1, input.begin(), ::toupper);
    transform(input.begin() + 1, input.end(), input.begin() + 1, ::tolower);
    return input;
}

void Game::handleInput(const string &input)
{
    Direction direction = inputToDirection(input);
    if(Direction::INVALID_DIR != direction){
        if(!player.move(direction)){
            cout << "Can't go that way." << endl;
        }
        return;
    }

    Action action = inputToAction(input);
    if(Action::INVALID_ACT != action){
        if(Action::HELP == action){
            printValidCommands();
        }
        if(Action::LIST_ITEMS == action){
            printItemsOnGround();
        }
        return;
    }
    cout << "Invalid command. Get help by typing 'h' or 'help' without apostrophe." << endl;
}

Direction Game::inputToDirection(const string& input)
{
    Direction direction = Direction::INVALID_DIR;

    if(DirectionStr::North.end() != std::find(DirectionStr::North.begin(),
                                              DirectionStr::North.end(), input))
    {
        direction = Direction::NORTH;
    }else if(DirectionStr::South.end() != std::find(DirectionStr::South.begin(),
                                                    DirectionStr::South.end(), input))
    {
        direction = Direction::SOUTH;
    }else if(DirectionStr::West.end() != std::find(DirectionStr::West.begin(),
                                                   DirectionStr::West.end(), input))
    {
        direction = Direction::WEST;
    }else if(DirectionStr::East.end() != std::find(DirectionStr::East.begin(),
                                                   DirectionStr::East.end(), input))
    {
        direction = Direction::EAST;
    }

    return direction;
}

Action Game::inputToAction(const string &input)
{
    Action action = Action::INVALID_ACT;
    if(ActionStr::Help.end() != std::find(ActionStr::Help.begin(),
                                          ActionStr::Help.end(), input))
    {
        action = Action::HELP;
    }
    else if(ActionStr::ListItems.end() != std::find(ActionStr::ListItems.begin(),
                                                    ActionStr::ListItems.end(), input))
    {
        action = Action::LIST_ITEMS;
    }
    return action;
}

void Game::printItemsOnGround()
{
    if(player.isLootInTheRoom()){
        cout << "Items on ground:" << endl;
        cout << player.getLootInRoomInfo();
    }else{
        cout << "No items here." << endl;
    }
}

void Game::printEnding()
{
    cout << "Congratulations, you've reached the exit!" << endl;
}
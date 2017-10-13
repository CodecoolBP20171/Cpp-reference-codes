#include "Player.h"

string Player::getRoomDescription()
{
    return currentRoom->getDescription();
}

string Player::getLootInRoomInfo()
{
    string info = currentRoom->getLootInfo() + "\n";
    return info;
}

string Player::getAvailableDirections()
{
    // collect names of available directions from this room
    string dirs;
    bool commaNeeded = false;
    int index = DirectionStr::LongDescription;
    if(nullptr != currentRoom->getRoom(Direction::NORTH)){
        dirs += DirectionStr::North[index];
        commaNeeded = true;
    }
    if(nullptr != currentRoom->getRoom(Direction::SOUTH)){
        if(commaNeeded) dirs += ", ";
        dirs += DirectionStr::South[index];
        commaNeeded = true;
    }
    if(nullptr != currentRoom->getRoom(Direction::WEST)){
        if(commaNeeded) dirs += ", ";
        dirs += DirectionStr::West[index];
        commaNeeded = true;
    }
    if(nullptr != currentRoom->getRoom(Direction::EAST)){
        if(commaNeeded) dirs += ", ";
        dirs += DirectionStr::East[index];
    }
    return dirs;
}

bool Player::move(const Direction direction)
{
    // don't let player go to unavailable places
    Room* nextRoom = currentRoom->getRoom(direction);
    if(nullptr != nextRoom){
        currentRoom = nextRoom;
        return true;
    }
    return false;
}

bool Player::isFinished()
{
    //TODO: better end-checking
    if( nullptr == currentRoom->getRoom(Direction::NORTH) &&
        nullptr == currentRoom->getRoom(Direction::SOUTH) &&
        nullptr == currentRoom->getRoom(Direction::WEST) &&
        nullptr == currentRoom->getRoom(Direction::EAST) )
    {
        return true;
    }
    return false;
}
//
// Created by László Molnár on 2017-10-3.
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_COMMANDS_HPP
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_COMMANDS_HPP
#include <map>

using namespace std;

enum Direction
{
    NORTH,
    SOUTH,
    EAST,
    WEST,
    INVALID_DIR
};

namespace DirectionStr
{
    static const int ShortDescription = 0;
    static const int LongDescription = 1;
    static const vector<string> North = {"N", "North"};
    static const vector<string> South = {"S", "South"};
    static const vector<string> East = {"E", "East"};
    static const vector<string> West = {"W", "West"};
};

enum Action
{
    HELP,
    LIST_ITEMS,
    INVALID_ACT
};

namespace ActionStr
{
    static const vector<string> Help = {"H", "Help"};
    static const vector<string> ListItems = {"L", "List"};

};

static const map<string, vector<string> > Commands = {
        {"Go North", DirectionStr::North},
        {"Go South", DirectionStr::South},
        {"Go West", DirectionStr::West},
        {"Go East", DirectionStr::East},
        {"List Items on the ground", ActionStr::ListItems},
        {"This Help", ActionStr::Help}
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_REFERENCE_COMMANDS_HPP

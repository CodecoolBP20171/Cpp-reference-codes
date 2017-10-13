#include <iostream>
#include <vector>
#include "Game.h"
#include "Room.h"

using namespace std;

int main() {
    cout << "Starting Mighty Text Adventure!" << endl;

    Game game;
    game.init();
    game.run();

    cout << "Exiting from Mighty Text Adventure!" << endl;
    return 0;
}

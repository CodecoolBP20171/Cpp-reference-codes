#include "Minesweeper.h"

using namespace std;


int main() {
    try {
        Minesweeper ms(10, 10);
        ms.printTable();
        cout << endl;
        ms.countNeighbours();
        ms.printTable();
    } catch (const std::bad_alloc &e) {
        std::cerr << "Couldn't allocate enough memory for minesweeper table" << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}
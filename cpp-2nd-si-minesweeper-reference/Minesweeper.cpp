#include <cstring>
#include <ctime>
#include <algorithm>
#include "Minesweeper.h"

void Minesweeper::countNeighbours() {
    for (size_t row = 0; row < height; ++row) {
        for (size_t col = 0; col < width; ++col) {
            size_t place = getPlaceInTable(col, row);
            if(TABLE_MINE == table[place]) {
                incMineCounter(col, row);
            }
        }
    }
}

void Minesweeper::printTable() const {
    for (unsigned row = 0; row < height; ++row) {
        cout << "\t";
        for (unsigned col = 0; col < width; ++col) {
            cout << table[getPlaceInTable(col, row)];
        }
        cout << endl;
    }
}

size_t Minesweeper::getPlaceInTable(const size_t col, const size_t row) const {
    return row * height + col;
}

void Minesweeper::fillTable() {
    initEmptyTable();
    placeMines();
}

void Minesweeper::initEmptyTable()
{
    memset(table, TABLE_EMPTY_PLACE, size * sizeof(char));
}

void Minesweeper::placeMines()
{
    srand(time(0)); // use current time as seed for random generator
    unsigned numOfMines = calculateNumOfMines();
    unsigned minesPlaced = 0;

    while (minesPlaced < numOfMines) {
        int place = rand() % size;
        if (TABLE_EMPTY_PLACE == table[place]) {
            table[place] = TABLE_MINE;
            ++minesPlaced;
        }
    }
}

unsigned Minesweeper::calculateNumOfMines()
{
    unsigned numOfMines = 0;
    do {
        numOfMines = rand() % (size / 2);
    }while(numOfMines < size / 4); // restrict number of mines. Not too many, not too few

    return numOfMines;
}

void Minesweeper::incMineCounter(const size_t col, const size_t row) {
    size_t currentRow = static_cast<size_t>(std::max(static_cast<int>(row - 1), 0)); // I don't say you should do this :)
    for ( ; currentRow < std::min(row + 2, height); ++currentRow) {
        size_t currentCol = max(static_cast<int>(col - 1), 0);
        for ( ; currentCol < min(col + 2, width); ++currentCol) {
            if( TABLE_MINE != table[getPlaceInTable(currentCol, currentRow)]) {
                if(TABLE_EMPTY_PLACE == table[getPlaceInTable(currentCol, currentRow)]) {
                    table[getPlaceInTable(currentCol, currentRow)] = '1';
                }else {
                    ++table[getPlaceInTable(currentCol, currentRow)];
                }
            }
        }
    }
}

//
// Created by László Molnár on 2017-10-12.
//

#ifndef MINESWEEPER_MINESWEEPER_H
#define MINESWEEPER_MINESWEEPER_H
#include <iostream>

using namespace std;

// macros are C-style but I wanted you to see them :)
#define TABLE_EMPTY_PLACE '.'
#define TABLE_MINE '*'


class Minesweeper {
public:
    Minesweeper(const size_t width, const size_t height)
            : width(width), height(height), size(width*height),
              table(new char[width * height]) {
        fillTable();
    }

    virtual ~Minesweeper() {
        delete[] table;
    }

    void countNeighbours();
    void printTable() const;

private:
    const size_t width, height;
    const size_t size;
    char *table;

    size_t getPlaceInTable(const size_t col, const size_t row) const;
    void fillTable();
    void initEmptyTable();
    void placeMines();
    unsigned calculateNumOfMines();
    void incMineCounter(const size_t col, const size_t row);
};

#endif //MINESWEEPER_MINESWEEPER_H

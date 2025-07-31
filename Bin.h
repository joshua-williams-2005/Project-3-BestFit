#pragma once
#include <utility>

struct board {
    bool occupied = false;
};

class Bin {
private:
    int rows;
    int columns;
    board table[5][5];
public:
    Bin();
    int capacity = 25;
    std::pair<int, int> canFit(int height, int width);
    bool is_empty();
    bool canPlaceAt(int height, int width, int startRow, int startCol);
    void placeRectangle(int height, int width, int startRow, int startCol);
    void printBin();

};
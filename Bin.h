#pragma once

#include <utility>

struct board {
    bool occupied = false;
};

class Bin {
private:
    int rows;
    int columns;
    board table[50][50];
public:
    int capacity = 2500;
    Bin();
    std::pair<int, int> canFit(int height, int width);
    bool is_empty();
    void placetherec(int width, int height, int startrows, int startcol);
};
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
    Bin();
    int capacity = 2500;
    std::pair<int, int> canFit(int height, int width);
    bool is_empty();
    void placetherec(int width, int height, int startrows, int startcol);
};
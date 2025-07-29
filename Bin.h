#pragma once

struct board {
    bool a = false;
};

class Bin {
private:
    int rows;
    int columns;
    board a[50][50];
public:
    int capacity;
    Bin();
    std::pair<int, int> canFit(int height, int width);
    void placetherec(int width, int height, int startrows, int startcol);
};
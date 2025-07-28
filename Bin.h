#pragma once
#include <vector>

struct newgrid {
    bool a=false;
};

class Bin {
private:
    int rows;
    int columns;
    //std::vector<std::vector<bool>> board;
    newgrid board[50][50];
public:
    int capacity;
    Bin();
    void placetherec(int width, int height, int startrows, int startcol);
};
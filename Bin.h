#pragma once
#include <vector>

struct newgrid {
    bool a=false;
};

class Bin {
private:
    int rows;
    int columns;
    std::vector<std::vector<bool>> board;
    newgrid a[50][50];
public:
    int capacity;
    Bin();
};
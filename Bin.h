#pragma once
#include <utility>
const int N = 5;//for the side length of bins

struct board {
    bool occupied = false;
};

class Bin {
private:
    int rows;
    int columns;
    board table[N][N];
public:
    Bin();
    int capacity = N * N;
    std::pair<int, int> canFit(int height, int width);
    bool is_empty();
    bool canPlaceAt(int height, int width, int startRow, int startCol);
    void placeRectangle(int height, int width, int startRow, int startCol);
    void printBin();
    void emptyBin();
};

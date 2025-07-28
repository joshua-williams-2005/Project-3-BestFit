#pragma once
#include "Bin.h"
#include <vector>
using namespace std;

class Grid {
private:
    int rows;
    int columns;
    vector<Bin> bins;

public:
    Grid();
    Grid(int width, int height);
    void firstFit();
    void bestFit();
    void printGrid();
};
#pragma once
#include "Bin.h"
#include <vector>
using namespace std;

class Grid {
private:
    int numBins;
    vector<Bin> bins;

public:
    Grid();

    void firstFit();
    void bestFit();
    void printGrid();
};
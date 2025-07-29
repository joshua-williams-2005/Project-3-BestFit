#pragma once
#include "Bin.h"
#include <iostream>
#include <vector>
#include <random>
using namespace std;

class Grid {
private:
    int numBins;
    vector<Bin> bins;
    vector<pair<int, int> > rectangles;

public:
    Grid();
    void createRectangles();
    void firstFit();
    void bestFit();
    void printGrid();
};
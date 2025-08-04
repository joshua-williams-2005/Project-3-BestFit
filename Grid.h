#pragma once

#include "Bin.h"
#include <iostream>
#include <vector>
#include <random>
using namespace std;
const int NUM_RECS = 100000;
const int NUM_BINS = 100000;
class Grid {
private:
    int FFspace;
    int BFspace;
    int numBins;
    vector<Bin> bins;
    vector<pair<int, int> > rectangles;


public:
    Grid();
    void createRectangles();
    void firstFit();
    void bestFit();
    void printRectangles();
    void printBins();
    void emptyBins();
    int getFFspace();
    int getBFspace();
};

#include "Grid.h"
#include <iostream>
using namespace std;

Grid::Grid(){
    this->numBins = 100;
    for (int i = 0; i < 100; i++){
      Bin b;
      bins.push_back(b);
    }
}


void Grid::printGrid(){
  cout << "Grid Size: " << numBins << endl;
}

void Grid::firstFit() {
    cout << "First Fit" << endl;
}

void Grid::bestFit() {
    cout << "Best Fit" << endl;
}
#include "Grid.h"
#include <iostream>
using namespace std;

Grid::Grid(){
    this->size = 100;
}

void Grid::printGrid(){
  cout << "Grid Size: " << size << endl;

}

void Grid::firstFit() {
    cout << "First Fit" << endl;
}

void Grid::bestFit() {
    cout << "Best Fit" << endl;
}
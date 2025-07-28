#include "Grid.h"
#include <iostream>
using namespace std;

Grid::Grid(){
    width = 100;
    height = 100;
}

Grid::Grid(int width, int height) {
    this->width = width;
    this->height = height;
}

void Grid::printGrid(){
  cout << "Grid Width: " << width << endl;
  cout << "Grid Height: " << height << endl;
}

void Grid::firstFit() {
    cout << "First Fit" << endl;
}

void Grid::bestFit() {
    cout << "Best Fit" << endl;
}
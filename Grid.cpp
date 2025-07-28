#include "Grid.h"
#include <iostream>
using namespace std;

Grid::Grid(){
    this->width = 100;
    this->height = 100;
}

void Grid::printGrid(){
  cout << "Grid Width: " << width << endl;
  cout << "Grid Height: " << height << endl;
}
#include "Grid.h"
#include <iostream>
using namespace std;


Grid::Grid() {
    width = 100;
    height = 100;
}

Grid::Grid(int w, int h) {
    width = w;
    height = h;
}

void::Grid::printGrid() {
  cout << "Grid Width: " << width << endl;
  cout << "Grid Height: " << height << endl;
}
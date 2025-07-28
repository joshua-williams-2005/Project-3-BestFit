#include "Grid.h"
#include <iostream>
using namespace std;

Grid::Grid(){
    rows = 100;
    columns = 100;
}

Grid::Grid(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
}

void Grid::printGrid(){
  cout << "Grid Rows: " << rows << endl;
  cout << "Grid Columns: " << columns << endl;
}

void Grid::firstFit() {
    cout << "First Fit" << endl;
}

void Grid::bestFit() {
    cout << "Best Fit" << endl;
}
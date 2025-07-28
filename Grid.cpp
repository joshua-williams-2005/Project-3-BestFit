#include "Grid.h"
#include <iostream>
using namespace std;

Grid::Grid(int width, int height){
    width = 100;
    height = 100;
}

void::Grid::printGrid(){
  cout << "Grid Width: " << width << endl;
  cout << "Grid Height: " << height << endl;
}
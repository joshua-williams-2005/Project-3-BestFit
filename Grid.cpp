#include "Grid.h"

using namespace std;

Grid::Grid() {
    this->numBins = 100; //we can change later
    //creating 100 empty bins in the grid
    for (int i = 0; i < 100; i++) {
      Bin b;
      bins.push_back(b);
    }
}
void Grid::createRectangles(){
    random_device rd;  // Seed
    mt19937 gen(rd()); // Mersenne Twister engine
    uniform_int_distribution<> dist(1, 50); // Range [1, 50], which will be always be less than bin length and width

    vector<int> lengths;
    vector<int> widths;

    // Generate 100 random lengths
    for (int i = 0; i < 100; ++i) {
        lengths.push_back(dist(gen));
    }
    // Generate 100 random widths
    for (int i = 0; i < 100; ++i) {
        widths.push_back(dist(gen));
    }
    //putting the 100 random rectangles into an array of pairs
    for (int i = 0; i < 100; ++i){
        pair <int, int> p;
        p.first = lengths[i];
        p.second = widths[i];
        rectangles.push_back(p);
    }
}
//testing/debugging function
void Grid::printGrid() {
  cout << "Grid Size: " << numBins << endl;
}

void Grid::firstFit() {
    cout << "First Fit" << endl;
}

void Grid::bestFit() {
    cout << "Best Fit" << endl;
}
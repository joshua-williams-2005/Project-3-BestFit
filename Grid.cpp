#include "Grid.h"

using namespace std;

Grid::Grid() {
    this->numBins = 100; //we can change later
    //    this->FFspace = 100;
    //    this->BFspace = 100;
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

    //iterate through every rectangle
    for (int i = 0; i < 100; ++i) {
        int length = rectangles[i].first; //length of rectangle i
        int width = rectangles[i].second; //width of rectangle i

        //iterate through every bin, but break once inserted
        for (int j = 0; j < 100; ++j) {
            Bin &b = bins[j];
            pair<int,int> p1;
            p1 = b.canFit(length,width);
            if (p1.first != -50 || p1.second != -50){
                b.placeRectangle(length,width,p1.first,p1.second);
                //b.capacity = b.capacity - (length * width); i put it in the place the rec method- alex
                break;
            }
        }
    }

    //check for space
    for (int i = 0; i < 100; ++i) {
        Bin b = bins[i];
        if (b.is_empty()){
          FFspace++;
        }
    }
}

void Grid::bestFit() {
    cout << "Best Fit" << endl;
    for (int i = 0; i < 100; ++i) {
        int length = rectangles[i].first; //length of rectangle i
        int width = rectangles[i].second; //width of rectangle i

        int min = 1000000;
        int bestIndex = -1;
        //check which bin has the least empty space when inserted
        for (int j = 0; j < 100; ++j) {
            Bin &b = bins[j];
            pair<int,int> p1;
            p1 = b.canFit(length,width);
            if (p1.first != -50 || p1.second != -50){
                int space = b.capacity - (length * width);
                if (space < min) {
                  min = space;
                  bestIndex = j;
                }
            }
        }
        //insert into the best fit bin and update the bin's capacity
        Bin b = bins[bestIndex];
        pair<int,int> p1 = b.canFit(length,width);
        b.placeRectangle(length,width,p1.first,p1.second);
        //b.capacity = b.capacity - (length * width); i put it in the place the rec method- alex
    }

    //check for space
    for (int i = 0; i < 100; ++i) {
        Bin b = bins[i];
        if (b.is_empty()){
            BFspace++;
        }
    }
}

void Grid::results() {
  cout << "Results" << endl;
  cout << "First Fit empty bins: " << FFspace << endl;
  cout << "Best Fit empty bins: " << BFspace << endl;
}

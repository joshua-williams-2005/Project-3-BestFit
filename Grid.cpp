#include "Grid.h"
#include <algorithm>
using namespace std;

Grid::Grid() {
    this->numBins = NUM_BINS; //we can change later
    //# of empty bins after BF and FF
    this->FFspace = 0;
    this->BFspace = 0;
    //creating 100 empty bins in the grid
    for (int i = 0; i < NUM_BINS; i++) {
        Bin b;
        bins.push_back(b);
    }
}
void Grid::createRectangles() {
    rectangles.clear();
    rectangles.reserve(NUM_BINS);

    random_device rd;  // Seed
    mt19937 gen(rd()); // Mersenne Twister engine
    uniform_int_distribution<> dist(1, 5); // Range [1, 50], which will be always be less than bin height and width

    vector<int> heights;
    vector<int> widths;

    // Generate NUM_RECS random heights
    for (int i = 0; i < NUM_RECS; ++i) {
        heights.push_back(dist(gen));
    }
    // Generate NUM_RECS random widths
    for (int i = 0; i < NUM_RECS; ++i) {
        widths.push_back(dist(gen));
    }
    //putting the NUM_RECS random rectangles into an array of pairs
    for (int i = 0; i < NUM_RECS; ++i) {
        pair <int, int> p;
        p.first = heights[i];
        p.second = widths[i];
        rectangles.push_back(p);
    }

}
void Grid::printRectangles() {
  for (int i = 0; i < rectangles.size(); ++i) {
      cout << rectangles[i].first << " " << rectangles[i].second << endl;
  }
}
void Grid::printBins() {
    for (int i = 0; i < bins.size(); ++i) {
        Bin b = bins[i];
        b.printBin();
    }
}
void Grid::emptyBins() {
  for (int i = 0; i < bins.size(); ++i) {
        Bin &b = bins[i];
        b.emptyBin();
  }
  FFspace = 0;
  BFspace = 0;
}

void Grid::firstFit() {
    //cout << "First Fit" << endl;
    //iterate through every rectangle
    for (int i = 0; i < NUM_RECS; ++i) {
        int height = rectangles[i].first; //height of rectangle i
        int width = rectangles[i].second; //width of rectangle i

        //iterate through every bin, but break once inserted
        for (int j = 0; j < NUM_BINS; ++j) {
            Bin &b = bins[j];
            if(b.capacity < height * width) {
                continue;
            }
            pair<int,int> p1 = b.canFit(height,width);
            if (p1.first != -50 || p1.second != -50) {
                b.placeRectangle(height,width,p1.first,p1.second);
                break;
            }
        }
    }
    //check for space
    for (int i = 0; i < NUM_BINS; ++i) {
        if (bins[i].is_empty()) {
            FFspace++;
        }
    }
}

void Grid::bestFit() {
    //cout << "Best Fit" << endl;
    auto newrecs = rectangles;
    sort(newrecs.begin(), newrecs.end(), [](auto& a, auto& b) {
              return a.first * a.second > b.first * b.second;
          });
    for (int i = 0; i < NUM_RECS; ++i) {
        int height = newrecs[i].first; //height of rectangle i
        int width = newrecs[i].second; //width of rectangle i

        //iterate through every bin, but break once inserted
        for (int j = 0; j < NUM_BINS; ++j) {

            Bin &b = bins[j];
            //if it can't fit, then break
            if(b.capacity < height * width) {
                continue;
            }
            pair<int,int> p1;
            p1 = b.canFit(height,width);
            if (p1.first != -50 && p1.second != -50){
                b.placeRectangle(height,width,p1.first,p1.second);
                break;
            }
        }
    }

    //check for space
    for (int i = 0; i < NUM_BINS; ++i) {
        if (bins[i].is_empty()) {
            BFspace++;
        }
    }
}

int Grid::getFFspace() {
    return FFspace;
}
int Grid::getBFspace() {
    return BFspace;
}

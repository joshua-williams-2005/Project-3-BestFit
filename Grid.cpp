#include "Grid.h"

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
void Grid::createRectangles(){
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
    for (int i = 0; i < NUM_RECS; ++i){
        pair <int, int> p;
        p.first = heights[i];
        p.second = widths[i];
        rectangles.push_back(p);
    }

}
void Grid::createSetRectangles() {
    std::mt19937 rng(42); // Fixed seed for reproducibility
    std::uniform_int_distribution<int> dist(1, 5);

    for (int i = 0; i < 100; ++i) {
        pair <int, int> p;
        p.first = dist(rng);
        p.second = dist(rng);
        rectangles.push_back(p);
    }
}
void Grid::createPredeterminedRectangles() {
    vector<int> heights = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1};
    vector<int> widths = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    for (int i = 0; i < heights.size(); ++i) {
        pair<int, int> p;
        p.first = heights[i];
        p.second = widths[i];
        rectangles.push_back(p);
    }
}
//test function
void Grid::printRectangles() {
  for (int i = 0; i < rectangles.size(); ++i) {
    cout << rectangles[i].first << " " << rectangles[i].second << endl;
  }
}
void Grid::printBins(){
    for (int i = 0; i < bins.size(); ++i){
        Bin b = bins[i];
        b.printBin();
    }
}
void Grid::emptyBins(){
  for (int i = 0; i < bins.size(); ++i){
        Bin &b = bins[i];
        b.emptyBin();
  }
  FFspace = 0;
  BFspace = 0;
}

void Grid::firstFit() {
    cout << "First Fit" << endl;

    //iterate through every rectangle
    for (int i = 0; i < NUM_RECS; ++i) {
        int height = rectangles[i].first; //height of rectangle i
        int width = rectangles[i].second; //width of rectangle i

        //iterate through every bin, but break once inserted
        for (int j = 0; j < NUM_BINS; ++j) {
            Bin &b = bins[j];
            pair<int,int> p1;
            p1 = b.canFit(height,width);
            if (p1.first != -50 || p1.second != -50){
                b.placeRectangle(height,width,p1.first,p1.second);
                break;
            }
        }
    }

    //check for space
    for (int i = 0; i < NUM_BINS; ++i) {
        Bin b = bins[i];
        if (b.is_empty()){
          FFspace++;
        }
    }
}

void Grid::bestFit() {
    cout << "Best Fit" << endl;

    for (int i = 0; i < NUM_RECS; ++i) {
        int height = rectangles[i].first; //height of rectangle i
        int width = rectangles[i].second; //width of rectangle i

        int min = 1000000;
        int bestIndex = -1;
        //check which bin has the least empty space when inserted
        for (int j = 0; j < NUM_BINS; ++j) {
            Bin &b = bins[j];
            pair<int,int> p1;
            p1 = b.canFit(height,width);
            if (p1.first != -50 || p1.second != -50){
                int space = b.capacity - (height * width);
                if (space < min) {
                  min = space;
                  bestIndex = j;
                }
            }
        }
        //insert into the best fit bin and update the bin's capacity
        Bin &b = bins[bestIndex];
        pair<int,int> p1 = b.canFit(height,width);
        b.placeRectangle(height,width,p1.first,p1.second);
    }

    //check for space
    for (int i = 0; i < NUM_BINS; ++i) {
        Bin b = bins[i];
        if (b.is_empty()){
            BFspace++;
        }
    }
}

int Grid::getFFspace(){
    return FFspace;
}
int Grid::getBFspace(){
    return BFspace;
}
void Grid::results() {

  firstFit();
  emptyBins();
  bestFit();
  emptyBins();

  cout << "RESULTS" << endl;
  cout << "First Fit empty bins: " << FFspace << "/100 bins remaining" << endl;
  cout << "Best Fit empty bins: " << BFspace << "/100 bins remaining" << endl;
}


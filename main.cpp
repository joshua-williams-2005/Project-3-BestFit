#include "Grid.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Grid g;

    std::string userInput;
    cout << "~~~~~~~~2D Rectangles Packing~~~~~~~~"<<endl;
    cout << "1. Generate New Rectangles" << endl;
    cout << "2. Run First-Fit Decreasing" << endl;
    cout << "3. Run Best-Fit Decreasing" << endl;
    cout << "4. First-Fit vs Best-Fit" << endl;
    cout << "5. Exit" << endl;
    cout << "Please Select a Choice Above" << endl;
    while (userInput != "5") {
        std::getline(std::cin, userInput);

        if (userInput == "1") {
            cout<<"generate rectangles" << endl;
            g.createRectangles(); //reset vector of rectangles and generate 100,000 random rectangles
            g.printRectangles();
        }
        else if (userInput == "2") {
            cout<<"first-fit" << endl;
            //calculate time
            g.firstFit();
            g.printBins();
            int space = g.getFFspace();

            cout << "First Fit empty bins: " << space << endl;
            cout << "Time to run First Fit: " << 0 << endl;
            g.emptyBins();

        }
        else if (userInput == "3") {
            cout<<"best-fit" << endl;
            //calculate time
            g.bestFit();
            g.printBins();
            int space = g.getBFspace();
            cout << "Best Fit empty bins: " << space << endl;
            cout << "Time to run Best Fit: " << 0 << endl;
            g.emptyBins();
        }
        else if (userInput == "4") {
            int BFspace, FFspace;

            g.firstFit();
            g.printBins();
            FFspace = g.getFFspace();
            g.emptyBins(); //resets BFspace and FFspace
            g.bestFit();
            g.printBins();
            BFspace = g.getBFspace(); //resets BFspace and FFspace
            g.emptyBins();
            cout << "RESULTS" << endl;
            cout << "First Fit empty bins: " << FFspace << endl;
            cout << "Best Fit empty bins: " << BFspace << endl;
            cout << "Time to run First Fit: " << 0 << endl;
            cout << "Time to run Best Fit: " << 0 << endl;
            //space is how many empty bins, so more empty bins is better, saving more space
            if(BFspace > FFspace) { //should happen
                cout << "Best Fit saves " << BFspace - FFspace << " bins" << endl;
            }
            else if (BFspace > FFspace){ //shouldn't happen
                cout << "First Fit saves " << FFspace - BFspace << " bins" << endl;
            }
            else{ //equal space
                cout << "Both algorithms save the same amount of bins" << endl;
            }
        }
        else if (userInput == "5") {
            cout<<"exit" << endl;
        }
        else {
            cout<<"Please Enter a Number between 1 and 5" << endl;
        }
    }
}




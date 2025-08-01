#include "Grid.h"
#include <iostream>
#include <string>
#include <chrono>
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
            auto time0=chrono::system_clock::now();
            g.firstFit();
            auto time1=chrono::system_clock::now();
            std::chrono::duration<double> time2 = time1 - time0;
            g.printBins();
            int space = g.getFFspace();

            cout << "First Fit empty bins: " << space << endl;
            cout << "Time to run First Fit: " << time2.count() <<" seconds."<< endl;
            g.emptyBins();

        }
        else if (userInput == "3") {
            cout<<"best-fit" << endl;
            //calculate time
            auto time0=chrono::system_clock::now();
            g.bestFit();
            auto time1=chrono::system_clock::now();
            std::chrono::duration<double> time2 = time1 - time0;
            g.printBins();
            int space = g.getBFspace();
            cout << "Best Fit empty bins: " << space << endl;
            cout << "Time to run Best Fit: " << time2.count() <<" seconds."<< endl;
            g.emptyBins();
        }
        else if (userInput == "4") {
            int BFspace, FFspace;
            auto time0=chrono::system_clock::now();
            g.firstFit();
            auto time1=chrono::system_clock::now();
            std::chrono::duration<double> firstFitTime = time1 - time0;
            g.printBins();
            FFspace = g.getFFspace();
            g.emptyBins(); //resets BFspace and FFspace
            auto time2=chrono::system_clock::now();
            g.bestFit();
            auto time3=chrono::system_clock::now();
            std::chrono::duration<double> bestFitTime = time3 - time2;
            g.printBins();
            BFspace = g.getBFspace(); //resets BFspace and FFspace
            g.emptyBins();
            cout << "RESULTS" << endl;
            cout << "First Fit empty bins: " << FFspace << endl;
            cout << "Best Fit empty bins: " << BFspace << endl;
            cout << "Time to run First Fit: " << firstFitTime.count() <<" seconds."<< endl;
            cout << "Time to run Best Fit: " << bestFitTime.count() <<" seconds."<< endl;
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
            if(firstFitTime.count() > bestFitTime.count()) { //shouldn't happen
                cout << "Best Fit saves " << firstFitTime.count() - bestFitTime.count() << " seconds" << endl;
            }
            else if (bestFitTime.count() > firstFitTime.count()){ //should happen
                cout << "First Fit saves " << bestFitTime.count() - firstFitTime.count() << " seconds" << endl;
            }
            else{ //equal space
                cout << "Both algorithms use the same amount of time" << endl;
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



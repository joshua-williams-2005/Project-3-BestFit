#include "Grid.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Grid g;

    std::string userInput;
    cout << "~~~~~~~~2D Rectangles Packing~~~~~~~~"<<endl;
    cout << "1. Generate Rectangles" << endl;
    cout << "2. Run First-Fit Decreasing" << endl;
    cout << "3. Run Best-Fit Decreasing" << endl;
    cout << "4. Show Results" << endl;
    cout << "5. Exit" << endl;
    cout << "Please Select a Choice Above" << endl;
    while (userInput != "5") {
        std::getline(std::cin, userInput);
        if (userInput == "1") {
            cout<<"generate rectangles" << endl;
            g.createRectangles();
        }
        else if (userInput == "2") {
            cout<<"first-fit" << endl;
            // g.firstFit();
        }
        else if (userInput == "3") {
            cout<<"best-fit" << endl;
            // g.bestFit();
        }
        else if (userInput == "4") {
            cout<<"show results" << endl;
            // g.results();
        }
        else if (userInput == "5") {
            cout<<"exit" << endl;
        }
        else {
            cout<<"Please Enter a Number between 1 and 5" << endl;
        }
    }
}




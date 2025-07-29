#include "Bin.h"
#include <iostream>
using namespace std;

Bin::Bin() {
    rows = 50;
    columns = 50;
}

bool Bin::canFit(int height, int width) {
    if (height > rows || width > columns) {
        return false;
    }

    for(int i = 0;i< height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (a[i][j].a == true) {
                return false;
            }
        }
    }
    return true;
}

void Bin::placetherec(int width, int height, int startrows, int startcol) {
    for(int i=0;i<width;i++) {
        for (int j = 0; j < height; j++)
            a[i + startrows][j + startcol].a = true;
    }
}
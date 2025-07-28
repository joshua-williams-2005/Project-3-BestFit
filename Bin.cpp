#include "Bin.h"
#include <iostream>
using namespace std;

Bin::Bin() {
    rows = 50;
    columns = 50;
}

void Bin::placetherec(int width, int height, int startrows, int startcol) {
    for(int i=0;i<width;i++) {
        for (int j = 0; j < height; j++)
            a[i + startrows][j + startcol].a = true;
    }
}
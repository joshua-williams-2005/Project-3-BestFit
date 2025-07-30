#include "Bin.h"
#include <iostream>
using namespace std;

Bin::Bin() {
    rows = 50;
    columns = 50;
    //initialize all table positions as unoccupied
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < columns; c++) {
            grid[r][c].occupied = false;
        }
    }
}

bool Bin::is_empty(){//to check if the bin is empty
    return capacity == 2500;
}

pair<int, int> Bin::canFit(int length, int width) {
    if (length > rows || width > columns) {
        return make_pair(-50,-50);
    }
    const int N=50;
    bool flag=true;
    int over=0;
    int newx=-50;
    int newy=-50;
    /*for(int i = 0;i< height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (a[i][j].a == true) {
                return false;
            }
        }
    }*/
    int i,j;
    for(i=0;i<N-length;i++){
        for(j=0;j<N-width;j++){
            flag=true;
            for(int k = 0;k< length; ++k) {
                for (int l = 0; l < width; ++l) {
                    if (table[i+k][j+l].occupied == true) {
                        flag=false;
                    }
                }
            }
            if(flag==true){
                over=1;
                newx=i;
                newy=j;
                break;
            }
        }
        if(over==1){
            break;
        }
    }

    return make_pair(newx,newy);
}

void Bin::placeRectangle(int height, int width, int startRow, int startCol) {
    for(int i=0;i<height;i++) {
        for (int j = 0; j < width; j++){
            table[i + startRow][j + startCol].occupied = true;
        }
    }
    capacity -= (height * width);
}
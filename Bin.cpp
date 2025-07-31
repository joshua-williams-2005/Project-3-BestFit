#include "Bin.h"
#include <iostream>
using namespace std;
Bin::Bin() {
    rows = N;
    columns = N;
    //initialize all table positions as unoccupied
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < columns; c++) {
            table[r][c].occupied = false;
        }
    }
}

bool Bin::is_empty() {//to check if the bin is empty
    return capacity == N*N;
}

bool Bin::canPlaceAt(int height, int width, int startRow, int startCol) {
    if (startRow + height > rows || startCol + width > columns) {
        return false;
    }
    //check values
    for (int i = startRow; i < startRow + height; i++) {
        for (int j = startCol; j < startCol + width; j++) {
            if (table[i][j].occupied) {
                return false;
            }
        }
    }
    return true;
}
pair<int, int> Bin::canFit(int height, int width) {
    if (height > rows || width > columns) {
        return make_pair(-50, -50);
    }

    for(int i = 0; i <= rows - height; i++) {
        for(int j = 0; j <= columns - width; j++) {
            if(canPlaceAt(height, width, i, j)) {
                return make_pair(i, j);
            }
        }
    }

    return make_pair(-50, -50);
}/*
pair<int, int> Bin::canFit(int height, int width) {
    if (height > rows || width > columns) {
        return make_pair(-50,-50);
    }
    const int N=50;
    bool flag=true;
    int over=0;
    int newx=-50;
    int newy=-50;
    int i,j;
    for(i=0;i<N-height;i++){
        for(j=0;j<N-width;j++){
            flag=true;
            for(int k = 0;k< height; ++k) {
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
}*/

void Bin::placeRectangle(int height, int width, int startRow, int startCol) {
    //Verify if placement is valid
    if (!canPlaceAt(height, width, startRow, startCol)) {
        cout << "Can't place rectangle" << endl;
        return;
    }
    //Place rectangle
    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++){
            table[i + startRow][j + startCol].occupied = true;
        }
    }
    capacity -= (height * width);
}

void Bin::printBin() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cout << table[i][j].occupied << " ";
        }
        cout << endl;
    }
    cout << "remaining capcity: " << capacity << endl;
}

void Bin::emptyBin() {
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < columns; c++) {
            table[r][c].occupied = false;
        }
    }
    capacity=N*N;
}

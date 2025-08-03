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

bool Bin::is_empty() const {
    return capacity == N * N;
}

bool Bin::canPlaceAt(int height, int width, int startRow, int startCol) const {
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
}

void Bin::placeRectangle(int height, int width, int startRow, int startCol) {
    //Verify if placement is valid
    if (!canPlaceAt(height, width, startRow, startCol)) {
        cout << "Can't place rectangle" << endl;
        return;
    }
    //Place rectangle
    for(int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
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
    cout << "remaining capacity: " << capacity << endl;
}

void Bin::emptyBin() {
    for(int r = 0; r < rows; r++) {
        for(int c = 0; c < columns; c++) {
            table[r][c].occupied = false;
        }
    }
    capacity = N * N;
}

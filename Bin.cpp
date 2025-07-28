#include "Bin.h"
#include <iostream>
using namespace std;

Bin::Bin(){
    rows = 50;
    columns = 50;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            board[i][j] = false;
        }
    }
}

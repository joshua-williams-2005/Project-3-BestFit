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
void Bin::placetherec(int width, int height, int startrows, int startcol){
    for(int i=0;i<width;i++){
        for (int j = 0; j < height; j++)
            board[i + startrows][j + startcol].a = true;
    }

}
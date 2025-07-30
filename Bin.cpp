#include "Bin.h"
#include <iostream>
using namespace std;

Bin::Bin() {
    rows = 50;
    columns = 50;
}
bool Bin::is_empty(){//to check if the bin is empty
    if (capacity==0){
        return true;
    }
    else{
        return false;
    }
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
                    if (a[i+k][j+l].a == true) {
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

void Bin::placetherec(int length, int width, int startrows, int startcol) {
    for(int i=0;i<length;i++) {
        for (int j = 0; j < width; j++){
            a[i + startrows][j + startcol].a = true;
        }
    }
    capacity = capacity - (length * width);
}
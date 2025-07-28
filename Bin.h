#pragma once
struct newgrid{
    bool a=false;
};
class Bin {
private:
    int rows;
    int columns;
    newgrid a[50][50];
public:
    int capacity;
    Bin();
};
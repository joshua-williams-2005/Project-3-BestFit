#pragma once

class Grid {
private:
    int rows;
    int columns;

public:
    Grid();
    Grid(int rows, int columns);
    void firstFit();
    void bestFit();
    void printGrid();
};
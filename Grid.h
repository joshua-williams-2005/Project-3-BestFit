#pragma once

class Grid {
private:
    int width;
    int height;

public:
    Grid();
    Grid(int width, int height);

    void printGrid();
};
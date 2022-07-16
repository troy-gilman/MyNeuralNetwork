//
// Created by Troy Gilman on 29/3/2022.
//

#ifndef CS3520_SPRING_2022_GRID_H
#define CS3520_SPRING_2022_GRID_H

#include <utility>
#include "Characters.h"
using namespace std;


class Grid {
private:
    void** g;
    int cols;
    int rows;

public:
    Grid(int r, int c): rows(r), cols(c){
        g = new void*[rows * cols];
        for (int i=0; i < rows * cols; i++)
            *(g+i) = nullptr;
    }

    void set(int row, int col, void* p);
    void* get(int row, int col);
    pair<int, int> shape();
    void display();
    bool isEmpty(int row, int col);
    void clear(int row, int col);
};


#endif //CS3520_SPRING_2022_GRID_H

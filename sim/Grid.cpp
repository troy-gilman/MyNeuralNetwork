//
// Created by Troy Gilman on 29/3/2022.
//

#include <stdexcept>
#include <iostream>
#include <ncurses.h>
#include "Grid.h"
#include "Organism.h"
using namespace std;

void Grid::set(int row, int col, void* p) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        int index = row * cols + col;
        *(g + index) = p;
    } else {
        throw invalid_argument("Could not set Organism: [" + to_string(row) + ", " + to_string(col) + "] out of range: " + to_string(rows) + "x" + to_string(cols));
    }
}

void* Grid::get(int row, int col) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        int index = row * cols + col;
        return *(g+index);
    } else {
        throw invalid_argument("Could not get Organism: [" + to_string(row) + ", " + to_string(col) + "] out of range: " + to_string(rows) + "x" + to_string(cols));
    }
}

pair<int, int> Grid::shape() {
    return pair<int, int>{rows, cols};
}

void Grid::display() {
    for (int i=0; i < cols+2; i++) {
        mvprintw(0, i*2, "%c", WALL_CHAR);
    }

    for (int r=0; r < rows; r++) {
        mvprintw(r+1, 0, "%c", WALL_CHAR);
        for (int c=0; c < cols; c++) {
            void* p = get(r, c);
            if (p != nullptr) {
                auto* o = static_cast<Organism *>(p);
                mvprintw(r+1, 2*c+2, "%c", o->getChar());
            }
        }
        mvprintw(r+1, 2*cols+2, "%c", WALL_CHAR);
    }

    for (int i=0; i < cols+2; i++) {
        mvprintw(rows+1, i*2, "%c", WALL_CHAR);
    }
}

bool Grid::isEmpty(int row, int col) {
    return get(row, col) == nullptr;
}

void Grid::clear(int row, int col) {
    set(row, col, nullptr);
}


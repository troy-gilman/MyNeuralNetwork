//
// Created by Troy Gilman on 29/3/2022.
//

#include <stdexcept>
#include <iostream>
#include "Ant.h"
using namespace std;

void Ant::move() {
    Organism::move();
    if (lastBreed >= 10) {
        *this + 8;
        *this + 8;
    } else if (lastBreed >= 5) {
        *this + 4;
    }
}

char Ant::getChar() {
    return ANT_CHAR;
}

Ant* Ant::operator+(int adjacency) {
    if (adjacency == 4 || adjacency == 8) {
        for (int i=0; i < adjacency; i++) {
            int move_row = row + adjacency8[i][0];
            int move_col = col + adjacency8[i][1];
            try {
                if (grid->isEmpty(move_row, move_col)) {
                    lastBreed = 0;
                    return new Ant(grid, move_row, move_col);
                }
            } catch (invalid_argument &e) {}
        }
    }
    return nullptr;
}

void Ant::operator--() {
    grid->clear(row, col);
    delete this;

}

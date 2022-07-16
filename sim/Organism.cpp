//
// Created by Troy Gilman on 29/3/2022.
//

#include <stdexcept>
#include "Organism.h"
using namespace std;

default_random_engine Organism::rand = default_random_engine(time(nullptr));
uniform_int_distribution<int> Organism::move_distribution(0, 3);


void Organism::move(int move_row, int move_col) {
    if (grid->isEmpty(move_row, move_col)) {
        grid->clear(row, col);
        grid->set(move_row, move_col, this);
        row = move_row;
        col = move_col;
    }
}

void Organism::move() {
    int direction = move_distribution(rand);
    int move_row = row + adjacency8[direction][0];
    int move_col = col + adjacency8[direction][1];
    try {
        move(move_row, move_col);
    } catch (invalid_argument& e) {
        move_row += -1 * adjacency8[direction][0] * grid->shape().first;
        move_col += -1 * adjacency8[direction][1] * grid->shape().second;
        move(move_row, move_col);
    }
    lastBreed++;
}

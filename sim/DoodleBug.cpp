//
// Created by Troy Gilman on 29/3/2022.
//

#include <stdexcept>
#include "DoodleBug.h"
using namespace std;

bool DoodleBug::eat(int move_row, int move_col) {
    if (!grid->isEmpty(move_row, move_col)) {
        auto *o = static_cast<Organism *>(grid->get(move_row, move_col));
        if (o->getChar() == ANT_CHAR) {
            --(*o);
            grid->clear(row, col);
            grid->set(move_row, move_col, this);
            row = move_row;
            col = move_col;
            lastAte = 0;
            return true;
        }
    }
    return false;
}

void DoodleBug::move() {
    bool ate = false;
    for (int i=0; i < 4; i++) {
        int move_row = row + adjacency8[i][0];
        int move_col = col + adjacency8[i][1];
        try {
            ate = eat(move_row, move_col);
            if (ate) break;
        } catch (invalid_argument& e) {
            move_row += -1 * adjacency8[i][0] * grid->shape().first;
            move_col += -1 * adjacency8[i][1] * grid->shape().second;
            ate = eat(move_row, move_col);
            if (ate) break;
        }
    }
    if (!ate) {
        lastAte++;
        if (lastAte >= 5) {
            --(*this);
            return;
        }
        Organism::move();
    }

    lastBreed++;
    if (lastBreed >= 10) {
        *this + 4;
    }
}

char DoodleBug::getChar() {
    return DOODLE_CHAR;
}

DoodleBug* DoodleBug::operator+(int adjacency) {
    if (adjacency == 4) {
        for (int i=0; i < adjacency; i++) {
            int move_row = row + adjacency8[i][0];
            int move_col = col + adjacency8[i][1];
            try {
                if (grid->isEmpty(move_row, move_col)) {
                    lastBreed = 0;
                    return new DoodleBug(grid, move_row, move_col);
                }
            } catch (invalid_argument& e) {}
        }
    }
    return nullptr;
}

void DoodleBug::operator--() {
    grid->clear(row, col);
    delete this;
}
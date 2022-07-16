//
// Created by Troy Gilman on 29/3/2022.
//

#ifndef CS3520_SPRING_2022_ORGANISM_H
#define CS3520_SPRING_2022_ORGANISM_H

#include <utility>
#include <random>
#include <ctime>
#include "Grid.h"
#include "Characters.h"
using namespace std;

static int adjacency8[8][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1},
                               {-1, -1}, {1, 1}, {1, 1}, {-1, -1}};

class Organism {
protected:
    int row;
    int col;
    int lastBreed;
    Grid* grid;
    static default_random_engine rand;
    static uniform_int_distribution<int> move_distribution;

public:
    Organism(Grid* g): grid(g), lastBreed(0) {
        uniform_int_distribution<int> row_distr(0, g->shape().first-1);
        uniform_int_distribution<int> col_distr(0, g->shape().second-1);
        do {
            row = row_distr(rand);
            col = col_distr(rand);
        } while (!g->isEmpty(row, col));
        grid->set(row, col, this);

    }
    Organism(Grid* g, int r, int c): grid(g), row(r), col(c), lastBreed(0) {
        grid->set(row, col, this);
    }

    void move(int row, int col);
    virtual void move();
    virtual char getChar() = 0;
    virtual Organism* operator+(int adjacency) = 0;
    virtual void operator--() = 0;
};


#endif //CS3520_SPRING_2022_ORGANISM_H

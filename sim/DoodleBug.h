//
// Created by Troy Gilman on 29/3/2022.
//

#ifndef CS3520_SPRING_2022_DOODLEBUG_H
#define CS3520_SPRING_2022_DOODLEBUG_H

#include "Organism.h"

class DoodleBug : public Organism {
private:
    int lastAte;

public:
    DoodleBug(Grid* g): lastAte(0), Organism(g) {}
    DoodleBug(Grid* g, int r, int c): lastAte(0), Organism(g, r, c) {}

    bool eat(int move_row, int move_col);
    void move() override;
    char getChar() override;
    DoodleBug* operator+(int adjacency) override;
    void operator--() override;
};


#endif //CS3520_SPRING_2022_DOODLEBUG_H

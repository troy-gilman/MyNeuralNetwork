//
// Created by Troy Gilman on 29/3/2022.
//

#ifndef CS3520_SPRING_2022_ANT_H
#define CS3520_SPRING_2022_ANT_H

#include "Organism.h"
#include "Grid.h"

class Ant : public Organism {
public:
    Ant(Grid* g): Organism(g) {}
    Ant(Grid* g, int r, int c): Organism(g, r, c) {}

    void move() override;
    char getChar() override;
    Ant* operator+(int adjacency) override;
    void operator--() override;
};


#endif //CS3520_SPRING_2022_ANT_H

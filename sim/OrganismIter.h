//
// Created by Troy Gilman on 30/3/2022.
//

#ifndef CS3520_SPRING_2022_ORGANISMITER_H
#define CS3520_SPRING_2022_ORGANISMITER_H

#include "Grid.h"
#include "Organism.h"
#include "Timer.h"


class OrganismIter {
private:
    Grid* grid;
    int currentRow;
    bool doodlesDone;
    Timer timer;
    Organism** visited;
    int sizeVisited;
    int numVisited;

public:
    OrganismIter(Grid* g): grid(g), numVisited(0), currentRow(0), doodlesDone(false) {
        pair<int, int> grid_shape = grid->shape();
        sizeVisited = grid_shape.first * grid_shape.second;
        visited = new Organism*[sizeVisited];
    }

    Organism* next();
    void shiftVisitedRight(int index);
    void visit(Organism* o);
    bool hasVisited(int start, int end, Organism* o);
    int getNumVisited() const;
};


#endif //CS3520_SPRING_2022_ORGANISMITER_H

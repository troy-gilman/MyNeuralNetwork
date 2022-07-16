//
// Created by Troy Gilman on 30/3/2022.
//

#include "OrganismIter.h"
using namespace std;

Organism* OrganismIter::next() {
    for (int row=currentRow; row < grid->shape().first; row++) {
        for (int col=0; col < grid->shape().second; col++) {
            if (!grid->isEmpty(row, col)) {
                auto o = static_cast<Organism*>(grid->get(row, col));
                if (doodlesDone) {
                    //timer.start();
                    bool v = hasVisited(0, numVisited, o);
                    //timer.pause();
                    if (!v) {
                        visit(o);
                        currentRow = row;
                        return o;
                    }
                } else {
                    if (o->getChar() == DOODLE_CHAR) {
                        //timer.start();
                        bool v = hasVisited(0, numVisited, o);
                        //timer.pause();
                        if (!v) {
                            visit(o);
                            currentRow = row;
                            return o;
                        }
                    }
                }
            }
        }
    }
    if (!doodlesDone) {
        doodlesDone = true;
        currentRow = 0;
        return next();
    }
    return nullptr;
}

void OrganismIter::shiftVisitedRight(int index) {
    for (int i=numVisited-1; i >= index; i--) {
        *(visited+i+1) = *(visited+i);
    }
}

void OrganismIter::visit(Organism* o) {
    if (numVisited == 0) {
        *visited = o;
        numVisited++;
        return;
    }
    if (numVisited < sizeVisited) {
        for (int i=0; i < numVisited; i++) {
            if (o < *(visited+i)) {
                shiftVisitedRight(i);
                *(visited+i) = o;
                numVisited++;
                return;
            }
        }
        *(visited+numVisited) = o;
        numVisited++;
    }
}

bool OrganismIter::hasVisited(int start, int end, Organism* o) {
    if (end - start <= 0) return false;
    if (end - start == 1) return *(visited+start) == o;
    int middle = start + (end-start)/2;
    if (o < *(visited+middle)) return hasVisited(start, middle, o);
    else return hasVisited(middle, end, o);
}

int OrganismIter::getNumVisited() const {
    return numVisited;
}
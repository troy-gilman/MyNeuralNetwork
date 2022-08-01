#pragma once

#include "GridState.hpp"

struct OrganismMove {
    int horizontalMove, verticalMove;

};

class Organism {
    private:
        

    public:
        Organism() {}

        OrganismMove move();
};
#include "Organism.hpp"
#include "Random.hpp"

OrganismMove Organism::move() {
    OrganismMove move;

    move.horizontalMove = Random::randInteger(-3, 4);
    move.verticalMove = Random::randInteger(-3, 4);

    return move;
}


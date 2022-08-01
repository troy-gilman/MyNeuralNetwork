#pragma once

#include <map>
#include "Organism.hpp"
#include "GridState.hpp"

using namespace std;

class Simulation {
    private:
        int m_StepsRemaining;
        map<string, Organism*> m_Organisms;
        GridState m_Grid;

    public:
        Simulation(map<string, Organism*> organisms);

        void start(unsigned int rows, unsigned int cols, unsigned int steps);
        bool step();

        const void draw();
        map<string, Organism*> getOrganisms();
        
};
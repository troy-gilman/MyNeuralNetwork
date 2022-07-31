#pragma once

#include <map>
#include "Organism.hpp"
#include "GameState.hpp"

using namespace std;

class Simulation {
    private:
        int m_StepsRemaining;
        map<string, Organism*> m_Organisms;
        GameState m_State;

    public:
        Simulation(map<string, Organism*> organisms);

        void start(unsigned int rows, unsigned int cols, unsigned int steps);
        bool step();

        const void draw();
        map<string, Organism*> getOrganisms();
        
};
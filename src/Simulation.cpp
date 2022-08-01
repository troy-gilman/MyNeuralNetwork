#include "Simulation.hpp"
#include "Random.hpp"
#include <ncurses.h>

Simulation::Simulation(map<string, Organism*> organisms) 
: m_StepsRemaining(0), m_Organisms(organisms) {
    
}
        
void Simulation::start(unsigned int rows, unsigned int cols, unsigned int steps) {
    vector<string> orgIds;
    for (auto& pair : m_Organisms) orgIds.push_back(pair.first);
    m_Grid = GridState(rows, cols, orgIds);
    m_StepsRemaining = steps;
    // TO-DO
    // make checks to ensure organism are compatible with GridState
}

bool Simulation::step() {
    if (m_StepsRemaining <= 0) return false;
    for (auto& organismPair : m_Organisms) {
        string id = organismPair.first;
        Organism* o = organismPair.second;
        auto oPos = m_Grid.getOrganismPos(id);
        OrganismMove move = o->move();
        m_Grid.moveOrganism(id, oPos.first + move.verticalMove, oPos.second + move.horizontalMove);
    }
    m_StepsRemaining--;
    return true;
}

const void Simulation::draw() {
    for (auto& pair : m_Organisms) {
        auto orgPos = m_Grid.getOrganismPos(pair.first);
        mvprintw(orgPos.first, orgPos.second, "%c", 'X');
    }
}
        
map<string, Organism*> Simulation::getOrganisms() {
    return m_Organisms;
}
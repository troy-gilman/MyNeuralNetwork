#include "Simulation.hpp"
#include "Random.hpp"

Simulation::Simulation(map<string, Organism*> organisms) 
: m_StepsRemaining(0), m_Organisms(organisms) {
    
}
        
void Simulation::start(unsigned int rows, unsigned int cols, unsigned int steps) {
    vector<string> orgIds;
    for (auto& pair : m_Organisms) orgIds.push_back(pair.first);
    m_State = GameState(rows, cols, orgIds);
    m_StepsRemaining = steps;
    // TO-DO
    // make checks to ensure organism are compatible with gamestate
}

bool Simulation::step() {
    if (m_StepsRemaining <= 0) return false;
    for (auto& organismPair : m_Organisms) {
        string id = organismPair.first;
        Organism* o = organismPair.second;
    }
    m_StepsRemaining--;
    return true;
}

const void Simulation::draw() {

}
        
map<string, Organism*> Simulation::getOrganisms() {
    return m_Organisms;
}
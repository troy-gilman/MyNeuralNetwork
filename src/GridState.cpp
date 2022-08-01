#include "GridState.hpp"
#include "Random.hpp"
#include <iostream>

GridState::GridState(unsigned int rows, unsigned int cols, vector<string> organisms)
: m_Rows(rows), m_Cols(cols) {
    for (string& id : organisms) {
        addOrganism(id);
    }
    //cout << m_Rows << " " << m_Cols << endl;
}

void GridState::addOrganism(string id) {
    if (m_OrgPositions.idExists(id)) throw invalid_argument("An organsim with that id already exists");
    auto pos = getFreeTilePos();
    m_OrgPositions.set(id, pos.first, pos.second);
}

void GridState::moveOrganism(string id, unsigned int row, unsigned int col) {
    if (!m_OrgPositions.idExists(id)) throw invalid_argument("The specified organism id does not exist");
    if (row >= m_Rows || col >= m_Cols) return;
    m_OrgPositions.set(id, row, col);
}

pair<unsigned int, unsigned int> GridState::getOrganismPos(string id) {
    if (!m_OrgPositions.idExists(id)) throw invalid_argument("The specified organism id does not exist");
    return m_OrgPositions.getPosOf(id);
}

pair<int, int> GridState::getFreeTilePos() {
    int row, col;
    int counter = 0;
    do {
        if (counter > 100) throw runtime_error("Exceeded limit of free tile position attempts");
        row = Random::randInteger(0, m_Rows);
        col = Random::randInteger(0, m_Cols);
        counter++;
    } while (m_OrgPositions.getIdAt(row, col) != "");
    return pair{ row, col };
}

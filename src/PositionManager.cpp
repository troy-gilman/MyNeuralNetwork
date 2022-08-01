#include "PositionManager.hpp"
#include <iostream>

PositionManager::PositionManager() {
    m_IdMap.clear();
    m_PosMap.clear();
}
        
void PositionManager::set(string id, unsigned int row, unsigned int col) {
    if (id == "") throw invalid_argument("Invalid id");

    string pos = encodePos(row, col);

    if (posExists(pos)) return;

    if (idExists(id)) m_PosMap.erase(m_IdMap[id]);

    m_IdMap[id] = pos;
    m_PosMap[pos] = id;
}

void PositionManager::clearId(string id) {
    if (!idExists(id)) throw invalid_argument("ID does not exist");
    string sPos = m_IdMap[id];
    m_PosMap.erase(sPos);
    m_IdMap.erase(id);
}

void PositionManager::clearPos(unsigned int row, unsigned int col) {
    string pos = encodePos(row, col);
    if (!posExists(pos)) return;
    string id = m_PosMap[pos];
    m_IdMap.erase(id);
    m_PosMap.erase(pos);
}

pair<unsigned int, unsigned int> PositionManager::getPosOf(string id) {
    if (!idExists(id)) throw invalid_argument("ID does not exist");
    pair<unsigned int, unsigned int> pos = decodePos(m_IdMap[id]);
    return pos;
}
        
        
string PositionManager::getIdAt(unsigned int row, unsigned int col) {
    string pos = encodePos(row, col);
    if (!posExists(pos)) return "";
    string id = m_PosMap[pos];
    return id;
}

bool PositionManager::posExists(string pos) {
    return m_PosMap.find(pos) != m_PosMap.end();
}

bool PositionManager::idExists(string id) {
    return m_IdMap.find(id) != m_IdMap.end();
}

string PositionManager::encodePos(unsigned int row, unsigned int col) {
    return to_string(row) + "," + to_string(col);
}

pair<unsigned int, unsigned int> PositionManager::decodePos(string pos) {
    auto delimIt = pos.find(",");
    string sRow = pos.substr(0, delimIt);
    string sCol = pos.substr(delimIt+1, pos.length() - delimIt);
    unsigned int row = stoul(sRow);
    unsigned int col = stoul(sCol);
    return pair{ row, col };
}


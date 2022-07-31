#pragma once

#include "PositionManager.hpp"
#include "Organism.hpp"
#include <vector>

using namespace std;

class GameState {
    private:
        int m_Rows;
        int m_Cols;
        PositionManager m_OrgPositions;

    public:
        GameState() {}
        GameState(unsigned int rows, unsigned int cols, vector<string> organisms);

        void addOrganism(string id);
        void moveOrganism(string id, unsigned int row, unsigned int col);

    private:
        pair<int, int> getFreeTilePos();
};
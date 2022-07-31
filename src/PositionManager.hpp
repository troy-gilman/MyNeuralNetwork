#pragma once

#include <map>
#include <string>

using namespace std;

class PositionManager {
    private:
        map<string, string> m_IdMap, m_PosMap;

    public:
        PositionManager();

        void set(string id, unsigned int row, unsigned int col);
        void clearId(string id);
        void clearPos(unsigned int row, unsigned int col);

        pair<unsigned int, unsigned int> getPosOf(string id);
        string getIdAt(unsigned int row, unsigned int col);
        bool idExists(string id);

    private:
        bool posExists(string pos);
        string encodePos(unsigned int row, unsigned int col);
        pair<unsigned int, unsigned int> decodePos(string pos);
        

};
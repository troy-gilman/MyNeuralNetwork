#pragma once

#include <vector>

using namespace std;

class LinearLayer {
    private:
        unsigned int m_InChannnels, m_OutChannels;
        vector<vector<float>> m_Params;

    public:
        LinearLayer(unsigned int inChannels, unsigned int outChannels);

        vector<float> forward(vector<float> x);
};
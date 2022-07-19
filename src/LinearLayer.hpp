#pragma once

#include "Array.hpp"
#include <vector>

using namespace std;

class LinearLayer {
    private:
        int m_InChannnels, m_OutChannels;
        Array m_Params;

    public:
        LinearLayer(int inChannels, int outChannels);

        Array forward(Array x);
        Array getParams();
};
#pragma once

#include "ArrayF.hpp"
#include <vector>

using namespace std;

class LinearLayer {
    private:
        int m_InChannnels, m_OutChannels;
        ArrayF m_Params;

    public:
        LinearLayer(int inChannels, int outChannels);

        ArrayF forward(ArrayF x);
        ArrayF getParams();
};
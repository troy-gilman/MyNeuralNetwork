#pragma once

#include "Matrix.hpp"
#include <vector>

using namespace std;

class LinearLayer {
    private:
        int m_InChannnels, m_OutChannels;
        Matrix m_Params;

    public:
        LinearLayer(int inChannels, int outChannels);

        Matrix forward(Matrix x);
        Matrix getParams();
};
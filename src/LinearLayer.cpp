#include "LinearLayer.hpp"

#include <random>

float randFloat() {
    return rand() / static_cast<float>(RAND_MAX);
}

LinearLayer::LinearLayer(unsigned int inChannels, unsigned int outChannels) : m_InChannnels(inChannels), m_OutChannels(outChannels) {
    m_Params.assign(outChannels, vector<float>(inChannels + 1, 0.0f));
    for (int outIdx = 0; outIdx < m_OutChannels; outIdx++) {
        for (int inIdx = 0; inIdx < m_InChannnels + 1; inIdx++)
            m_Params[outIdx][inIdx] = randFloat();
    }
}

vector<float> LinearLayer::forward(vector<float> x) {
    if (x.size() != m_InChannnels) {
        printf("Incorrect number of channels %d != %d\n", x.size(), m_InChannnels);
        return vector<float>();
    }
    vector<float> out(m_OutChannels);
    for (int outIdx = 0; outIdx < m_OutChannels; outIdx++) {
        out[outIdx] = 0.0;
        for (int inIdx = 0; inIdx < m_InChannnels; inIdx++)
            out[outIdx] += x[inIdx] * m_Params[outIdx][inIdx];
        out[outIdx] += m_Params[outIdx][m_InChannnels];
    }
    return out;
}
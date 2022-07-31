#include "LinearLayer.hpp"



float randFloat() {
    return rand() / static_cast<float>(RAND_MAX);
}

LinearLayer::LinearLayer(int inChannels, int outChannels) : m_InChannnels(inChannels), m_OutChannels(outChannels) {
    m_Params = ArrayF(vector<int>{ outChannels, inChannels + 1 });
    for (int outIdx = 0; outIdx < m_OutChannels; outIdx++) {
        for (int inIdx = 0; inIdx < m_InChannnels + 1; inIdx++)
            m_Params.at(vector<int>{ outIdx, inIdx }) = randFloat();
    }
}

ArrayF LinearLayer::forward(ArrayF x) {
    int batchSize = x.size()[0];
    if (batchSize == 0) {
        printf("Recieved empty vector\n");
        return ArrayF();
    }

    ArrayF out(vector<int>{ batchSize, m_OutChannels });

    for (int dataIdx = 0; dataIdx < batchSize; dataIdx++) {
        if (x.size()[1] != m_InChannnels) {
            printf("Incorrect number of data dimensions %d != %d\n", x.size()[1], m_InChannnels);
            return ArrayF();
        }
        for (int outIdx = 0; outIdx < m_OutChannels; outIdx++) {
            out.at(vector<int>{ dataIdx, outIdx }) = m_Params.at(vector<int>{ outIdx, m_InChannnels});
            for (int inIdx = 0; inIdx < m_InChannnels; inIdx++) {
                out.at(vector<int>{ dataIdx, outIdx }) += x.at(vector<int>{ dataIdx, inIdx }) * m_Params.at(vector<int>{ outIdx, inIdx });
            }
        }
    }
    return out;
}

ArrayF LinearLayer::getParams() {
    return m_Params;
}
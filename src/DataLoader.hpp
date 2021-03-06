#pragma once

#include "ArrayF.hpp"

#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class DataLoader {
    private:
        ArrayF m_Dataset;
        int m_BatchSize, m_BatchIdx;

    public:
        DataLoader(ArrayF dataset, unsigned int batchSize) : m_Dataset(dataset), m_BatchSize(batchSize), m_BatchIdx(0) {};

        ArrayF next();

        static ArrayF loadImages(string& path);

};
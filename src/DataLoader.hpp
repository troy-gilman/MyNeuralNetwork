#pragma once

#include "Array.hpp"

#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class DataLoader {
    private:
        Array m_Dataset;
        int m_BatchSize, m_BatchIdx;

    public:
        DataLoader(Array dataset, unsigned int batchSize) : m_Dataset(dataset), m_BatchSize(batchSize), m_BatchIdx(0) {};

        Array next();

        static Array loadImages(string& path);

};
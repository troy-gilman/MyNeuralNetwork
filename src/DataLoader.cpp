#include "DataLoader.hpp"
#include "Matrix.hpp"

#include <filesystem>
#include <opencv2/highgui.hpp>

namespace fs = std::filesystem;

Matrix DataLoader::next() {
    int dataIdx = m_BatchIdx * m_BatchIdx;
    if (dataIdx >= m_Dataset.size()[0]) {
        m_BatchIdx = 0;
        return Matrix();
    }

    int range[] = { dataIdx, min(dataIdx + m_BatchSize, m_Dataset.size()[0]) };
    Matrix out = m_Dataset.slice(range[0], range[1]);
    m_BatchIdx++;
    return out;
}

Matrix DataLoader::loadImages(string& path) {
    Matrix dataset;
    for (const auto& entry : fs::directory_iterator(path)) {

        Mat img = imread(entry.path());
        if (img.data == NULL) {
            printf("No image data\n");
            return dataset;
        }
        
        if (img.isContinuous()) {
            img.convertTo(img, 5);
            resize(img, img, Size(32, 32), 0, 0, INTER_CUBIC);
            img = img.reshape(1, vector<int>{ 1, 32 * 32 * 3 });
            //printf("%d %d %d %d\n", img.dims, img.size[0], img.size[1], img.channels());
            
            img = img / 255.0f;
            vector<float> imgVector;
            imgVector.assign((float*) img.data, (float*) img.data + img.rows * img.cols * img.channels());
            Matrix matrix(imgVector);
            dataset.append(matrix);
            printf("Loaded %s from file\n", entry.path().c_str());
        } else {
            printf("Data is not continuous\n");
        }
        
    }
    return dataset;
}

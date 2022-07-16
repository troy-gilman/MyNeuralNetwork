#include "DataLoader.hpp"

#include <opencv2/opencv.hpp>
#include <filesystem>

namespace fs = std::filesystem;


vector<vector<float>> DataLoader::load(string& path) {
    vector<vector<float>> dataset;
    for (const auto& entry : fs::directory_iterator(path)) {

        cv::Mat img = cv::imread(entry.path());
        if (!img.data) {
            printf("No image data\n");
            return dataset;
        }
        
        if (img.isContinuous()) {
            img.convertTo(img, 5);
            cv::resize(img, img, cv::Size(32, 32), 0, 0, cv::INTER_CUBIC);
            vector<float> imgVector;
            imgVector.assign((float*) img.data, (float*) img.data + img.total() * img.channels());
            transform(imgVector.begin(), imgVector.end(), imgVector.begin(), [](float& f){ return f/255.0f; });
            dataset.push_back(imgVector);
        } else {
            printf("Data is not continuous\n");
        }
        
    }

    return dataset;
}

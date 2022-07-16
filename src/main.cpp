#include "LinearLayer.hpp"
#include "DataLoader.hpp"
#include "Matrix.hpp"
#include "iostream"
#include "random"
#include "ctime"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    srand(time(NULL));

    int batchSize = 64;
    int imgSize = 32;
    int imgChannels = 3;

    string dataPath = "../../Pokemon-GAN/real_data/";
    Matrix dataset = DataLoader::loadImages(dataPath);
    cout << dataset.size()[0] << " " << dataset.size()[1] << endl;
    DataLoader dataloader(dataset, batchSize);

    LinearLayer layer1(imgSize * imgSize * imgChannels, 3);

    Matrix x = dataloader.next();
    while (!x.empty()) {
        Matrix out = layer1.forward(x);
        //cout << out.toString() << endl;
        x = dataloader.next();
    }

    cout << endl;
    Matrix::unitTests();
}
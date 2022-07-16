#include "LinearLayer.hpp"
#include "DataLoader.hpp"
#include "iostream"
#include "random"
#include "ctime"

using namespace std;

int main() {
    srand(time(NULL));

    string dataPath = "../Pokemon-GAN/real_data/";
    vector<vector<float>> dataset = DataLoader::load(dataPath);
    cout << dataset.size() << endl;

    LinearLayer layer1(32 * 32 * 3, 1);

    for (auto& x : dataset) {
        x = layer1.forward(x);

        cout << x.size() << " " << x[0] << endl;

    }

    return 0;
}
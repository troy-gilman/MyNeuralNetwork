#pragma once

#include <vector>
#include <string>

using namespace std;

class ArrayF {
    private:
        vector<float> m_Data;
        vector<int> m_Size;

        int getIdx(vector<int> pos);
        

    public:
        ArrayF();
        ArrayF(vector<float> data);
        ArrayF(vector<int> size);
        ArrayF(vector<float> data, vector<int> size);

        float& at(vector<int> pos);
        void append(ArrayF m);
        const ArrayF slice(int begin, int end);

        const vector<int> size();
        const vector<float> data();
        const bool empty();
        const string toString();

        static bool unitTests();
};

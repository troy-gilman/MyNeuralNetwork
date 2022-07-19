#pragma once

#include <vector>
#include <string>

using namespace std;

class Array {
    private:
        vector<float> m_Data;
        vector<int> m_Size;

        int getIdx(vector<int> pos);
        

    public:
        Array();
        Array(vector<float> data);
        Array(vector<int> size);
        Array(vector<float> data, vector<int> size);

        float& at(vector<int> pos);
        Array slice(int begin, int end);
        void append(Array m);

        vector<int> size();
        vector<float> data();
        bool empty();
        string toString();

        static bool unitTests();
};

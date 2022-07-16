#pragma once

#include <vector>
#include <string>

using namespace std;

class Matrix {
    private:
        vector<float> m_Data;
        vector<int> m_Size;

        int getIdx(vector<int> pos);
        

    public:
        Matrix();
        Matrix(vector<float> data);
        Matrix(vector<int> size);
        Matrix(vector<float> data, vector<int> size);

        float& at(vector<int> pos);
        Matrix slice(int begin, int end);
        void append(Matrix m);

        vector<int> size();
        vector<float> data();
        bool empty();
        string toString();

        static bool unitTests();
};

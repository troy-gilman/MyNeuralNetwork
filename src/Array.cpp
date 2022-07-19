#include "Array.hpp"

#include <stdexcept>
using namespace std;

Array::Array() {
    m_Size = vector<int>{ 0 };
}

Array::Array(vector<float> data) : m_Data(data) {
    m_Size = vector<int>{ (int) data.size() };
}

Array::Array(vector<int> size) : m_Size(size) {
    int totalItems = 1;
    for (auto& dimSize : size) totalItems *= dimSize;
    m_Data = vector<float>(totalItems, 0.0f);
}

Array::Array(vector<float> data, vector<int> size) : m_Data(data), m_Size(size) {}

int Array::getIdx(vector<int> pos) {
    if (pos.size() != m_Size.size())
        throw invalid_argument("Position does not have the correct number of dimensions");
    int idx = pos[pos.size()-1];
    int blockLength = m_Size[m_Size.size()-1];
    for (int dimIdx = pos.size()-2; dimIdx >= 0; dimIdx--) {
        idx += pos[dimIdx] * blockLength;
        blockLength *= m_Size[dimIdx];
    }
    return idx;
}

float& Array::at(vector<int> pos) {
    int idx = getIdx(pos);
    return m_Data[idx];
}

Array Array::slice(int begin, int end) {
    vector<int> beginPos(m_Size.size(), 0);
    vector<int> endPos(m_Size.size(), 0);
    beginPos[0] = begin;
    endPos[0] = end;
    int beginIdx = getIdx(beginPos);
    int endIdx = getIdx(endPos);
    vector<float> newData(m_Data.begin() + beginIdx, m_Data.begin() + endIdx);
    vector<int> newSize(m_Size);
    newSize[0] = end - begin;
    return Array(newData, newSize);
}

void Array::append(Array m) {
    vector<float> newData = m.data();
    vector<int> newSize = m.size();
    if (!m_Size[0] && m.size()[0]) {
        m_Data = newData;
        m_Size = newSize;
        m_Size.insert(m_Size.begin(), 1);
    } else if (m.size() == vector<int>(m_Size.begin() + 1, m_Size.end())) {
        m_Data.insert(m_Data.begin(), newData.begin(), newData.end());
        m_Size[0]++;
    } else {
        throw invalid_argument("Input Array was not appendible to this Array");
    }
}

vector<int> Array::size() {
    return m_Size;
}

vector<float> Array::data() {
    return m_Data;
}

bool Array::empty() {
    return m_Size[0] == 0;
}

string Array::toString() {
    vector<int> pos(m_Size.size(), 0);
    string str;
    int dimIdx = 0;
    str += "Array([";

    while (true) {
        if (dimIdx == pos.size()-1) {
            str += to_string(at(pos));
            if (pos[dimIdx] != m_Size[dimIdx] - 1)
                str += ", ";
            pos[dimIdx]++;
        } else {
            str += "[";
            dimIdx++;
        }

        if (pos[dimIdx] == m_Size[dimIdx]) {
            while (pos[dimIdx] == m_Size[dimIdx]) {
                pos[dimIdx] = 0;
                dimIdx--;
                if (dimIdx < 0) break;
                pos[dimIdx]++;
                str += "]";
            }
            if (dimIdx < 0) break;
            str += ",\n\t";
            str += string(dimIdx, ' ');
        }
    }

    str += "])\n";
    return str;
}

bool Array::unitTests() {
    vector<float> nums = {
        0.1, 0.2, 
        0.3, 0.4, 
        0.5, 0.6,
        0.7, 0.8, 
    };
    Array mat(nums, vector<int>{ 2, 2, 2 });
    printf("%s\n", mat.toString().c_str());
    return true;
}
#pragma once

#include <string>

using namespace std;

static const string idChars = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

class Random {
    public:
        static const void init();
        static const float randFloat(float min, float max); // [min, max)
        static const int randInteger(int min, int max);     // [min, max)
        static const string randId(unsigned int len);
};
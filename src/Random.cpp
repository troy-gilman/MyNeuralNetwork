#include "Random.hpp"

#include <random>
#include "ctime"

const void Random::init() {
    srand(time(NULL));
}

const float Random::randFloat(float min, float max) {
    return min + (max - min) * (rand() / static_cast<float>(RAND_MAX));
}

const int Random::randInteger(int min, int max) {
    return static_cast<int>(randFloat(static_cast<float>(min), static_cast<float>(max)));
}

const string Random::randId(unsigned int len) {
    string id;
    for (int i = 0; i < len; i++) {
        id += idChars[randInteger(0, idChars.length())];
    }
    return id;
}
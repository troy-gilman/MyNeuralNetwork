//
// Created by Troy Gilman on 31/3/2022.
//

#include <chrono>
#include <thread>
#include "Timer.h"
using namespace std::chrono;

void Timer::sleep(int ms) {
    std::this_thread::sleep_for(milliseconds(ms));
}

void Timer::start() {
    startTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    paused = false;
}

void Timer::pause() {
    auto pauseTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    duration += double(pauseTime - startTime) / 1000.0;
    paused = true;
}

double Timer::stop() {
    if (!paused) {
        auto endTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        duration += double(endTime - startTime) / 1000.0;
    }
    double d = duration;
    duration = 0;
    startTime = 0;
    return d;
}

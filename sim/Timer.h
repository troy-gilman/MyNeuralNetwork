//
// Created by Troy Gilman on 31/3/2022.
//

#ifndef CS3520_SPRING_2022_TIMER_H
#define CS3520_SPRING_2022_TIMER_H


class Timer {
private:
    long startTime;
    double duration;
    bool paused;

public:
    Timer(): startTime(0), duration(0), paused(false) {}

    void sleep(int ms);
    void start();
    void pause();
    double stop();
};


#endif //CS3520_SPRING_2022_TIMER_H

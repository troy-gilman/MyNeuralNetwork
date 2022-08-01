#include "iostream"
#include "Random.hpp"
#include "Simulation.hpp"
#include "Organism.hpp"
#include <ncurses.h>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    Random::init();

    initscr();
    nodelay(stdscr, TRUE);
    noecho();

    int orgN = 100;
    map<string, Organism*> organisms;

    for (int i = 0; i < orgN; i++) {
        Organism* o = new Organism();
        string id;
        do {
            id = Random::randId(8);
        } while (organisms.find(id) != organisms.end());
        organisms[id] = o;
    }

    Simulation sim(organisms);
    sim.start(20, 40, 1000);
    while (sim.step()) {
        clear();
        sim.draw();
        refresh();
        this_thread::sleep_for(chrono::milliseconds(10));
    }
    endwin();
}
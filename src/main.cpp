#include "iostream"
#include "Random.hpp"
#include "Simulation.hpp"
#include "Organism.hpp"

using namespace std;

int main() {
    Random::init();

    int orgN = 10;
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
    sim.start(30, 30, 10);
    while (sim.step()) {
        cout << "step" << endl; 
    }
}
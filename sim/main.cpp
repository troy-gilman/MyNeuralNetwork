//
// Created by Troy Gilman on 29/3/2022.
//

#include <cstring>
#include <ncurses.h>
#include <iostream>
#include <vector>
#include "Timer.h"
#include "Grid.h"
#include "Ant.h"
#include "DoodleBug.h"
#include "OrganismIter.h"
using namespace std;

int NUM_ANTS = 99;
int NUM_DOODLES = 11;
int GRID_ROWS = 30;
int GRID_COLS = 30;
int ROUNDS = 1000;
int SLEEP_TIME = 100;


int read_escape() {
    int c;
    if ((c = getch()) == ERR) {
        return -1;
    }
    return c;
}


void endSim(size_t ants, size_t doodles) {
    endwin();
    cout << "Ants: " << ants << endl;
    cout << "DoodleBugs: " << doodles << endl;
    exit(0);
}


void runSim(Grid* grid, bool automatic, int rounds) {
    vector<Organism*> ants;
    vector<Organism*> doodles;
    Timer timer;

    for (int i=0; i < rounds; i++) {
        if (automatic) timer.sleep(SLEEP_TIME);
        do {
            int c;
            if ((c = read_escape()) == 'q') {
                endSim(ants.size(), doodles.size());
            } else if (c == 10) {
                break;
            }
        } while (!automatic);

        timer.start();
        OrganismIter iter = OrganismIter(grid);
        Organism* o;
        while ((o = iter.next()) != nullptr) {
            o->move();
        }

        ants.erase(ants.begin(), ants.end());
        doodles.erase(doodles.begin(), doodles.end());
        for (int row=0; row < grid->shape().first; row++) {
            for (int col = 0; col < grid->shape().first; col++) {
                if (!grid->isEmpty(row, col)) {
                    o = static_cast<Organism *>(grid->get(row, col));
                    if (o->getChar() == ANT_CHAR) {
                        ants.push_back(o);
                    }
                    if (o->getChar() == DOODLE_CHAR) {
                        doodles.push_back(o);
                    }
                }
            }
        }

        clear();
        grid->display();
        mvprintw(0, 2 * grid->shape().second + 5, "Round: %d", i + 1);
        mvprintw(1, 2 * grid->shape().second + 5, "Ants: %d", ants.size());
        mvprintw(2, 2 * grid->shape().second + 5, "DoodleBugs: %d", doodles.size());
        mvprintw(3, 2 * grid->shape().second + 5, "Processing Time: %f", timer.stop());
        refresh();
        if (ants.empty() || doodles.empty()) break;
    }
    endSim(ants.size(), doodles.size());
}

int main(int argc, char *argv[]) {
    bool automatic = true;
    if (argc >= 2) {
        if (strcmp(argv[1], "-m") == 0) automatic = false;
    }

    initscr();
    nodelay(stdscr, TRUE);
    noecho();

    Grid* grid = new Grid(GRID_ROWS, GRID_COLS);

    for (int i=0; i < NUM_ANTS; i++) {
        new Ant(grid);
    }
    for (int i=0; i < NUM_DOODLES; i++) {
        new DoodleBug(grid);
    }

    grid->display();
    mvprintw(0, 2 * grid->shape().second + 5, "Round: %d", 0);
    mvprintw(1, 2 * grid->shape().second + 5, "Ants: %d", NUM_ANTS);
    mvprintw(2, 2 * grid->shape().second + 5, "DoodleBugs: %d", NUM_DOODLES);
    refresh();

    runSim(grid, automatic, ROUNDS);
}
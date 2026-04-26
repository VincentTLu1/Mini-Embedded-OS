#include <iostream>
using namespace std;

static int tickCount = 0;

bool schedule();
void runCurrentTask();
void updateDelays();
void idleTask();

//Simulates "time" using ticks
void tick() {
    tickCount++;
    std::cout << "[TIMER] TICK " << tickCount << "\n";

    updateDelays();

    // ONLY run task if scheduler found one
    if (schedule()) {
        runCurrentTask();
    }
    else{
        idleTask();
    }
}
#include <iostream>
#include "scheduler.h"
using namespace std;

static int tickCount = 0;

bool schedule();
void runCurrentTask();
void updateDelays();
void idleTask();
void addAging();
bool willPreempt();

//Simulates "time" using ticks
void tick() {
    tickCount++;
    std::cout << "[TIMER] TICK " << tickCount << "\n";

    updateDelays();

    addAging();

    // ONLY run task if scheduler found one
    if (willPreempt()){
        if (schedule()) {
            runCurrentTask();
        }
        else{
            idleTask();
        } 
    }

    else{
        std::cout << "[TASK "
            << tasks[currentTask].id
            << "] continues running\n";

        runCurrentTask();
    }
}
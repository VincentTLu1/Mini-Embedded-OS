#include <iostream>
#include <thread>
#include <chrono>
#include "gpio.h"

using namespace std;

void addTask(void (*func)(), int priority);
void schedule();
void runCurrentTask();
void tick();
void sleepCurrentTask(int ticks);
void setTaskDelay(int taskId, int ticks);
void idleTask();

void task1(){
    cout << "Task 1 executing\n";
    LED1.toggle();

    //Set a fast delay
    setTaskDelay(0, 5);
};

void task2(){
    cout << "Task 2 executing\n";
    LED2.toggle();

    //Set a slow delay
    setTaskDelay(1, 5);
};

int main() {
    addTask(task1, 2);
    addTask(task2, 1);

    while (true){
        tick();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
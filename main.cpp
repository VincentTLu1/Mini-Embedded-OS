#include <iostream>
#include <thread>
#include <chrono>
#include "gpio.h"

using namespace std;

void addTask(void (*func)());
void schedule();
void runCurrentTask();
void tick();
void sleepCurrentTask(int ticks);

void task1(){
    cout << "Task 1 executing\n";
    LED1.toggle();
};

void task2(){
    cout << "Task 2 executing\n";
    LED2.toggle();
};

int main() {
    addTask(task1);
    addTask(task2);

    while (true){
        tick();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void addTask(void (*func)());
void schedule();
void runCurrentTask();
void tick();
void sleepCurrentTask(int ticks);

void task1(){
    cout << "Task 1 executing\n";

};

void task2(){
    cout << "Task 2 executing\n";
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
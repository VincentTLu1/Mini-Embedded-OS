#include <iostream>
using namespace std;

void addTask(void (*func)());
void schedule();
void runCurrentTask();

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
        schedule();
        runCurrentTask();
    }

    return 0;
}
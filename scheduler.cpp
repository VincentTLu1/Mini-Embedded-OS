#include <vector>
#include <iostream>


// The different task states: Ready, Running, Stopped
enum TaskState{
    READY,
    RUNNING,
};

// struct for a task
struct Task{
 int id;
 TaskState state;
 void (*taskFunc)();
};

std::vector<Task> tasks;
int currentTask = -1;

// Add a task to the scheduler function
void addTask(void (*func)()){
    Task t;
    t.state = READY;
    t.id = tasks.size();
    t.taskFunc = func;
    tasks.push_back(t);
}

// Main schedule function 
void schedule(){
    if (tasks.empty()) return;

    currentTask = (currentTask + 1) % tasks.size();

    std::cout << "[SCHEDULER] Switching to Task " << currentTask << "\n";
}

// Run the current task
void runCurrentTask(){
    if (currentTask < 0 || currentTask >= tasks.size()) return;

    Task &t = tasks[currentTask];

    t.state = RUNNING;
    std::cout << "[TASK " << t.id << "] is Running\n";

    t.taskFunc();

    t.state = READY;
}


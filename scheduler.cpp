#include <vector>
#include <iostream>

const int TIME_SLICE = 2;

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
 int delay;
};

std::vector<Task> tasks;
int currentTask = -1;

// Add a task to the scheduler function
void addTask(void (*func)()){
    Task t;
    t.delay = 0;
    t.state = READY;
    t.id = tasks.size();
    t.taskFunc = func;
    tasks.push_back(t);
}

// Main schedule function 
bool schedule() {
    if (tasks.empty()) return false;

    int start_task = currentTask;
    int attempt = 0;

    do {
        currentTask = (currentTask + 1) % tasks.size();
        attempt++;

        if (tasks[currentTask].delay == 0) {
            std::cout << "[SCHEDULER] Switching to Task " << currentTask << "\n";
            return true;
        }

    } while (attempt < tasks.size());

    std::cout << "[SCHEDULER] No runnable tasks at the moment\n";
    currentTask = start_task;
    return false;
}


// Run the current task (current task is an index)
void runCurrentTask(){
    if (currentTask < 0 || currentTask >= tasks.size()) return;

    Task &t = tasks[currentTask];

    t.state = RUNNING;
    std::cout << "[TASK " << t.id << "] is Running\n";

    t.taskFunc();

    t.state = READY;

    t.delay = TIME_SLICE;
}

void updateDelays(){
    for (auto& task : tasks){
        if (task.delay > 0){
            task.delay -= 1;
        }
    }
}

void sleepCurrentTask(int ticks) {
    if (currentTask < 0) return;
    tasks[currentTask].delay = ticks;
}

void setTaskDelay(int taskId, int ticks) {
    if (taskId < 0 || taskId >= tasks.size()) return;
    tasks[taskId].delay = ticks;
}


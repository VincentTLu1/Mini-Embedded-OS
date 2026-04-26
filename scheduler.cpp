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
 int priority;
};

std::vector<Task> tasks;
int currentTask = -1;

// Add a task to the scheduler function
void addTask(void (*func)(), int priority){
    Task t;
    t.delay = 0;
    t.state = READY;
    t.id = tasks.size();
    t.taskFunc = func;
    t.priority = priority;
    tasks.push_back(t);
}

// Main schedule function 
bool schedule() {
    if (tasks.empty()) return false;

    int prio_task = INT_MAX;

    //Figure out the mst optimal priority for the system
    for (int i = 0; i < tasks.size(); i++){
        if (tasks[i].delay == 0){
            if (tasks[i].priority < prio_task){
                prio_task = std::min(prio_task, tasks[i].priority);
            }
        }
    }

    if (prio_task == INT_MAX){
        std::cout << "[SCHEDULER] No runnable tasks at the moment\n";
        return false;
    }
    
    int start_task = currentTask;
    int attempt = 0;
    //Round Robin within priority
    do {
        currentTask = (currentTask + 1) % tasks.size();
        attempt++;

        if (tasks[currentTask].delay == 0 && tasks[currentTask].priority == prio_task) {
            std::cout << "[SCHEDULER] Switching to Task " << tasks[currentTask].id << "\n";
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

void idleTask(){
    std::cout << "[IDLE] Current CPU is idle\n";
}


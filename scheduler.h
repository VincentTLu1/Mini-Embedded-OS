#pragma once

#include <vector>

// Task states
enum TaskState{
    READY,
    RUNNING,
};

// Task structure
struct Task{
    int id;
    TaskState state;

    void (*taskFunc)();

    int delay;

    int priority;
    int basePriority;

    int timeSlice;
};

// globals
extern std::vector<Task> tasks;
extern int currentTask;

// scheduler functions
bool schedule();

void runCurrentTask();

void updateDelays();

void idleTask();

void addAging();

bool willPreempt();

void addTask(void (*func)(), int priority);

void setTaskDelay(int taskId, int ticks);
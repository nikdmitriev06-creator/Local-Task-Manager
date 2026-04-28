#pragma once
#include <unordered_map>
#include "task.h"
#include <iostream>
#include <queue>
#include "execution_engine.h"
#include "thread_pool.h"

class TaskManager
{
    std::unordered_map<int, Task> tasks;
    int next_id = 0;
    std::queue<int> TasksQueue;
    ThreadPool pool;
    bool Started = false;

    std::string StatusToText(TaskStatus status);

public:

    TaskManager(size_t ThreadsNum);

    void CreateTask(std::string type, std::string payload);
    void start();

    int GetQueueSize();
    int GetIdFromQueue();
    void PopIdOfQueue();

    Task *GetTask(int id);

    void ListTasks();
};
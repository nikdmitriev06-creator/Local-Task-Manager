#pragma once
#include <unordered_map>
#include "task.h"
#include <iostream>
#include <queue>
#include "execution_engine.h"

class TaskManager
{
    std::unordered_map<int, Task> tasks;
    int next_id = 0;
    std::queue<int> TasksQueue;

    std::string StatusToText(TaskStatus status);

public:

    TaskManager();

    void CreateTask(std::string type, std::string payload);

    int GetQueueSize();
    int GetIdFromQueue();
    void PopIdOfQueue();

    Task *GetTask(int id);

    void ListTasks();
};
#pragma once
#include <unordered_map>
#include "task.h"
#include <iostream>
#include <queue>


class taskManager
{
    std::unordered_map<int, Task> tasks;
    int next_id = 0;
    std::queue<int> tasksQueue;

    std::string statusToText(taskStatus status);

public:

    taskManager();

    void createTask(std::string type, std::string payload);

    std::string* getType(int id);

    int getQueueSize();
    int getIdFromQueue();
    void PopIdOfQueue();

    Task *getTask(int id);



    void listTasks();
};
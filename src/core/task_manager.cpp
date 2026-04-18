#pragma once
#include "task_manager.h"


std::string taskManager::statusToText(taskStatus status)
{
    switch (status)
    {
    case taskStatus::Created :
        return "Created";

    case taskStatus::Done :
        return "Done";

    case taskStatus::Running :
        return "Running";

    case taskStatus::Failed:
        return "Failed";
    default:
        return "Unknown";
    }
}

taskManager::taskManager()
{

}

void taskManager::createTask(std::string type, std::string payload)
{
    Task task;
    task.id = next_id;
    task.payload = payload;
    task.type = type;
    task.status = taskStatus::Created;
    tasks[next_id] = task;
    tasksQueue.push(next_id);
    next_id++;
}

std::string *taskManager::getType(int id)
{
    if(tasks.find(id) != tasks.end())
    {
        return &tasks[id].type;
    } else return nullptr;
}

int taskManager::getQueueSize()
{
    return tasksQueue.size();
}

int taskManager::getIdFromQueue()
{
    return tasksQueue.front();
}

void taskManager::PopIdOfQueue()
{
    tasksQueue.pop();
}

Task *taskManager::getTask(int id)
{
    if(tasks.find(id) != tasks.end())
    {
        return &tasks[id];
    } else return nullptr;
}

void taskManager::listTasks()
{
    for(const auto& pairs : tasks)
    {
        const Task& task = pairs.second;
        std::cout << "task id: " << task.id;
        std::cout << "\ntask type: " << task.type;
        std::cout << "\ntask payload: " << task.payload;
        std::cout << "\ntask status: " << statusToText(task.status);
    }
}

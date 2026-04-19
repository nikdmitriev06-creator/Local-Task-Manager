#include "task_manager.h"


std::string TaskManager::StatusToText(TaskStatus status)
{
    switch (status)
    {
    case TaskStatus::Created :
        return "Created";

    case TaskStatus::Done :
        return "Done";

    case TaskStatus::Running :
        return "Running";

    case TaskStatus::Failed:
        return "Failed";
    default:
        return "Unknown";
    }
}

TaskManager::TaskManager()
{

}

void TaskManager::CreateTask(std::string type, std::string payload)
{
    Task task;
    task.id = next_id;
    task.payload = payload;
    task.type = type;
    task.status = TaskStatus::Created;
    tasks[next_id] = task;
    TasksQueue.push(next_id);
    next_id++;
}

int TaskManager::GetQueueSize()
{
    return TasksQueue.size();
}

int TaskManager::GetIdFromQueue()
{
    return TasksQueue.front();
}

void TaskManager::PopIdOfQueue()
{
    TasksQueue.pop();
}

Task *TaskManager::GetTask(int id)
{
    if(tasks.find(id) != tasks.end())
    {
        return &tasks[id];
    } else return nullptr;
}

void TaskManager::ListTasks()
{
    for(const auto& pairs : tasks)
    {
        const Task& task = pairs.second;
        std::cout << "task id: " << task.id;
        std::cout << "\ntask type: " << task.type;
        std::cout << "\ntask payload: " << task.payload;
        std::cout << "\ntask status: " << StatusToText(task.status);
    }
}

#include <unordered_map>
#include "task.h"
#include <iostream>

class taskManager
{
    std::unordered_map<int, Task> tasks;
    int next_id = 0;

    std::string statusToText(taskStatus status);

public:
    taskManager();

    void createTask(std::string type, std::string payload);

    std::string* getType(int id);

    Task *getTask(int id);

    void listTasks();
};
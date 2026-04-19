#pragma once
#include <string>

enum class TaskStatus
{
    Created,
    Running,
    Done,
    Failed
};

struct Task
{
    int id;
    std::string type;
    std::string payload;
    TaskStatus status;
};
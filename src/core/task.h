#pragma once
#include <string>

enum class taskStatus
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
    taskStatus status;
};
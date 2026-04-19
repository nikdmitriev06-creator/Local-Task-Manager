#pragma once
#include "task.h"
#include <thread>
#include <chrono>
#include <iostream>

class TaskRunner
{
public:
    void RunTask_print(Task* CurrTask);
    bool RunTask_sleep(Task* CurrTask);
    void RunTask_fail(Task* CurrTask);
    void RunTask(Task* CurrTask);
};
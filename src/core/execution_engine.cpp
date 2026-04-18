#pragma once
#include "execution_engine.h"

void runTask(Task* currTask)
{
    currTask->status = taskStatus::Running;

    if(currTask->type == "print")
    {
        std::cout << currTask->payload;
        currTask->status = taskStatus::Done;
    } 
    else if(currTask->type == "sleep")
    {
        int timeSleep;
        try
        {
            timeSleep = std::stoi(currTask->payload);
        } 
        catch (std::invalid_argument)
        {
            currTask->status = taskStatus::Failed;
            std::cerr << "not an integer";
            return;
        }
        std::this_thread::sleep_for(std::chrono::seconds(timeSleep));
        currTask->status = taskStatus::Done;
    } else 
    {
        currTask->status = taskStatus::Failed;
    }
}
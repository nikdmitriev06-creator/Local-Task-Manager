#include "execution_engine.h"

void TaskRunner::RunTask_print(Task* CurrTask)
{
    std::cout << CurrTask->payload;
}

bool TaskRunner::RunTask_sleep(Task *CurrTask)
{
     int TimeSleep;
        try
        {
            TimeSleep = std::stoi(CurrTask->payload);
        } 
        catch (std::invalid_argument)
        {
            std::cerr << "not an integer";
            return false;
        }
        std::this_thread::sleep_for(std::chrono::seconds(TimeSleep));
        return true;
}

void TaskRunner::RunTask_fail(Task *CurrTask)
{
    CurrTask->status = TaskStatus::Failed;
}

void TaskRunner::RunTask(Task *CurrTask)
{
    std::cout << "[Task " << CurrTask->id << "] started\n";
    CurrTask->status = TaskStatus::Running;

    if(CurrTask->type == "print")
    {
        RunTask_print(CurrTask);
        CurrTask->status = TaskStatus::Done;
    } else if(CurrTask->type == "sleep")
    {
        if(RunTask_sleep(CurrTask))
        {
        CurrTask->status = TaskStatus::Done;
        } else CurrTask->status = TaskStatus::Failed;
    } else
    {
        RunTask_fail(CurrTask);
    }
    std::cout << "\n[Task " << CurrTask->id << "] done\n";
}

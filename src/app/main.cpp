#include "../core/task.h"
#include "../core/execution_engine.h"
#include "../core/task_manager.h"
#include <iostream>

int main() {

    TaskManager tasksManager;
    TaskRunner Runner;
    tasksManager.CreateTask("print", "Hello");

    while(tasksManager.GetQueueSize() != 0){
        Runner.RunTask(tasksManager.GetTask(tasksManager.GetIdFromQueue()));
        tasksManager.PopIdOfQueue();
    }

    return 0;
}
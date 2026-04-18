#include "../core/task.h"
#include "../core/execution_engine.h"
#include <iostream>

int main() {

    taskManager tasksManager;
    tasksManager.createTask("print", "Hello");

    while(tasksManager.getQueueSize() != 0){
        runTask(tasksManager.getTask(tasksManager.getIdFromQueue()));
        tasksManager.PopIdOfQueue();
    }

    return 0;
}
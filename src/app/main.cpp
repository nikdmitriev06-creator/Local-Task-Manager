#include "../core/task.h"
#include "../core/execution_engine.h"
#include "../core/task_manager.h"
#include <iostream>

int main() {

    TaskManager manager(4);

    manager.CreateTask("print", "Hello\n");
    manager.CreateTask("sleep", "1000");

    std::this_thread::sleep_for(std::chrono::seconds(2));
}
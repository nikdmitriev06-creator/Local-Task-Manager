#include "../core/task.h"
#include "../core/execution_engine.h"
#include "../core/task_manager.h"
#include "../core/menu.h"
#include <iostream>

int main() {

    TaskManager manager(4);
    menu menu(manager);

    manager.CreateTask("sleep", "100");
    manager.CreateTask("print", "Hello\n");
    manager.CreateTask("sleep", "10");

    menu.enterMenu();

    std::cin.get();
}
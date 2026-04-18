#include "../core/task.h"
#include <iostream>

int main() {
    Task t;
    t.id = 1;
    t.type = "print";
    t.payload = "Hello";
    t.status = taskStatus::Running;

    std::cout << "Task created with id: " << t.id << "\n";

    return 0;
}
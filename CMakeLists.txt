cmake_minimum_required(VERSION 3.16)
project(TaskManager)

set(CMAKE_CXX_STANDARD 20)

add_executable(task_manager
    src/app/main.cpp
    src/core/task.cpp
    src/core/task_manager.cpp
)
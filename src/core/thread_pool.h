#pragma once


#include "task.h"
#include <functional>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <memory>
#include <queue>

class ThreadPool
{
std::queue<std::function<void()>> FuncQueue;
std::vector<std::thread> TasksThread;

std::mutex TaskMutex;
std::condition_variable cv;
bool stop = false;

public:
ThreadPool(int num_threads);

void worker();
void EnqueueTask(std::function<void()> task);

~ThreadPool();
};
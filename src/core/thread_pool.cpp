#include "thread_pool.h"

ThreadPool::ThreadPool(int num_threads)
{
    TasksThread.reserve(num_threads);
    for(size_t i = 0; i < num_threads;++i)
    {
        TasksThread.emplace_back(&worker, this);
    }
}

void ThreadPool::worker()
{
    while(true)
    {
        std::unique_lock<std::mutex> lock(TaskMutex);

        cv.wait(lock, [this] {return stop || !FuncQueue.empty();} );

        if(stop && FuncQueue.empty()) return;

        std::function<void()> task = std::move(FuncQueue.front());
        FuncQueue.pop();
        lock.unlock();

        task();
    }
}

void ThreadPool::EnqueueTask(std::function<void()> task)
{
    {
    std::lock_guard<std::mutex> lock(TaskMutex);

    FuncQueue.push(std::move(task));
    }

    cv.notify_one();
}

ThreadPool::~ThreadPool()
{
    {
        std::lock_guard<std::mutex> lock(TaskMutex);
        stop = true;
    }

    cv.notify_all();

    for (auto& t : TasksThread)
    {
        t.join();
    }
}
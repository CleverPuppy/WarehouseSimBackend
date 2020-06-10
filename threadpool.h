#pragma once

#include <vector>
#include <queue>
#include <atomic>
#include <future>
#include <condition_variable>
#include <thread>
#include <functional>
#include <stdexcept>

class ThreadPool;

class ThreadPool
{
    using Task = std::function<void()>;

private:
    std::vector<std::thread> _pool;
    std::queue<Task> _tasks;
    std::mutex _lock;
    std::condition_variable _task_cv;
    std::atomic<bool> _run{true};   // if thread pool running
    std::atomic<int> _idlThrNum{0}; // idel thread num
public:
    ThreadPool(unsigned short size = 4);
    ~ThreadPool();

    template <typename Func, typename... Args>
    auto commit(Func &&f, Args &&... args);

    int idleCount();
    int threadCount();
private:
    void addThread(unsigned short size);
};

template <typename Func, typename... Args>
auto ThreadPool::commit(Func &&f, Args &&... args)
{
    if (!_run)
    {
        throw std::runtime_error("commit on ThreadPool is stopped.");
    }
    using ReturnType = decltype(f(args...));
    auto task = std::make_shared<std::packaged_task<ReturnType()>>(
        std::bind(std::forward<Func>(f), std::forward<Args>(args)...));
    std::future<ReturnType> future = task->get_future();
    
    {
        std::lock_guard<std::mutex> lock{ _lock };
        _tasks.emplace([task](){
            (*task)();
        });
    }

    _task_cv.notify_one(); // 唤醒一个线程执行
    
    return true;
}

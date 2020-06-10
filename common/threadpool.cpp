#include "threadpool.h"


int ThreadPool::idleCount() 
{
    return _idlThrNum;
}


int ThreadPool::threadCount() 
{
    return _pool.size();
}

void ThreadPool::addThread(unsigned short size) 
{
    for(unsigned short i = 0 ; i < size; ++i)
    {
        _pool.emplace_back([this](){
           while(_run)
           {
               Task task;
               {
                   std::unique_lock<std::mutex> lock{_lock};
                   _task_cv.wait(lock, [this](){
                       return !_run || !_tasks.empty();
                   }); // wait until there is a task
                   if(!_run && _tasks.empty())
                   {
                       return;
                   }
                   task = std::move(_tasks.front()); // fifo
                   _tasks.pop();
               }
               _idlThrNum--;
               task();
               _idlThrNum++;
           } 
        });
    }
}


ThreadPool::ThreadPool(unsigned short size) 
{
    addThread(size);
}


ThreadPool::~ThreadPool() 
{
    _run = false;
    _task_cv.notify_all();
    for(auto& thread : _pool)
    {
        if(thread.joinable()){
            thread.join(); // wait for task to be done
        }
    }
}
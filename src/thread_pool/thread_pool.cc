#include <functional>
#include <cstddef>
#include <optional>
#include "cppLibraries/thread_pool.h"


namespace cppLibraries
{
    
    Work::Work(std::function<void()> callable, int priority, int task_id) :
        m_callable(callable),
        m_priority(priority),
        m_task_id(task_id)
    {

    }

    Work::~Work() {

    }


    void Work::Execute() {
        m_callable();
    }

    void Queue::Push(Work work) {
        m_queue.PushBack(work);
    }

    std::optional<Work> Queue::Pop() {
        return m_queue.PopFront();
    }

    ThreadPool::ThreadPool(size_t worker_count) :
        m_worker_count(worker_count)
    {
        // create worker_count no of threads
    }

    
    ThreadPool::~ThreadPool() {

    }

    Work ThreadPool::CreateWork(std::function<void()> callable) {
            return Work(
            callable,
            -1, /* priority, will implement later */
            m_task_id++
        );
    }

    void ThreadPool::Add(std::function<void()> callable) {

        Work work = CreateWork(callable);
        m_queue.Push(work);
    }

    void ThreadPool::TestExec() {
        
        std::optional<Work> work = m_queue.Pop();

        if (work.has_value()) {
            work->Execute();
        }
    }


} // namespace cppLibraries

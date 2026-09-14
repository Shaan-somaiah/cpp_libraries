#include <functional>
#include <cstddef>
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

} // namespace cppLibraries

#include "thread_pool_impl.h"
#include "cppLibraries/thread_pool/thread_pool.h"
#include "queue.h"
#include "work.h"

#include <cstddef>
#include <functional>

namespace cppLibraries {

    ThreadPool::Impl::Impl(size_t worker_count) :
        m_worker_count(worker_count)
    {

    }

    void ThreadPool::Impl::Add(std::function<void()> m_callable) {
        
        Work work{m_callable,1,1};

        m_queue.Push(work);
    }

    void ThreadPool::Impl::TestExec() {

        auto work = m_queue.Pop();

        if (work) {
            Work poped_work = work.value();

            poped_work.Execute();
        }

    }

} // namespace cppLibraries

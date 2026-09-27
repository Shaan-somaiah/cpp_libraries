#include "cppLibraries/thread_pool/thread_pool.h"
#include "thread_pool_impl.h"

#include <cstddef>
#include <functional>

namespace cppLibraries {

    ThreadPool::ThreadPool(size_t worker_count) :
        m_impl{new Impl(worker_count)}
    {

    }

    ThreadPool::~ThreadPool() {
        delete m_impl;
    }

    void ThreadPool::Add(std::function<void()> callable) {

        // Wrap the callable in non template type and invoke implementation specific Add()
        m_impl->Add(callable);
    }

    void ThreadPool::TestExec() {
        m_impl->TestExec();
    }
    
} // namespace cppLibraries

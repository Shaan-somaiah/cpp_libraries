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

    void ThreadPool::AddImpl(std::function<void()> cb) {
        m_impl->Add(cb);
    }

    void ThreadPool::TestExec() {
        m_impl->TestExec();
    }
    
} // namespace cppLibraries

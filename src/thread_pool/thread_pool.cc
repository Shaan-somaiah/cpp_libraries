#include "cppLibraries/thread_pool/thread_pool.h"
#include "thread_pool_impl.h"

#include <cstddef>
#include <functional>

namespace cppLibraries {

    ThreadPool::ThreadPool(size_t worker_count) :
        m_impl{new Impl(worker_count)}
    {

    }
    
} // namespace cppLibraries

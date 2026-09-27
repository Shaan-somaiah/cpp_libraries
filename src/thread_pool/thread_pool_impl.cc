#include "thread_pool_impl.h"
#include "cppLibraries/thread_pool/thread_pool.h"

#include <cstddef>

namespace cppLibraries {

    ThreadPool::Impl::Impl(size_t worker_count) :
        m_worker_count(worker_count)
    {

    }

} // namespace cppLibraries

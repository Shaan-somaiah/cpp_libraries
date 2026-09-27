#ifndef CPP_LIBRARIES_THREAD_POOL_IMPL_H
#define CPP_LIBRARIES_THREAD_POOL_IMPL_H

#include "cppLibraries/thread_pool/thread_pool.h"

#include <cstddef>

namespace cppLibraries {

    class ThreadPool::Impl {

        private:
            size_t m_worker_count = 0;

        public:
            Impl(size_t worker_count); 
    };

} // namespace cppLibraries

#endif // CPP_LIBRARIES_THREAD_POOL_IMPL_H

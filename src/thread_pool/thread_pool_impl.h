#ifndef CPP_LIBRARIES_THREAD_POOL_IMPL_H
#define CPP_LIBRARIES_THREAD_POOL_IMPL_H

#include "cppLibraries/thread_pool/thread_pool.h"
#include "work.h"
#include "queue.h"

#include <cstddef>
#include <functional>

namespace cppLibraries {

    class ThreadPool::Impl {

        private:
            size_t m_worker_count = 0;

            Queue m_queue;


        public:
            Impl(size_t worker_count); 

            void Add(std::function<void()> m_callable);

            void TestExec();
    };

} // namespace cppLibraries

#endif // CPP_LIBRARIES_THREAD_POOL_IMPL_H

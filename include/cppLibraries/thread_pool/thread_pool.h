#ifndef CPP_LIBRARIES_THREAD_POOL_H
#define CPP_LIBRARIES_THREAD_POOL_H

#include <cstddef>
#include <functional>

namespace cppLibraries {

    class ThreadPool {

        // Pointer to implementation, do not want to expose any more details to consumer
        private:
            class Impl;
            Impl* m_impl;
    
        
        public:
            explicit ThreadPool(std::size_t worker_count);
            ~ThreadPool();

            // Public API to submit work to ThreadPool, takes in any callable
            // todo: Generalise the callable to support different return types and arguments
            void Add(std::function<void()> callable);

            void TestExec();

    }; 

} // namespace cppLibraries

#endif //CPP_LIBRARIES_THREAD_POOL_H

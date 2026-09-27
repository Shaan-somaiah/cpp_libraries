#ifndef CPP_LIBRARIES_THREAD_POOL_H
#define CPP_LIBRARIES_THREAD_POOL_H

#include <cstddef>
#include <functional>

namespace cppLibraries {

    class ThreadPool {
    
        public:
            explicit ThreadPool(std::size_t worker_count);
            ~ThreadPool();

            void Add(std::function<void()> callable);
            void TestExec();

        private:
            class Impl;
            Impl* m_impl;
    }; 

} // namespace cppLibraries

#endif //CPP_LIBRARIES_THREAD_POOL_H

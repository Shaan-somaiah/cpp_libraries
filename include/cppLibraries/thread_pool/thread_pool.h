#ifndef CPP_LIBRARIES_THREAD_POOL_H
#define CPP_LIBRARIES_THREAD_POOL_H

#include <cstddef>
#include <functional>
#include <utility>

namespace cppLibraries {

    class ThreadPool {

        private:

            // Forward declare internal implementation
            // Done to hide internally implementation from consumer
            class Impl;
            Impl* m_impl;

            // Private wrapper to call m_impl->Add(cb)
            // Since m_impl is only forward declared above, I cannot call m_impl->Add(cb) 
            // directly within templated Add()
            void AddImpl(std::function<void()> callable);
    
        
        public:
            explicit ThreadPool(std::size_t worker_count);
            ~ThreadPool();

            // Public API to submit work to ThreadPool, takes in any callable
            // Ignoring return types for now, I can generalise any callable to a std::function<void()> by 
            // wrapping it in a lamda
            // Todo: Will work on returning a future of the correct type
            template <typename Callable, typename... Args>
            auto Add(Callable&& callable, Args&&... args) { 

                std::function<void()> callable_ = [callable, args...]() {
                    callable(args...);
                };

                AddImpl(callable_);
            }

            // testing only
            void TestExec();
    }; 

} // namespace cppLibraries

#endif //CPP_LIBRARIES_THREAD_POOL_H

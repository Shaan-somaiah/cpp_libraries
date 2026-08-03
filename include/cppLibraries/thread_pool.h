#ifndef CPP_LIBRARIES_THREAD_POOL_H
#define CPP_LIBRARIES_THREAD_POOL_H

#include <functional>

namespace cppLibraries {

    class ThreadPool {

        private: 
            int m_worker_count;

            struct m_work {
                std::function<void()> m_callback;
                int m_priority;
                int task_id;
                
            };

            // Need to create a DS library to implement basic LL featureset
            // LinkedList<m_work> m_queue;

            void WorkerLoop();

        public:
            ThreadPool() = delete;
            ThreadPool(int workercount);

            ~ThreadPool();

            

    };

} // namespace cppLibraries

#endif //CPP_LIBRARIES_THREAD_POOL_H
#ifndef CPP_LIBRARIES_THREAD_POOL_H
#define CPP_LIBRARIES_THREAD_POOL_H

#include <functional>
#include <cstddef>
#include "cppLibraries/data_structures/double_linked_list.h"

namespace cppLibraries {

    // Unit of work that will be pushed onto the queue
    class Work {

        private:
            std::function<void()> m_callable;
            int m_priority;
            int m_task_id;
    };

    // Each thread waits on Queue, contains Work
    class Queue {

        private:
            dataStructure::DoubleLinkedList<Work> m_queue;
    };
    
    
    // Public API
    class ThreadPool {

        private: 
            std::size_t m_worker_count = 0;

            Queue queue;

        public:
            
            // Create worker_count no of threads and put them to sleep?
            explicit ThreadPool(int worker_count);

            ~ThreadPool();

            // Submit work to the queue, notify worker to check the queue for work?
            // construct Work Object from passed in callable
            void SubmitWork(/* work */);
            
    };

} // namespace cppLibraries

#endif //CPP_LIBRARIES_THREAD_POOL_H

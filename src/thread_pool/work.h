#ifndef CPP_LIBRARIES_THREAD_POOL_WORK_H
#define CPP_LIBRARIES_THREAD_POOL_WORK_H

#include <functional>

// Unit of work that will be pushed onto the queue
namespace cppLibraries {
    class Work {

        public:
            explicit Work(std::function<void()> callable, int priority, int task_id);
            ~Work();

            void Execute();

        private:
            std::function<void()> m_callable;
            int m_priority;
            int m_task_id;
    };
} // namespace cppLibraries

#endif // CPP_LIBRARIES_THREAD_POOL_WORK_H

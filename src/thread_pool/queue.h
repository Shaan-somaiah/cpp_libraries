#ifndef CPP_LIBRARIES_THREAD_POOL_QUEUE_H
#define CPP_LIBRARIES_THREAD_POOL_QUEUE_H

#include <optional>
#include <cppLibraries/data_structures/double_linked_list.h>
#include "work.h"

namespace cppLibraries {

    // Each thread waits on Queue, contains Work
    class Queue {

        public:
            // copy for now, will look into std::move later
            void Push(Work work);
            std::optional<Work> Pop();

        private:
            dataStructure::DoubleLinkedList<Work> m_queue;
    };

} // namespace cppLibraries

#endif // CPP_LIBRARIES_THREAD_POOL_QUEUE_H

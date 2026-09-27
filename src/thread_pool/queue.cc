#include "queue.h"

namespace cppLibraries {
    void Queue::Push(Work work) {
        m_queue.PushBack(work);
    }

    std::optional<Work> Queue::Pop() {
        return m_queue.PopFront();
    }

} // namespace cppLibraries

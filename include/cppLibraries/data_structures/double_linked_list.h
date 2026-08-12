#ifndef CPP_LIBRARIES_DS_DOUBLE_LINKED_LIST_H
#define CPP_LIBRARIES_DS_DOUBLE_LINKED_LIST_H

#include <cstddef>

namespace cppLibraries { namespace dataStructure {

    template <typename T> class DoubleLinkedList {

        private:
            size_t m_length = 0;

            struct Node {
                T m_data;
                Node* m_next = nullptr;
                Node* m_prev = nullptr;
            };

            Node* m_head = nullptr;
            Node* m_tail = nullptr;

        public:
            DoubleLinkedList();
            ~DoubleLinkedList();

            void PushFront(T data);
            void PushBack(T data);

            T PopFront();
            T PopBack();

            size_t GetLength();

            bool Exists(T data);
    };

} // namespace dataStructure
} // namespace cppLibraries

namespace ds = cppLibraries::dataStructure;

template <typename T> ds::DoubleLinkedList<T>::DoubleLinkedList() {

}

template <typename T> ds::DoubleLinkedList<T>::~DoubleLinkedList() {
    // free all mem
}

template <typename T> void ds::DoubleLinkedList<T>::PushFront(T data) {
    
}

template <typename T> void ds::DoubleLinkedList<T>::PushBack(T data) {
    
}

template <typename T> T ds::DoubleLinkedList<T>::PopFront() {
    
}

template <typename T> T ds::DoubleLinkedList<T>::PopBack() {
    
}

template <typename T> size_t ds::DoubleLinkedList<T>::GetLength() {
    
}
template <typename T> bool ds::DoubleLinkedList<T>::Exists(T data) {
    
}


#endif // CPP_LIBRARIES_DS_DOUBLE_LINKED_LIST_H

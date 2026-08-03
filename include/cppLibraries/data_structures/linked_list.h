#ifndef CPP_LIBRARIES_DS_LINKED_LIST_H
#define CPP_LIBRARIES_DS_LINKED_LIST_H

#include <cstddef>
// Remove in release
#include <iostream>


namespace cppLibraries { namespace dataStructure {

        template <typename T> class LinkedList {
            private:
                size_t m_length = 0;

                struct Node
                {
                    Node *m_next = nullptr;
                    T m_data;
                };

                Node *m_head = nullptr;
                Node *m_tail = nullptr;

            public:
                LinkedList();
                ~LinkedList();

                void PushFront(T data);
                void PushBack(T data);

                T PopFront();
                T PopBack();

                size_t GetLength() const;
            };

    } // namespace dataStructure
} // namespace cppLibraries

namespace ds = cppLibraries::dataStructure;


template <typename T> ds::LinkedList<T>::LinkedList() {

}

template <typename T> ds::LinkedList<T>::~LinkedList() {

    // free all the nodes
}

template <typename T> void ds::LinkedList<T>::PushFront(T data) {

    Node* node = new Node;
    node->m_data = data;

    // first node addition
    if(m_head == nullptr) {
        node->m_next = nullptr;
        m_head = node;
        m_tail = node;
    }
    else {
        node->m_next = m_head;
        m_head = node;
    }

    m_length++;
}

template <typename T> void ds::LinkedList<T>::PushBack(T data) {
    
    Node* node = new Node;
    node->m_data = data;

    // first node addition
    if(m_head == nullptr) {
        node->m_next = nullptr;
        m_head = node;
        m_tail = node;
    }
    else {
        node->m_next = nullptr;
        m_tail->m_next = node;
        m_tail = node;
    }

    m_length++;
}

template <typename T> T ds::LinkedList<T>::PopFront() {

}

template <typename T> T ds::LinkedList<T>::PopBack() {

}

template <typename T> size_t ds::LinkedList<T>::GetLength() const {
    return m_length;
}

#endif // CPP_LIBRARIES_DS_LINKED_LIST_H

#ifndef CPP_LIBRARIES_DS_LINKED_LIST_H
#define CPP_LIBRARIES_DS_LINKED_LIST_H

#include <cstddef>
#include <optional>

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

                std::optional<T> PopFront();
                std::optional<T> PopBack();

                size_t GetLength() const;

                bool Exists(T data) const;
            };

    } // namespace dataStructure
} // namespace cppLibraries

namespace ds = cppLibraries::dataStructure;


template <typename T> ds::LinkedList<T>::LinkedList() {

}

template <typename T> ds::LinkedList<T>::~LinkedList() {

    Node* tmpptr = m_head;

    while(tmpptr != nullptr) {
        m_head = m_head->m_next;
        delete (tmpptr);
        tmpptr = m_head;
    }

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

template <typename T> std::optional<T> ds::LinkedList<T>::PopFront() {
    
    // handle empty list
    if(m_head == nullptr) {
        return std::nullopt;
    }

    T data = m_head->m_data;
    Node* tmpptr = m_head;
    m_head = m_head->m_next;

    if(m_head == nullptr) {
        m_tail = nullptr;
    }

    delete(tmpptr);

    m_length--;

    return data;
}

template <typename T> std::optional<T> ds::LinkedList<T>::PopBack() {

    // handle empty list
    if(m_head == nullptr) {
        return std::nullopt;
    }

    // single node list
    if (m_head == m_tail) {
        T data = m_head->m_data;
        delete (m_head);
        m_head = nullptr;
        m_tail = nullptr;

        m_length--;

        return data;
    }

    Node* tmpptr = m_head;

    while (tmpptr->m_next != m_tail) {
        tmpptr = tmpptr->m_next;
    }

    T data = m_tail->m_data;
    m_tail = tmpptr;
    tmpptr = tmpptr->m_next;
    m_tail->m_next = nullptr;

    delete (tmpptr);

    m_length--;
    
    return data;

}

template <typename T> size_t ds::LinkedList<T>::GetLength() const {
    return m_length;
}

template <typename T> bool ds::LinkedList<T>::Exists(T data) const {
    
    // early return if linked list is empty
    if(m_head == nullptr){
        return false;
    }

    const Node* tmpptr = m_head;

    while (tmpptr != nullptr) {

        if(tmpptr->m_data == data) {
            return true;
        } 

        tmpptr = tmpptr->m_next;
    }

    return false;

}

#endif // CPP_LIBRARIES_DS_LINKED_LIST_H

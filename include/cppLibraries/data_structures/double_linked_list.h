#ifndef CPP_LIBRARIES_DS_DOUBLE_LINKED_LIST_H
#define CPP_LIBRARIES_DS_DOUBLE_LINKED_LIST_H

#include <cstddef>
#include <optional>

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

            std::optional<T> PopFront();
            std::optional<T> PopBack();

            size_t GetLength() const;

            bool Exists(T data);
    };

} // namespace dataStructure
} // namespace cppLibraries

namespace ds = cppLibraries::dataStructure;

template <typename T> ds::DoubleLinkedList<T>::DoubleLinkedList() {

}

template <typename T> ds::DoubleLinkedList<T>::~DoubleLinkedList() {
    
    Node* tmpptr = m_head;

    while(tmpptr != nullptr) {
        m_head = m_head->m_next;
        delete (tmpptr);
        tmpptr = m_head;
    }

}

template <typename T> void ds::DoubleLinkedList<T>::PushFront(T data) {
    
    Node* tmpptr = new Node;
    tmpptr->m_data = data;

    // first node
    if(m_head == nullptr) {
        m_head = tmpptr;
        m_tail = tmpptr;
        tmpptr->m_next = nullptr;
        tmpptr->m_prev = nullptr;
    }
    else {
        tmpptr->m_next = m_head;
        tmpptr->m_prev = nullptr;
        m_head->m_prev = tmpptr;
        m_head = tmpptr;
    }

    m_length++;
}

template <typename T> void ds::DoubleLinkedList<T>::PushBack(T data) {

    Node* tmpptr = new Node;

    // first node
    if(m_length == 0) {
        tmpptr->m_data = data;
        m_head = tmpptr;
        m_tail = tmpptr;
        tmpptr->m_next = nullptr;
        tmpptr->m_prev = nullptr;
    }

    m_tail->m_next = tmpptr;
    tmpptr->m_next = nullptr;
    tmpptr->m_prev = m_tail;
    m_tail = tmpptr;

    m_length++;

}

template <typename T> std::optional<T> ds::DoubleLinkedList<T>::PopFront() {

    // Handle empty list
    if(m_head == nullptr) {
        return std::nullopt;
    }
    
    T data  = m_head->m_data;
    Node* tmpptr = m_head;

    // Handle single node
    if(m_head == m_tail) {
        m_head = nullptr;
        m_tail = nullptr;
        delete(tmpptr);
        m_length--;
        return data;
    }

    m_head = m_head->m_next;
    m_head->m_prev = nullptr;

    delete(tmpptr);
    m_length--;

    return data;
}

template <typename T> std::optional<T> ds::DoubleLinkedList<T>::PopBack() {

    // Handle empty list
    if(m_head == nullptr) {
        return std::nullopt;
    }
    
    T data  = m_tail->m_data;
    Node* tmpptr = m_tail;

    // Handle single node
    if(m_head == m_tail) {
        m_head = nullptr;
        m_tail = nullptr;
        delete(tmpptr);
        m_length--;
        return data;
    }

    m_tail = m_tail->m_prev;
    m_tail->m_next = nullptr;

    delete(tmpptr);
    m_length--;

    return data;
}

template <typename T> size_t ds::DoubleLinkedList<T>::GetLength() const {
    return m_length;
}
template <typename T> bool ds::DoubleLinkedList<T>::Exists(T data) {

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


#endif // CPP_LIBRARIES_DS_DOUBLE_LINKED_LIST_H

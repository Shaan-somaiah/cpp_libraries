#ifndef CPP_LIBRARIES_DATA_STRUCTURE_H
#define CPP_LIBRARIES_DATA_STRUCTURE_H


namespace cppLibraries { namespace dataStructure {

    template <typename T> class LinkedList {

        private:
            size_t m_length = 0;

            struct node {
                node* m_next = nullptr;
                T m_data;
            }

            node* m_head = nullptr;
            node* m_tail = nullptr;

        public:
            
            LinkedList();
            // LinkedList(size_t length);

            ~LinkedList();

            void PushFront(T data);

            void PushBack(T data);

            T PopFront();

            T PopBack();

            size_t GetLength() const;

    };

    } // namespace dataStructure 
} // namespace cppLibraries

#endif //CPP_LIBRARIES_DATA_STRUCTURE_H
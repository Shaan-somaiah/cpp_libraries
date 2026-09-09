#include <iostream>
#include "cppLibraries/data_structures/linked_list.h"


namespace ds = cppLibraries::dataStructure;
int main() {
    ds::LinkedList<int> LinkedList;

    LinkedList.PushFront(100);


    LinkedList.PushFront(15);


    LinkedList.PushBack(55);


    for (size_t i=0; i < LinkedList.GetLength(); i++) {
        std::cout << LinkedList.PopFront() << "\n";
    }

    std::cout << "Length of LL now : " << LinkedList.GetLength() << "\n"; 

}

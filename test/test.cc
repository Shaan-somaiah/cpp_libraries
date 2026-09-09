#include <iostream>
#include "cppLibraries/data_structures/linked_list.h"


namespace ds = cppLibraries::dataStructure;
int main() {
    ds::LinkedList<int> LinkedList;

    LinkedList.PushFront(100);


    LinkedList.PushFront(15);


    LinkedList.PushBack(55);

    LinkedList.PopBack();

    LinkedList.PopFront();


    LinkedList.PopFront();
    LinkedList.PopFront();
    LinkedList.PopFront();

    std::cout << "Length of LL now : " << LinkedList.GetLength() << "\n"; 

}

#include <iostream>
#include "cppLibraries/data_structures/linked_list.h"


namespace ds = cppLibraries::dataStructure;
int main() {
    ds::LinkedList<int> LinkedList;

    LinkedList.PushFront(100);

    std::cout << LinkedList.GetLength() << "\n";

    LinkedList.PushFront(15);

    std::cout << LinkedList.GetLength() << "\n";

}

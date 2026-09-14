#include <iostream>
#include "cppLibraries/thread_pool.h"

void test() {
    std::cout << "INSIDE TEST!!!!\n";
    return;
}


int main() {

    cppLibraries::ThreadPool t_pool(5);

    t_pool.Add(&test);

    t_pool.TestExec();


}

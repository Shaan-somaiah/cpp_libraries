#include <iostream>
#include <functional>
#include <string>
#include <utility>
#include "cppLibraries/thread_pool/thread_pool.h"

class TestClass {
    public:
        int a=1;
        int b=1;

    public:

    TestClass()
    {
        std::cout << "Inside TestClass constructor\n";
    }
    
    TestClass(int a,int b) :
        a{a}, b{b}
    {
        std::cout << "Inside TestClass constructor\n";
    }

    TestClass(const TestClass& other) {

        std::cout << "Copied TestClass\n";
        this->a = other.a;
        this->b = other.b;
    }
};


int int_cb(int a, int b) { 
    std::cout << "Inside int_cb\n";
    return a+b;
}

int main () {

    std::function<void()> void_cb = []() {
        std::cout << "Inside void_cb\n";
    };

    std::function<TestClass(TestClass)> class_cb = [](const TestClass& tc) {

        std::cout << "Inside class_cb\n";
        TestClass new_test = tc;

        new_test.a = 10;
        new_test.b = 15;

        return new_test;
    };
    
    cppLibraries::ThreadPool tp{1}; 

    TestClass tc{5,6};

    tp.Add(std::move(void_cb));

    tp.Add(int_cb,5,10);

    tp.Add(class_cb,tc);


    tp.TestExec();
    tp.TestExec();
    tp.TestExec();
    tp.TestExec();
    tp.TestExec();
    tp.TestExec();

}
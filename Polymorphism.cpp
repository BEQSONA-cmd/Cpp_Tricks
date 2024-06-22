#include <iostream>

// Polymorphism

class A
{
    public:
        virtual void foo(void) { std::cout << "this is a" << std::endl; }
};

class B : public A
{
    public:
        void foo(void) { std::cout << "this is b" << std::endl; }
};

int main(void) 
{
    A *a = new B();

    // polymorphism (is a situation where a pointer to a base class is used to access a derived class object)
    a->foo();

    delete a;
    return 0;
}

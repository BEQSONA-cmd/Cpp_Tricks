#include <iostream>

// dynamic casting

class A
{
    protected:
        int num = 0;
    public:
        virtual ~A() = default;
};

class B : public A
{
    private:
        int num = 5;
    public:
        int foo(void) { return num; }
};

int main(void) 
{
    A *a = new B();

    // dynamicly casting A to B to access B's foo
    B *b = dynamic_cast<B *>(a);

    std::cout << b->foo() << std::endl;

    delete a;
    return 0;
}

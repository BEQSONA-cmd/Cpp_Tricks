#include <iostream>

// Pointer Aliasing

int foo(int *a, int *b) 
{
    *a = 5;
    *b = 6;
    return *a + *b;
}

int main(void) 
{
    int c;
    std::cout << foo(&c, &c) << std::endl;
    return 0;
}

#include <iostream>

// const casting

void cast_const(const int *a)
{
    // casting const int to int
    int *b = const_cast<int *>(a);
    
    // now b is modifiable
    *b = 5;
    std::cout << *b << std::endl;
    *b = 6;
    std::cout << *b << std::endl;
}

int main(void) 
{
    const int a = 49;

    cast_const(&a);

    return 0;
}

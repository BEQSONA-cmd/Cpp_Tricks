#include <iostream>

// numeric casting

float cast(void)
{
    int a = 5;
    
    float b = 4.2;

    // casting int to float
    int c = static_cast<float>(a);
    // now we can add c and b
    return c + b;

}

// void casting

int cast_void(void)
{
    int a = 5;

    // casting int to void
    void *b = static_cast<void *>(&a);
    // casting void to int back
    int *c = static_cast<int *>(b);

    return *c;
}

int main(void) 
{
    std::cout << cast() << std::endl;
    std::cout << cast_void() << std::endl;
    return 0;
}

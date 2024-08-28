#include <iostream>

// Type Casting

struct t_data
{
    int x;
    float y;
};

int main(void) 
{
    // casting int to char
    int i = 0;
    int a = 49;

    char *b = (char *)(&a);

    std::cout << b << std::endl;

    // casting struct to char
    t_data data;
    data.x = 49;
    data.y = 50.0;

    char *raw = (char *)(&data);

    while (i < sizeof(data))
    {
        std::cout << raw[i] << " ";
        i++;
    }
    std::cout << std::endl;

    return 0;
}

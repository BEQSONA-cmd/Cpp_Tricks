#include <iostream>

// global access to a static variable

// struct to hold the data
struct t_data
{
    int x;
    float y;
};

// initialize the static variable
t_data	*init_data(t_data *d)
{
	static t_data	*data;

	if (d == NULL)
		return (data);
    d->x = 42;
    d->y = 42.0;
	data = d;
	return (data);
}

// get the data
t_data	*data(void)
{
	return (init_data(NULL));
}

// change the value of the data
void change_value(void)
{
    data()->x = 5;
    data()->y = 5.0;
}

int main(void) 
{
    init_data(new t_data);
    std::cout << data()->x << " ";
    std::cout << data()->y << std::endl;

    change_value();
    std::cout << data()->x << " ";
    std::cout << data()->y << std::endl;

    delete data();
    return 0;
}

#include <iostream>

template <class T>
T max(T a, T b)
{
    return a > b ? a : b;
}

// this allows multiple types to be used in the template, type S is given a default type of int
template <class T, class S = int>
S min(T a, S b)
{
    return a < b ? a : b;
}

int main(int argc, char const *argv[])
{
    int x = 8;
    int y = 4;

    float f = 5.1;
    float g = 9.6;

    int max_x_y = max<int>(x, y);
    std::cout << "max_x_y  = " << max_x_y << std::endl;

    float max_f_g = max<float>(f, g);
    std::cout << "max_f_g  = " << max_f_g << std::endl;

    float min_x_f = min<int,float>(x, f);
    std::cout << "min_x_f  = " << min_x_f << std::endl;

    float min_g_y = min<float>(g, y);
    std::cout << "min_g_y  = " << min_g_y << std::endl;

    return 0;
}

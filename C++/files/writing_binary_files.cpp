#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    // C methods for binary file writing can also be used

    std::ofstream file;

    // mode flags can be combined with binary OR operator |
    file.open("./binary_file.bin", std::ios::out | std::ios::binary);

    if (file.is_open())
    {
        std::string string_to_write = "acxz";
        file.write(string_to_write.c_str(), string_to_write.size());

        char int_chars_to_write[] = {97, 65, 76, 101, 99, 67, 88, 113};
        file.write(int_chars_to_write, sizeof(int_chars_to_write));
    }

    file.close();

    return 0;
}
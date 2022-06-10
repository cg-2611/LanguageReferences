#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    // C methods for file writing can also be used

    std::ofstream file;

    // mode flags can be combined with binary OR operator |
    file.open("./written_file.txt", std::ios::out);

    if (file.is_open())
    {
        std::string text_to_write = "This is 123.4\n\n\tA\nTest string";
        file << text_to_write;
    }

    file.close();

    return 0;
}

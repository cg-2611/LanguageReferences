#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char const *argv[])
{
    // C methods for file reading can also be used

    std::ifstream file;

    // mode flags can be combined with binary OR operator |
    file.open("./file.txt", std::ios::in);

    if (file.is_open())
    {
        // file >> line_from_file can be used to read one line
        // file >> line 1 >> line 2 >> line 3 can be used to read lines too

        // this loops through each line of the file
        // while (getline(file, line)) {
        //     // do something with line
        // }

        std::stringstream string_stream; // create string stream

        string_stream << file.rdbuf(); // read file

        std::string text_from_file = string_stream.str(); // get string from stream

        std::cout << text_from_file << std::endl;
    }

    file.close();

    return 0;
}

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    // C methods for binary file reading can also be used

    std::ifstream file;

    file.open("./binary_file.bin", std::ios::in | std::ios::binary | std::ios::ate); // open at the end of the file for binary reading

    if (file.is_open())
    {
        std::streampos size = file.tellg(); // get the size of the file
        char *data_from_file = new char [size]; // allocate memory to store data in file

        file.seekg(0, std::ios::beg); // return to beginning of file
        file.read(data_from_file, size); // read the file into data_from_file

        std::cout << data_from_file << std::endl;

        delete[] data_from_file;
    }

    file.close();


    return 0;
}

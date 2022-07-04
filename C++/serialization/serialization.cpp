#include <fstream>
#include <iostream>
#include <string>

#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>

// structs can be serialized the same way as in C
// for very simple classes, the << and >> operators can be overriden to output the object to an iostream for a text file
// otherwise, to serialize to a binary file, the following method works

// recommended third-party libraries include:
// - boost: https://www.boost.org/doc/libs/1_79_0/libs/serialization/doc/index.html
// - cereal: http://uscilab.github.io/cereal/

// the following reference is a simple example of how to use cereal
// compile with: clang++ -o ./serialization ./serialization.cpp -Ilib/cereal/include/

class SerializationExample
{
private:
    int value;
    std::string string;

    friend cereal::access;
    template<class Archive>
    void serialize(Archive & archive)
    {
        archive(value, string);
    }
public:
    // default constructor
    SerializationExample()
    {
        this->value = 0;
        this->string = "";
    }

    SerializationExample(int value, std::string string)
    {
        this->value = value;
        this->string = string;
    }

    int getValue()
    {
        return value;
    }

    std::string getString()
    {
        return string;
    }
};

int main(int argc, char const *argv[])
{
    SerializationExample write_example1 = SerializationExample(47, "example1");
    SerializationExample write_example2 = SerializationExample(21, "example2");

    {
        std::ofstream output_file_stream = std::ofstream("serialized_objects.bin", std::ios::binary);
        cereal::BinaryOutputArchive output_archive = cereal::BinaryOutputArchive(output_file_stream);
        output_archive(write_example1); // serialize write_example1
        output_archive(write_example2); // serialize write_example2
    } // archive now out of scope, stream closed and archive destructed

    SerializationExample read_example1;
    SerializationExample read_example2;

    {
        std::ifstream input_file_stream = std::ifstream("serialized_objects.bin", std::ios::binary);
        cereal::BinaryInputArchive input_archive = cereal::BinaryInputArchive(input_file_stream);
        input_archive(read_example1); // deserialize read_example1
        input_archive(read_example2); // deserialize read_example2
    } // archive now out of scope, stream closed and archive destructed

    std::cout << "read_example1 value = " << read_example1.getValue() << std::endl;
    std::cout << "read_example1 string = " << read_example1.getString() << std::endl;

    std::cout << "read_example2 value = " << read_example2.getValue() << std::endl;
    std::cout << "read_example2 string = " << read_example2.getString() << std::endl;

    return 0;
}

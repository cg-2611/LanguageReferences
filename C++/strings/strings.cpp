#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    // strings support +, += and boolean operators as well as iterators
    std::string str = "This is a string.";

    std::cout << "String Value: " << str << std::endl;
    std::cout << "String Length: " << str.length() << std::endl;
    std::cout << "String Capacity: " << str.capacity() << std::endl;
    std::cout << "String character at 5th index: " << str[5] << std::endl; // can also use str.at(5)
    std::cout << "String last character: " << str.back() << std::endl;
    std::cout << "String first character: " << str.front() << std::endl;

    // when finding characters, find_first_of and find_last_of can also be used, however, these methods
    // search for the first character that matches any of the characters specified in the argument
    std::cout << "String index of \'a\': " << str.find('a') << std::endl;
    std::cout << "String index of \'z\': " << str.find('z') << std::endl; // undefined behaviour
    std::cout << "String index of \"string\": " << str.find("string") << std::endl;
    std::cout << "String first index of \'i\': " << str.find('i') << std::endl;
    std::cout << "String last index of \'i\': " << str.rfind('i') << std::endl;
    std::cout << "String from index 3: " << str.substr(3) << std::endl;
    std::cout << "String substring between from index 3 with length 12: " << str.substr(3, 12) << std::endl;

    str += " This is an appended string"; // can also use str.append(...)
    std::cout << "String Value: " << str << std::endl;

    // inserts a character at the end of the string
    str.push_back('.');
    std::cout << "String Value: " << str << std::endl;

    // this sets the value of str to the substring of str from index 8 with length 9
    str.assign(str, 8, 9); // can also use = operator
    std::cout << "String Value: " << str << std::endl;

    // set the front character of the string to new character
    str.front() = 'A';
    std::cout << "String Value: " << str << std::endl;

    // insert a string at index 1
    str.insert(1, "n");
    std::cout << "String Value: " << str << std::endl;

    // remove last character of string
    str.pop_back();
    std::cout << "String Value: " << str << std::endl;

    return 0;
}

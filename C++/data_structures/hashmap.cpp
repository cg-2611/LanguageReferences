#include <iostream>
#include <iterator>
#include <map>
#include <string>

// iterators can be used with std::map
// i.e. iterators can be used to traverse the map and also insert elements at specific positions

int main(int argc, char const *argv[])
{

    std::map<std::string, int> hashmap = std::map<std::string, int>();

    hashmap.insert(std::pair<std::string, int>("key1", 100)); // insert "key1" with value 100
    hashmap.insert(std::pair<std::string, int>("key2", 200));
    hashmap.insert(std::pair<std::string, int>("key3", 300));
    hashmap.insert(std::pair<std::string, int>("key4", 400)); // inset "key4" with value 400

    std::cout << "Hashmap empty: " << hashmap.empty() << std::endl;
    std::cout << "Hashmap size: " << hashmap.size() << std::endl;

    std::pair<std::map<std::string,int>::iterator,bool> insert_status;
    insert_status = hashmap.insert(std::pair<std::string, int>("key4", 500)); // insert again "key6" with value 700

    if (insert_status.second == false)
    {
        std::cout << "\nHashmap: key \"" << insert_status.first->first << "\" already in hashmap ";
        std::cout << "with value " << insert_status.first->second << '\n';
    }

    std::map<std::string, int>::iterator itr = hashmap.begin();
    hashmap.insert(itr, std::pair<std::string, int>("key5", 500));
    hashmap.insert(itr, std::pair<std::string, int>("key6", 600));
    hashmap.insert(itr, std::pair<std::string, int>("key7", 700));
    hashmap.insert(itr, std::pair<std::string, int>("key8", 800));
    hashmap.insert(itr, std::pair<std::string, int>("key9", 900));

    std::cout << "\nHashmap size: " << hashmap.size() << std::endl;

    std::cout << "\nHashmap value of  \"key2\" = " << hashmap.at("key2") << std::endl;
    std::cout << "Hashmap value of  \"key3\" = " << hashmap["key3"] << std::endl;

    std::cout << "\nHashmap:" << std::endl;
    for (auto itr = hashmap.begin(); itr != hashmap.end(); itr++)
    {
        std::cout << itr->first << " -> " << itr->second << std::endl;
    }

    std::cout << "\nHashmap removed \"key5\" and \"key1\"" << std::endl;
    itr = hashmap.find("key5");
    hashmap.erase(itr);
    hashmap.erase("key1");

    std::cout << "\nHashmap removed range from \"key7\" to end of hashmap" << std::endl;
    itr = hashmap.find("key7");
    hashmap.erase(itr, hashmap.end());

    std::cout << "\nHashmap:" << std::endl;
    for (auto itr = hashmap.begin(); itr != hashmap.end(); itr++)
    {
        std::cout << itr->first << " -> " << itr->second << std::endl;
    }

    return 0;
}

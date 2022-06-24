#include <iostream>
#include <string>

template <class T>
class SingleTypeGeneric
{
private:
    T value;
public:
    SingleTypeGeneric(T value)
    {
        this->value = value;
    }

    T getValue()
    {
        return value;
    }

};

// default types can be given to these types, e.g. class S = int will give type S a default type of int
// templates also support passing non-type parameters e.g. template <class T, int N> where n can be used in the
// body of the generic class or function
template <class T, class S>
class MultiTypeGeneric
{
private:
    T value1;
    S value2;
public:
    MultiTypeGeneric(T value1, S value2)
    {
        this->value1 = value1;
        this->value2 = value2;
    }

    T getValue1()
    {
        return value1;
    }

    S getValue2()
    {
        return value2;
    }

};

int main(int argc, char const *argv[])
{
    SingleTypeGeneric<int> intGeneric = SingleTypeGeneric<int>(2);
    std::cout << "intGeneric value = " << intGeneric.getValue() << std::endl;

    SingleTypeGeneric<std::string> stringGeneric = SingleTypeGeneric<std::string>("string");
    std::cout << "stringGeneric value = " << stringGeneric.getValue() << std::endl;

    MultiTypeGeneric<int, std::string> multiTypeGeneric = MultiTypeGeneric<int, std::string>(42, "Value 2");
    std::cout << "multiTypeGeneric value1 = " << multiTypeGeneric.getValue1() << std::endl;
    std::cout << "multiTypeGeneric value2 = " << multiTypeGeneric.getValue2() << std::endl;

    return 0;
}

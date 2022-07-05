#include <iostream>
#include <stack>

int main(int argc, char const *argv[])
{
    std::stack<int> stack = std::stack<int>();

    stack.push(122);
    stack.push(145);
    stack.push(109);
    stack.push(156);
    stack.push(134);

    std::cout << "Stack empty: " << stack.empty() << std::endl;
    std::cout << "Stack size: " << stack.size() << std::endl;

    std::cout << "\nStack popped: " << stack.top() << std::endl;
    stack.pop();

    std::cout << "Stack popped: " << stack.top() << std::endl;
    stack.pop();

    std::cout << "Stack size: " << stack.size() << std::endl;

    stack.push(156);
    std::cout << "\nStack pushed: " << stack.top() << std::endl;

    stack.push(117);
    std::cout << "Stack pushed: " << stack.top() << std::endl;

    std::cout << "\nStack:   top ->\t" << stack.top() << std::endl;
    stack.pop();

    while (!stack.empty())
    {
        std::cout << "\t\t" << stack.top() << std::endl;
        stack.pop();
    }

    return 0;
}

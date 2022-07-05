#include <iostream>
#include <queue>

int main(int argc, char const *argv[])
{
    std::queue<int> queue = std::queue<int>();

    queue.push(122);
    queue.push(145);
    queue.push(109);
    queue.push(156);
    queue.push(134);

    std::cout << "Queue empty: " << queue.empty() << std::endl;
    std::cout << "Queue size: " << queue.size() << std::endl;

    std::cout << "\nQueue dequeued: " << queue.front() << std::endl;
    queue.pop();

    std::cout << "Queue dequeued: " << queue.front() << std::endl;
    queue.pop();

    std::cout << "Queue size: " << queue.size() << std::endl;

    queue.push(156);
    std::cout << "\nQueue enqueued: " << queue.back() << std::endl;

    queue.push(117);
    std::cout << "Queue enqueued: " << queue.back() << std::endl;

    std::cout << "\nQueue: front ->\t" << queue.front();
    queue.pop();

    while (!queue.empty())
    {
        std::cout << "  |  " << queue.front();
        queue.pop();
    }

    std::cout << " <- back" << std::endl;

    return 0;
}

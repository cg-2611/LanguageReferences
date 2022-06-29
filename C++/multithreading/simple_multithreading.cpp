#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

// for multithreading, the C methods using pthread.h can still be used

void thread_function1(int thread_number)
{
    std::cout << "Printed by thread " << thread_number << std::endl;
}

void thread_function2(const std::string &thread_name)
{
    for(int i = 3; i > 0; i--)
    {
        std::cout << "Thread " << thread_name << ": " << i << std::endl;

        // get the current thread and sleep for 1s
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void thread_function3(int thread_number, const std::string &thread_string)
{
    thread_function1(thread_number);
    std::cout << thread_string << " " << thread_number << std::endl;
}

int main(int argc, char const *argv[])
{
    std::thread thread1 = std::thread(thread_function1, 1);
    std::thread thread2 = std::thread(thread_function1, 2);

    thread1.join();
    std::cout << "Joined thread 1" << std::endl;

    thread2.join();
    std::cout << "Joined thread 2" << std::endl;

    std::cout << std::endl;

    std::thread thread3 = std::thread(thread_function2, "thread 3");
    thread3.join();
    std::cout << "Joined thread 3" << std::endl;

    std::cout << std::endl;

    std::vector<std::thread> threads;

    for (int i = 0; i < 25; i++)
    {
        threads.push_back(std::thread(thread_function3, i + 1, "Executed thread"));
    }

    int i = 0;
    for (std::thread &thread : threads)
    {
        thread.join();
        std::cout << "Joined thread " << ++i << std::endl;
    }

    return 0;
}

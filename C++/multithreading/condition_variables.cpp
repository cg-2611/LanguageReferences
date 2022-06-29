#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

#define THREAD_COUNT 3

int count = 25;
std::mutex count_mutex;

// condition_variable::wait takes a unique_lock
// condition_variable_any::wait takes any lockable type
std::condition_variable_any count_condition;

void increment_counter(int thread_number, int increment_value)
{
    while (count < 50)
    {
        count_mutex.lock();
        count += increment_value;

        std::cout << "Increment Thread " << thread_number << " - Increased count by " << increment_value << std::endl;
        std::cout << "Count = " << count << std::endl;
        count_mutex.unlock();

        // Unblocks all threads currently waiting for this condition
        // notify_one unlocks only one currently waiting for this condition
        count_condition.notify_all();

        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // sleep for 500 milliseconds
    }
}

void decrement_counter()
{
    // std::unique_lock<std::mutex> lock(count_mutex);

    int decrement_value = 25;
    count_mutex.lock();

    while (count < 50)
    {
        std::cout << "Decrement Thread - Count not at 50, no decrement" << std::endl;

        // blocks on count_condition until there is a signal on the condition variable
        // alternatives include wait_for which will wait until timeout or until notified, or
        // wait_until which will wait until notified or a time point
        count_condition.wait(count_mutex);
    }

    while (count > 0)
    {
        count -= decrement_value;
        std::cout << "Decrement Thread - Decremented count by " << decrement_value << std::endl;
        std::cout << "Count = " << count << std::endl;
        count_mutex.unlock();
    }

}

int main(int argc, char const *argv[])
{
    std::vector<std::thread> threads;

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        if (i == THREAD_COUNT - 1)
        {
            threads.push_back(std::thread(decrement_counter));
        }
        else
        {
            threads.push_back(std::thread(increment_counter, i + 1, (THREAD_COUNT * i) + 1));
        }
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    std::cout << "All threads joined" << std::endl;

    return 0;
}

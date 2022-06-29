#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

int count = 0;
std::mutex mutex;

void increment_counter()
{
    for (int i = 0; i < 1500000; i++)
    {
        // lock allows only one thread to increment count at a time
        // if the mutex is locked, then lock will wait until it is unlocked
        mutex.lock();
        count++;
        mutex.unlock();
    }


    // alternatively to lock, try_lock can be used
    // the return value of the try_lock function can be checked for failure (false) when the lock
    // cannot be obtained and this can be handled try_lock will not wait until an unlock, it will
    // return either after trying to get the lock, or after getting the lock, executing, and then unlocking
    // for example:
    // if (mutex.try_lock()) {
    //     count++;
    //     mutex.unlock();
    // }
}

int main(int argc, char const *argv[])
{
    std::vector<std::thread> threads;

    for (int i = 0; i < 3; i++)
    {
        threads.push_back(std::thread(increment_counter));
        std::cout << "Started thread " << i + 1 << std::endl;
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    std::cout << "Count = " << count << std::endl;
    std::cout << "All threads joined" << std::endl;

    return 0;
}

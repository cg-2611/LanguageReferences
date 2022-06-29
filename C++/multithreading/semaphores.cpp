#include <iostream>
#include <semaphore>
#include <thread>
#include <vector>

// semaphores require c++20

int count = 0;

// equivalent to below: std::counting_semaphore<1> count_semaphore;
std::binary_semaphore count_semaphore {0}; // 0 is locked state 1 is released state

void increment_counter()
{
    for (int i = 0; i < 1500000; i++)
    {
        // acquire allows only one thread to increment count at a time
        // if the semaphore is locked, then acquire will wait until it is released
        count_semaphore.acquire();
        count++;
        count_semaphore.release();

        // alternatively to acquire, try_acquire can be used
        // the return value of the try_acquire function can be checked for failure (false) when the lock
        // cannot be obtained and this can be handled try_acquire will not wait until an unlock, it will
        // return either after trying to get the lock, or after acquiring, executing, and then releasing
        // for example:
        // if (counting_semaphore.try_acquire()) {
        //     count++;
        //     counting_semaphore.unlock();
        // }
    }

}

int main(int argc, char const *argv[])
{
    std::vector<std::thread> threads;

    count_semaphore.release(); // needed since initialized with value 0, not needed if initialized with value 1

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

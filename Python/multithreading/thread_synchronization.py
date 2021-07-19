import threading


count = 0


def thread_function(lock: threading.Lock()) -> None:
    global count
    for _ in range(1500000):
        # with statement equivalent to
        # lock.acquire()
        # try:
        #   do something
        # finally:
        #     lock.release()

        with lock:
            count += 1


if __name__ == "__main__":
    lock = threading.Lock() # can also use semaphore in a similar way

    threads = [threading.Thread(target=thread_function, args=(lock,)) for i in range(1, 4)]

    print("Main: starting threads")
    for thread in threads:
        thread.start()

    for thread in threads:
        thread.join()
    print("Main: all threads joined")

    print("Count:", count)
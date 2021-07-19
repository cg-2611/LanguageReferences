import threading


def thread_function(limit: int) -> None:
    current_thread = threading.current_thread()
    print(f"Thread name: {current_thread.name} started:", end=" ")

    for i in range(limit):
        print(f"{i} ", end="")

    print(f"\nThread {current_thread.name} exited")


if __name__ == "__main__":
    # for a single thread use thread = threading.Thread(...)
    threads = [threading.Thread(target=thread_function, args=(i + 2,)) for i in range(1, 10)]

    print("Main: starting threads")
    for thread in threads:
        thread.start()

    for thread in threads:
        thread.join()
    print("Main: all threads joined")

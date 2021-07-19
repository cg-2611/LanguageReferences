import multiprocessing
import os


def process_function(lock) -> None:
    # with statement equivalent to
    # lock.acquire()
    # try:
    #   do something
    # finally:
    #     lock.release()

    with lock:
        current_process = multiprocessing.current_process()
        print(f"Process name: {current_process.name}, pid: {current_process.pid}, ppid: {os.getppid()}")


if __name__ == "__main__":
    lock = multiprocessing.Lock()

    processes = [multiprocessing.Process(target=process_function, args=(lock,)) for i in  range(1, 8)]

    print(f"Main process pid: {os.getpid()}, ppid: {os.getppid()}")

    for process in processes:
        process.start()

    for process in processes:
        process.join()

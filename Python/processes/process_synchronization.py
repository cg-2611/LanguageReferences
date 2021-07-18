import multiprocessing
import os


def process_function(lock) -> None:
    # block until lock is free, then get the lock
    # using lock here prevents multiple processes printing at the same time
    lock.acquire()
    try:
        current_process = multiprocessing.current_process()
        print(f"Process name: {current_process.name}, pid: {current_process.pid}, ppid: {os.getppid()}")
    finally:
        # release the lock after print complete
        lock.release()


if __name__ == "__main__":
    lock = multiprocessing.Lock()

    processes = [multiprocessing.Process(target=process_function, args=(lock,)) for i in  range(1, 8)]

    print(f"Main process pid: {os.getpid()}, ppid: {os.getppid()}")

    for process in processes:
        process.start()

    for process in processes:
        process.join()

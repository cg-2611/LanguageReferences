# os module can be used to create and use process in a similar
# way to C, i.e. using fork(), wait(), getpid(), getppid(), singals and pipes etc.
import multiprocessing
import os


def process_function() -> None:
    current_process = multiprocessing.current_process()
    print(f"Process name: {current_process.name}, pid: {current_process.pid}, ppid: {os.getppid()}")


if __name__ == "__main__":
    processes: multiprocessing.Process = []

    print(f"Main process pid: {os.getpid()}, ppid: {os.getppid()}")

    for i in range(1, 8):
        new_process = multiprocessing.Process(name=f"process {i}", target=process_function)
        print(f"Starting process \"{new_process.name}\"")
        new_process.start()
        processes.append(new_process)

    for process in processes:
        print(f"Joining process \"{process.name}\"")
        process.join()

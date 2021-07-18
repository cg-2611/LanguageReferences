# os module can be used to create and use process in a similar
# way to C, i.e. using fork(), wait(), getpid(), getppid(), singals and pipes etc.
import multiprocessing
import os


def print_process_information() -> None:
    current_process = multiprocessing.current_process()
    print(f"Process name: {current_process.name}, pid: {current_process.pid}, ppid: {os.getppid()}")

def process_function() -> None:
    print_process_information()

    process1_child = multiprocessing.Process(name="process1_child", target=print_process_information)
    process1_child.start()


if __name__ == "__main__":
    process1 = multiprocessing.Process(name="process1", target=process_function)

    process1.start()

    print(f"{process1.name} is alive: {process1.is_alive()}")
    print(f"Main process pid: {os.getpid()}, ppid: {os.getppid()}")

    process1.join() # waits for child processes to complete before continuing, a timeout can be passed as well

    print(f"{process1.name} exited with exit code: {process1.exitcode}")
    print(f"{process1.name} is alive: {process1.is_alive()}")

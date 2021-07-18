import multiprocessing


def process_function(queue: multiprocessing.Queue) -> None:
    current_process = multiprocessing.current_process()

    if not queue.empty():
        queue_element = queue.get()
        print(f"process {current_process.name} read \"{queue_element}\" from queue")
    else:
        print(f"process {current_process.name} did not read from queue as it is empty")

    queue.put(f"string from {current_process.name}")


if __name__ == "__main__":
    queue = multiprocessing.Queue() # a maximum size can be specified for the queue as well

    # put 4 strings into the queue
    _ = [queue.put(f"string {i} from main") for i in  range(1, 5)]

    processes = [multiprocessing.Process(target=process_function, args=(queue,)) for i in  range(1, 8)]

    for process in processes:
        process.start()

    for process in processes:
        process.join()

    # output the remaining queue elements
    while not queue.empty():
        # get blocks the queue until it has read and removed the value returned
        print(f"main process read \"{queue.get()}\" from queue")

    queue.close()

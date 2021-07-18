import multiprocessing
import multiprocessing.connection


def process_function(pipe_connection: multiprocessing.connection.Connection) -> None:
    # receive message from parent process
    message = pipe_connection.recv()
    print("Message from parent process:", message)

    # send messages to parent process
    pipe_connection.send("string from child process")
    pipe_connection.send([1.33, True, "string", None, 5])

    pipe_connection.close()


if __name__ == "__main__":
    # Pipe() returns a tuple of pipes that can be used for two way communication (duplex)
    # pipes support communication between two processes
    parent_connection, child_connection = multiprocessing.Pipe()

    child_process = multiprocessing.Process(name="child_process", target=process_function, args=(child_connection,))

    child_process.start()

    # send tuple to child process
    parent_connection.send((2, False))

    # receive the first message from the child process
    message = parent_connection.recv()
    print("Message from child process:", message)

    # receive the second message from the child process
    message = parent_connection.recv()
    print("Message from child process:", message)

    child_process.join()

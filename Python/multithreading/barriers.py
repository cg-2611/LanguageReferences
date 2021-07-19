import threading


class ThreadSubclass(threading.Thread):
    def __init__(self, barrier: threading.Barrier) -> None:
        threading.Thread.__init__(self)
        self.barrier = barrier

    def run(self) -> None:
        print(f"{self.name}: waiting for barrier...")
        print(f"{self.name}: Barrier waiting for {barrier.parties} threads")
        print(f"{self.name}: Barrier waitied for {barrier.n_waiting} threads")
        self.barrier.wait()


if __name__ == "__main__":
    barrier = threading.Barrier(3) # creates a barrier that waits for 3 parties

    thread1 = ThreadSubclass(barrier)
    thread2 = ThreadSubclass(barrier)
    thread3 = ThreadSubclass(barrier)

    print("Main: all processes started")
    thread1.start()
    thread2.start()

    barrier.wait()

    thread1.join()
    thread2.join()

    print("Main: all processes joined")

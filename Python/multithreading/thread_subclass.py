import threading


class ThreadSubclass(threading.Thread):
    def run(self) -> None:
        print(f"printed from thread \"{self.name}\"")
        return


if __name__ == "__main__":
    threads: ThreadSubclass = []

    for i in range(1, 8):
        new_thread = ThreadSubclass(name=f"thread {i}")
        new_thread.start()
        threads.append(new_thread)

    for thread in threads:
        thread.join()


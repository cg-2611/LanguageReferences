import multiprocessing


class ProcessSubclass(multiprocessing.Process):
    def run(self) -> None:
        print(f"printed from process \"{self.name}\"")
        return


if __name__ == "__main__":
    processes: ProcessSubclass = []

    for i in range(1, 8):
        new_process = ProcessSubclass(name=f"process {i}")
        new_process.start()
        processes.append(new_process)

    for process in processes:
        process.join()

